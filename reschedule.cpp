#include "reschedule.h"
#include "ui_reschedule.h"

Reschedule::Reschedule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reschedule)
{
    ui->setupUi(this);
    connect(ui->btnSearch, &QPushButton::clicked, this, &Reschedule::on_btnSearch_clicked);
    connect(ui->btnSave, &QPushButton::clicked, this, &Reschedule::on_btnSave_clicked);
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

void Reschedule::on_btnSearch_clicked()
{
    QString sTokenNo = ui->lineEdit->text();  // Token number
    QString sContactNo = ui->lineEdit_2->text();  // Contact number

    QSqlQuery query(MyDB::getInstance()->getDBInstance());
    query.prepare("SELECT AppointmentDateTime FROM cppbuzz_transaction WHERE TokenNo = :tokenNo AND CustomerContact = :contactNo");
    query.bindValue(":tokenNo", sTokenNo);
    query.bindValue(":contactNo", sContactNo);

    if (!query.exec()) {
        qDebug() << query.lastError().text() << query.lastQuery();
        ui->textLabel_2->setText("Error: Could not fetch records");
    } else {
        if (query.next()) {
            QDateTime appointmentDate = query.value(0).toDateTime();
            ui->textLabel_2->setText("Current Appointment Date: " + appointmentDate.toString("yyyy-MM-dd HH:mm:ss"));
            ui->dateTimeEdit->setEnabled(true);  // Enable date/time input if record is found
        } else {
            ui->textLabel_2->setText("Error: No matching record found");
            ui->dateTimeEdit->setEnabled(false);  // Keep date/time input disabled if no record
        }
    }
}

void Reschedule::on_btnSave_clicked()
{
    QDateTime newDateTime = ui->dateTimeEdit->dateTime();  // Get the selected date-time
    QString sTokenNo = ui->lineEdit->text();  // Token number
    QString sContactNo = ui->lineEdit_2->text();  // Contact number

    QSqlQuery query(MyDB::getInstance()->getDBInstance());
    query.prepare("UPDATE cppbuzz_transaction SET AppointmentDateTime = :newDateTime WHERE TokenNo = :tokenNo AND CustomerContact = :contactNo");
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

