#include "booking.h"
#include "ui_booking.h"
#include <QRandomGenerator>
#include <QSqlError>

Booking::Booking(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Booking)
{
    ui->setupUi(this);
}

void Booking::populateData()
{
    QSqlQuery query(MyDB::getInstance()->getDBInstance());
    query.prepare("SELECT Slot FROM cppbuzz_booking WHERE Status = 'Y'");

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text() << query.lastQuery();
    } else {
        qDebug() << "Read was successful:" << query.lastQuery();
        ui->cmbSlot->clear();
        while (query.next()) {
            ui->cmbSlot->addItem(query.value(0).toString());
        }
    }
}

Booking::~Booking()
{
    delete ui;
}
void Booking::on_btnBook_clicked()
{
    // Clear previous info message
    ui->lblInfo->setText("");

    // Ensure the database is open
    if (!MyDB::getInstance()->getDBInstance().isOpen()) {
        ui->lblInfo->setText("Error: Database is not open.");
        return;
    }

    // Get input values
    QString sName = ui->txtName->text();
    QString sContactNo = ui->txtContactNo->text();
    QString sSlot = ui->cmbSlot->currentText();

    // Generate a random token number between 111111 and 999999
    int sTokenNo = QRandomGenerator::global()->bounded(111111, 999999 + 1);
    QString sDate = QDate::currentDate().toString();

    QSqlQuery query(MyDB::getInstance()->getDBInstance());

    // Update booking status
    query.prepare("UPDATE cppbuzz_booking SET Status = 'N', TokenNo = :tokenNo WHERE Slot = :slot");
    query.bindValue(":tokenNo", sTokenNo);
    query.bindValue(":slot", sSlot);

    if (!query.exec()) {
        qDebug() << "Error updating booking status:" << query.lastError().text() << query.lastQuery();
        ui->lblInfo->setText("Error: Could not update booking status.");
        return; // Early return on error
    }

    // Insert transaction record
    query.clear(); // Clear previous query
    query.prepare("INSERT INTO cppbuzz_transaction (Slot, CustomerName, CustomerContact, TokenNo, Status, DateTime) "
                  "VALUES (:slot, :customerName, :customerContact, :tokenNo, 'Booked', :dateTime)");
    query.bindValue(":slot", sSlot);
    query.bindValue(":customerName", sName);
    query.bindValue(":customerContact", sContactNo);
    query.bindValue(":tokenNo", sTokenNo);
    query.bindValue(":dateTime", sDate);

    if (!query.exec()) {
        qDebug() << "Error inserting transaction record:" << query.lastError().text() << query.lastQuery();
        ui->lblInfo->setText("Error: Could not insert transaction record.");
        return; // Early return on error
    }

    // If both queries were successful
    ui->txtName->clear();
    ui->txtContactNo->clear();
    populateData(); // Refresh available slots
    ui->lblInfo->setText("Slot has been booked! Token No: " + QString::number(sTokenNo));
}
