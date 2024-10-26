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
}
Reschedule::~Reschedule()
{
    delete  ui;
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
        ui->textLabel->setText("Error: Could not fetch records");
    } else {
        if (query.next()) {
            QString appointmentDate = query.value(0).toString();
            ui->textLabel->setText("Current Appointment Date: " + appointmentDate);
            ui->dateTimeEdit->setEnabled(true); // Enable date/time input if record is found
        } else {
            ui->textLabel->setText("Error: No matching record found");
            ui->dateTimeEdit->setEnabled(false); // Keep date/time input disabled if no record
        }
    }
}
