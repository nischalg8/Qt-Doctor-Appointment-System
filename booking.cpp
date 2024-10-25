#include "booking.h"
#include "ui_booking.h"
#include <QRandomGenerator>
#include <QSqlError>

Booking::Booking(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Booking) {
    ui->setupUi(this);
    // Set minimum and maximum date-time in the QDateTimeEdit widget
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

Booking::~Booking() {
    delete ui;
}

void Booking::on_btnBook_clicked() {
    // Clear previous info message
    ui->lblinfo->setText("");

    // Ensure the database is open
    if (!MyDB::getInstance()->getDBInstance().isOpen()) {
        ui->lblinfo->setText("Error: Database is not open.");
        return;
    }

    // Get input values
    QString sName = ui->txtName->text();
    QString sContactNo = ui->txtContactNo->text();
    QDateTime sDateTime = ui->dateTimeEdit->dateTime(); // Get the selected date-time
    QDateTime currentDateTime = QDateTime::currentDateTime();

    // Generate a random token number between 111111 and 999999
    int sTokenNo = QRandomGenerator::global()->bounded(111111, 999999 + 1);

    QSqlQuery query(MyDB::getInstance()->getDBInstance());

    // Check if the selected date-time is already booked
    query.prepare("SELECT COUNT(*) FROM cppbuzz_transaction WHERE AppointmentDateTime = :dateTime");
    query.bindValue(":dateTime", sDateTime.toString("yyyy-MM-dd HH:mm:ss"));
    if (!query.exec()) {
        qDebug() << "Error checking for existing booking:" << query.lastError().text() << query.lastQuery();
        ui->lblinfo->setText("Error: Could not check for existing booking.");
        return; // Early return on error
    }

    query.next();
    int count = query.value(0).toInt();
    if (count > 0) {
        // If there is already a booking for the selected date-time
        ui->lblinfo->setText("Error: The selected date and time is already booked.");
        return; // Slot is already booked, return early
    }

    // Insert transaction record into `cppbuzz_transaction`
    query.clear(); // Clear previous query
    query.prepare("INSERT INTO cppbuzz_transaction (CustomerName, CustomerContact, TokenNo, Status, AppointmentDateTime, BookedTimeStamp) "
                  "VALUES (:customerName, :customerContact, :tokenNo, 'Booked', :dateTime, :bookingTimestamp)");
    query.bindValue(":customerName", sName);
    query.bindValue(":customerContact", sContactNo);
    query.bindValue(":tokenNo", sTokenNo);
    query.bindValue(":dateTime", sDateTime.toString("yyyy-MM-dd HH:mm:ss"));
    query.bindValue(":bookingTimestamp", currentDateTime.toString("yyyy-MM-dd HH:mm:ss"));

    if (!query.exec()) {
        qDebug() << "Error inserting transaction record:" << query.lastError().text() << query.lastQuery();
        ui->lblinfo->setText("Error: Could not insert transaction record.");
        return; // Early return on error
    }

    // If the query was successful
    ui->txtName->clear();
    ui->txtContactNo->clear();
    ui->lblinfo->setText("Booking confirmed! Token No: " + QString::number(sTokenNo));
}
