#include "reschedule.h"
#include "ui_reschedule.h"
#include <QSqlError>
#include <QDebug>

Reschedule::Reschedule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reschedule)
{
    ui->setupUi(this);
    connect(ui->btnSearch, &QPushButton::clicked, this, &Reschedule::on_btnSearch_clicked);
    connect(ui->btnSave, &QPushButton::clicked, this, &Reschedule::on_btnSave_clicked);
    connect(ui->dateTimeEdit, &QDateTimeEdit::dateChanged, this, &Reschedule::updateTimeLimits);

    ui->dateTimeEdit->setEnabled(false);  // Disable date/time input by default

    QDateTime currentDateTime = QDateTime::currentDateTime();
    QDate currentDate = currentDateTime.date();
    QTime minTime(8, 0); // 8 am
    QTime maxTime(19, 0); // 7 pm

    ui->dateTimeEdit->setCalendarPopup(true);
    ui->dateTimeEdit->setDisplayFormat("yyyy-MM-dd HH:mm:ss");

    // Set minimum date (one day after current date) and time (8 am)
    QDateTime minDateTime = QDateTime(currentDate.addDays(1), minTime);
    ui->dateTimeEdit->setMinimumDateTime(minDateTime);

    // Set maximum date (one week from current date) and time (7 pm)
    QDateTime maxDateTime = QDateTime(currentDate.addDays(7), maxTime);
    ui->dateTimeEdit->setMaximumDateTime(maxDateTime);
}

Reschedule::~Reschedule()
{
    delete ui;
}

// Reset fields, labels, and date/time input when the dialog is opened
void Reschedule::showEvent(QShowEvent *event)
{
    QDialog::showEvent(event);

    ui->lineEdit->clear();           // Clear token number input
    ui->lineEdit_2->clear();         // Clear contact number input
    ui->textLabel->clear();           // Clear message label
    ui->textLabel_2->clear();         // Clear current appointment label
    ui->dateTimeEdit->clear();        // Clear date/time edit
    ui->dateTimeEdit->setEnabled(false); // Disable date/time input by default
}

// Reset fields, labels, and date/time input when the dialog is closed
void Reschedule::closeEvent(QCloseEvent *event)
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->textLabel->clear();
    ui->textLabel_2->clear();
    ui->dateTimeEdit->clear();
    ui->dateTimeEdit->setEnabled(false); // Disable date/time input

    QDialog::closeEvent(event);
}

void Reschedule::updateTimeLimits()
{
    QDate selectedDate = ui->dateTimeEdit->date();
    QTime minTime(8, 0);
    QTime maxTime(19, 0);
    QDateTime minDateTime = QDateTime(selectedDate, minTime);
    QDateTime maxDateTime = QDateTime(selectedDate, maxTime);
    ui->dateTimeEdit->setMinimumDateTime(minDateTime);
    ui->dateTimeEdit->setMaximumDateTime(maxDateTime);
}

void Reschedule::on_btnSearch_clicked() {
    QString sTokenNo = ui->lineEdit->text();  // Token number
    QString sContactNo = ui->lineEdit_2->text();  // Contact number

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
    } else {
        ui->textLabel_2->setText("Error: No matching record found.");
        ui->dateTimeEdit->setEnabled(false);  // Keep date/time input disabled if no record
    }
}

void Reschedule::on_btnSave_clicked() {
    QDateTime newDateTime = ui->dateTimeEdit->dateTime();  // Get the selected date-time
    QString sTokenNo = ui->lineEdit->text();  // Token number
    QString sContactNo = ui->lineEdit_2->text();  // Contact number

    // Ensure the selected time is within allowed hours (8 am - 7 pm)
    QTime selectedTime = newDateTime.time();
    if (selectedTime < QTime(8, 0) || selectedTime > QTime(19, 0)) {
        ui->textLabel->setText("Error: Please select a time between 8:00 AM and 7:00 PM.");
        return;
    }

    // Query to check if the selected date-time and doctor are already booked by another user
    QSqlQuery query(MyDB::getInstance()->getDBInstance());
    query.prepare("SELECT COUNT(*) FROM records_table WHERE AppointmentDateTime = :newDateTime AND DoctorName = :doctorName AND NOT (TokenNo = :tokenNo AND CustomerContact = :contactNo)");
    query.bindValue(":newDateTime", newDateTime);
    query.bindValue(":doctorName", doctorName);  // Use the doctor name retrieved from the database in on_btnSearch_clicked
    query.bindValue(":tokenNo", sTokenNo);
    query.bindValue(":contactNo", sContactNo);

    if (!query.exec()) {
        qDebug() << "Error checking for existing booking:" << query.lastError().text() << query.lastQuery();
        ui->textLabel->setText("Error: Could not check for existing booking.");
        return;
    }

    query.next();
    int count = query.value(0).toInt();
    if (count > 0) {
        // If another user has booked the same date-time with this doctor
        ui->textLabel->setText("Error: The selected date and time are already booked for this doctor.");
        return;
    }

    // Proceed to update the record if there are no conflicts
    query.clear();
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
