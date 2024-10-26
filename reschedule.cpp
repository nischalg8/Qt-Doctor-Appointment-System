#include "reschedule.h"
#include "ui_reschedule.h"
#include <QSqlError>
#include <QDebug>
#include <QRegularExpression>

Reschedule::Reschedule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reschedule)
{
    ui->setupUi(this);
    setupDateTimeEdit();  // Setup date/time limits
    connect(ui->btnSearch, &QPushButton::clicked, this, &Reschedule::on_btnSearch_clicked);
    connect(ui->btnSave, &QPushButton::clicked, this, &Reschedule::on_btnSave_clicked);
    ui->btnSave->setEnabled(false);  // Disable Save button by default
}

// Destructor
Reschedule::~Reschedule()
{
    delete ui;
}

// Reset fields, labels, and date/time input when the dialog is opened
void Reschedule::showEvent(QShowEvent *event)
{
    QDialog::showEvent(event);
    clearFields();  // Clear input fields on show
}

// Reset fields when the dialog is closed
void Reschedule::closeEvent(QCloseEvent *event)
{
    clearFields();  // Reset fields on close
    QDialog::closeEvent(event);
}

// Setup minimum and maximum date-time in the QDateTimeEdit widget
void Reschedule::setupDateTimeEdit()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QDate currentDate = currentDateTime.date();
    QTime minTime(8, 0);  // 8 AM
    QTime maxTime(19, 0); // 7 PM

    // Set limits for the date/time picker
    ui->dateTimeEdit->setMinimumDateTime(QDateTime(currentDate.addDays(1), minTime));
    ui->dateTimeEdit->setMaximumDateTime(QDateTime(currentDate.addDays(7), maxTime));
    ui->dateTimeEdit->setCalendarPopup(true);
    ui->dateTimeEdit->setDisplayFormat("yyyy-MM-dd HH:mm");

    // Restrict time intervals to every 30 minutes within 8:00 AM - 7:00 PM
    setupTimeRestrictions();
}

void Reschedule::setupTimeRestrictions()
{
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
            ui->textLabel->setText("Please select a time in 30-minute intervals from 8:00 AM to 7:00 PM.");
        }
    });
}

// Clear input fields
void Reschedule::clearFields()
{
    ui->lineEdit->clear();           // Clear token number input
    ui->lineEdit_2->clear();         // Clear contact number input
    ui->textLabel->clear();           // Clear message label
    ui->textLabel_2->clear();         // Clear current appointment label
    ui->dateTimeEdit->clear();        // Clear date/time edit
    ui->dateTimeEdit->setEnabled(false); // Disable date/time input by default
    ui->btnSave->setEnabled(false);  // Disable Save button by default
}

void Reschedule::on_btnSearch_clicked() {
    QString sTokenNo = ui->lineEdit->text();  // Token number
    QString sContactNo = ui->lineEdit_2->text();  // Contact number

    // Fetch existing appointment
    QSqlQuery query(MyDB::getInstance()->getDBInstance());
    query.prepare("SELECT AppointmentDateTime, DoctorName FROM records_table WHERE TokenNo = :tokenNo AND CustomerContact = :contactNo");
    query.bindValue(":tokenNo", sTokenNo);
    query.bindValue(":contactNo", sContactNo);

    if (!query.exec()) {
        qDebug() << query.lastError().text() << query.lastQuery();
        ui->textLabel_2->setText("Error: Could not fetch records.");
        return;
    }

    if (query.next()) {
        QDateTime appointmentDate = query.value(0).toDateTime();
        doctorName = query.value(1).toString();  // Retrieve the doctor’s name for use in validation
        ui->textLabel_2->setText("Current Appointment Date: " + appointmentDate.toString("yyyy-MM-dd HH:mm:ss"));
        ui->dateTimeEdit->setEnabled(true);  // Enable date/time input if record is found
        updateSaveButtonState();
    } else {
        ui->textLabel_2->setText("Error: No matching record found.");
        ui->dateTimeEdit->setEnabled(false);
        ui->btnSave->setEnabled(false);
    }
}

void Reschedule::updateSaveButtonState()
{
    ui->btnSave->setEnabled(ui->dateTimeEdit->isEnabled() && !ui->dateTimeEdit->dateTime().isNull());
}

void Reschedule::on_btnSave_clicked() {
    ui->textLabel_2->setText("");  // Clear previous info
      ui->textLabel->setText("");
    // Collect user input
    QString sTokenNo = ui->lineEdit->text();  // Token number
    QString sContactNo = ui->lineEdit_2->text();  // Contact number
    QDateTime newDateTime = ui->dateTimeEdit->dateTime();  // Get the selected date-time

    // Basic input validation
    if (sTokenNo.isEmpty() || sContactNo.isEmpty()) {
        ui->textLabel_2->setText("Error: Token Number and Contact Number cannot be empty.");
        return;
    }

    QRegularExpression re("^[0-9]+$");
    if (!re.match(sContactNo).hasMatch()) {
        ui->textLabel_2->setText("Error: Contact Number must contain only digits.");
        return;
    }

    // Check for existing appointments within 30 minutes
    QSqlQuery query(MyDB::getInstance()->getDBInstance());
    query.prepare("SELECT COUNT(*) FROM records_table WHERE DoctorName = :doctorName "
                  "AND ABS(strftime('%s', AppointmentDateTime) - strftime('%s', :dateTime)) <= 1800");
    query.bindValue(":doctorName", doctorName);
    query.bindValue(":dateTime", newDateTime);

    if (!query.exec()) {
        qDebug() << "Error checking for existing booking:" << query.lastError().text();
        ui->textLabel->setText("Error: Could not check for existing booking.");
        return;
    }

    query.next();
    int count = query.value(0).toInt();
    if (count > 0) {
        ui->textLabel->setText("Error: Selected date and time are already booked within 30 minutes.");
        return;
    }

    // Proceed to update the record if there are no conflicts
    query.prepare("UPDATE records_table SET AppointmentDateTime = :newDateTime WHERE TokenNo = :tokenNo AND CustomerContact = :contactNo");
    query.bindValue(":newDateTime", newDateTime);
    query.bindValue(":tokenNo", sTokenNo);
    query.bindValue(":contactNo", sContactNo);

    if (!query.exec()) {
        qDebug() << "Error updating record:" << query.lastError().text() << query.lastQuery();
        ui->textLabel->setText("Error: Could not update record.");
    } else {
        qDebug() << "Record updated successfully: " << query.lastQuery();
        ui->textLabel->setText("Appointment rescheduled to: " + newDateTime.toString("yyyy-MM-dd HH:mm:ss"));
    }
}
