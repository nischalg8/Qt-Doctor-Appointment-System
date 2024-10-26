#include "cancellation.h"
#include "ui_cancellation.h"

Cancellation::Cancellation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cancellation)
{
    ui->setupUi(this);

}

Cancellation::~Cancellation()
{
    delete ui;
}

void Cancellation::on_btnCancel_clicked() {
    QString sTokenNo = ui->txtTokenNo->text();
    QString sContactNo = ui->txtContactNo->text();
    QSqlQuery query(MyDB::getInstance()->getDBInstance());

    // Delete the record if the token number and contact number match
    query.prepare("DELETE FROM cppbuzz_transaction WHERE TokenNo = :tokenNo AND CustomerContact = :contactNo");
    query.bindValue(":tokenNo", sTokenNo);
    query.bindValue(":contactNo", sContactNo);

    if (!query.exec()) {
        qDebug() << "Error deleting record:" << query.lastError().text() << query.lastQuery();
        ui->lblInfo->setText("Error: Could not delete record.");
    }
    else {
        if (query.numRowsAffected() >= 1) {
            qDebug() << "Record deleted successfully: " << query.lastQuery();
            ui->lblInfo->setText("Booking Cancelled and Record Deleted");
            ui->txtTokenNo->clear();
            ui->txtContactNo->clear();
        } else {
            qDebug() << "Warning: No matching record found";
            ui->lblInfo->setText("Warning: No matching record found");
        }
    }
}

