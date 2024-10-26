#include "booking.h"
#include "ui_booking.h"
#include <QRandomGenerator>
#include <QSqlError>
#include <QRegularExpression>

// Constructor for Booking dialog
Booking::Booking(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Booking)
{
    ui->setupUi(this);

    // Set the DateTime Edit with specific limits
    setupDateTimeEdit();

    // Load doctors from database into the combo box
    QSqlQuery query(MyDB::getInstance()->getDBInstance());
    query.prepare("SELECT DoctorName, Specialty FROM doctorlist");

    if (query.exec()) {
        while (query.next()) {
            QString doctorName = query.value(0).toString();
            QString specialty = query.value(1).toString();
            ui->doctorComboBox->addItem(doctorName + " (" + specialty + ")", QVariant::fromValue(specialty));
        }
    } else {
        qDebug() << "Error loading doctors:" << query.lastError().text();
    }
}

// Destructor
Booking::~Booking()
{
    delete ui;
}
void Booking::showEvent(QShowEvent *event)
{
    QDialog::showEvent(event);

    ui->txtName->clear();           // Clear name input
    ui->txtContactNo->clear();      // Clear contact number input
    ui->lblinfo->clear();           // Clear information label
    ui->dateTimeEdit->clear();      // Clear date-time selection
    ui->doctorComboBox->setCurrentIndex(0);  // Reset doctor selection
}

// Reset fields when the dialog is closed
void Booking::closeEvent(QCloseEvent *event)
{
    ui->txtName->clear();
    ui->txtContactNo->clear();
    ui->lblinfo->clear();
    ui->dateTimeEdit->clear();
    ui->doctorComboBox->setCurrentIndex(0);

    QDialog::closeEvent(event);
}
// Sets the minimum and maximum date-time in the QDateTimeEdit widget
void Booking::setupDateTimeEdit()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QDate currentDate = currentDateTime.date();
    QTime minTime(8, 0); // 8 am
    QTime maxTime(19, 0); // 7 pm

    // Set minimum date (one day after current date) and time (8 am)
    QDateTime minDateTime = QDateTime(currentDate.addDays(1), minTime);
    ui->dateTimeEdit->setMinimumDateTime(minDateTime);

    // Set maximum date (one week from current date) and time (7 pm)
    QDateTime maxDateTime = QDateTime(currentDate.addDays(7), maxTime);
    ui->dateTimeEdit->setMaximumDateTime(maxDateTime);

    // Display format and calendar popup
    ui->dateTimeEdit->setCalendarPopup(true);
    ui->dateTimeEdit->setDisplayFormat("yyyy-MM-dd HH:mm");

    // Restrict time intervals to every 30 minutes within 8:00 AM - 7:00 PM
    QList<QTime> allowedTimes;
    for (int hour = 8; hour <= 18; ++hour) {
        allowedTimes.append(QTime(hour, 0));
        allowedTimes.append(QTime(hour, 30));
    }
    allowedTimes.append(QTime(19, 0)); // 7:00 PM

    connect(ui->dateTimeEdit, &QDateTimeEdit::editingFinished, this, [=]() {
        QTime selectedTime = ui->dateTimeEdit->time();
        if (!allowedTimes.contains(selectedTime)) {
            ui->dateTimeEdit->setTime(allowedTimes.first());
            ui->lblinfo->setText("Please select a time in 30-minute intervals from 8:00 AM to 7:00 PM.");
        }
    });
}



// Called when booking button is clicked
void Booking::on_btnBook_clicked()
{
    ui->lblinfo->setText("");

    // Collect user input
    QString sName = ui->txtName->text();
    QString sContactNo = ui->txtContactNo->text();
    QDateTime sDateTime = ui->dateTimeEdit->dateTime();
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString doctorName = ui->doctorComboBox->currentText();
    QString specialty = ui->doctorComboBox->itemData(ui->doctorComboBox->currentIndex()).toString();

    // Basic input validation
    if (sName.isEmpty() || sContactNo.isEmpty()) {
        ui->lblinfo->setText("Error: Name and Contact Number cannot be empty.");
        return;
    }
    QRegularExpression re("^[0-9]+$");
    if (!re.match(sContactNo).hasMatch()) {
        ui->lblinfo->setText("Error: Contact Number must contain only digits.");
        return;
    }

    // Ensure the selected time is within allowed hours
    QTime selectedTime = sDateTime.time();
    if (selectedTime < QTime(8, 0) || selectedTime > QTime(19, 0)) {
        ui->lblinfo->setText("Error: Please select a time between 8:00 AM and 7:00 PM.");
        return;
    }

    // Check for existing appointments within 30 minutes
    QSqlQuery query(MyDB::getInstance()->getDBInstance());
    query.prepare("SELECT COUNT(*) FROM records_table WHERE DoctorName = :doctorName "
                  "AND ABS(strftime('%s', AppointmentDateTime) - strftime('%s', :dateTime)) <= 1800");
    query.bindValue(":doctorName", doctorName);
    query.bindValue(":dateTime", sDateTime);

    if (!query.exec()) {
        qDebug() << "Error checking for existing booking:" << query.lastError().text();
        ui->lblinfo->setText("Error: Could not check for existing booking.");
        return;
    }

    query.next();
    int count = query.value(0).toInt();
    if (count > 0) {
        ui->lblinfo->setText("Error: Selected date and time are already booked within 30 minutes.");
        return;
    }

    // Generate a token number
    int sTokenNo = QRandomGenerator::global()->bounded(111111, 999999 + 1);

    // Insert booking into database
    query.prepare("INSERT INTO records_table (CustomerName, CustomerContact, TokenNo, Status, AppointmentDateTime, BookedTimeStamp, DoctorName, Specialty) "
                  "VALUES (:customerName, :customerContact, :tokenNo, 'Booked', :dateTime, :bookingTimestamp, :doctorName, :specialty)");
    query.bindValue(":customerName", sName);
    query.bindValue(":customerContact", sContactNo);
    query.bindValue(":tokenNo", sTokenNo);
    query.bindValue(":dateTime", sDateTime);
    query.bindValue(":bookingTimestamp", currentDateTime);
    query.bindValue(":doctorName", doctorName);
    query.bindValue(":specialty", specialty);

    if (!query.exec()) {
        qDebug() << "Error inserting booking:" << query.lastError().text();
        ui->lblinfo->setText("Error: Could not insert booking record.");
        return;
    }

    // Booking successful
    ui->txtName->clear();
    ui->txtContactNo->clear();
    ui->lblinfo->setText("Booking confirmed! Token No: " + QString::number(sTokenNo));
}
