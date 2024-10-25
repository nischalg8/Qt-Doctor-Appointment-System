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

void Cancellation::on_btnBook_clicked()
{
    QString sTokenNo = ui->txtTokenNo->text();
    int flag = 0;
    QSqlQuery query(MyDB::getInstance()->getDBInstance());

    // Check for and update the booking status in `cppbuzz_transaction`
    query.prepare("UPDATE cppbuzz_transaction SET Status='Cancelled' WHERE TokenNo = :tokenNo");
    query.bindValue(":tokenNo", sTokenNo);
    if (!query.exec()) {
        qDebug() << query.lastError().text() << query.lastQuery();
        ui->lblInfo->setText(query.lastError().text());
    } else {
        if (query.numRowsAffected() >= 1) {
            qDebug() << "Update was successful: " << query.lastQuery();
            flag++;
        } else {
            qDebug() << "Warning: Nothing was updated";
            ui->lblInfo->setText("Warning: Nothing was updated");
        }
    }

    if (flag == 1) {
        // Delete the record if the status update was successful
        query.clear();
        query.prepare("DELETE FROM cppbuzz_transaction WHERE TokenNo = :tokenNo");
        query.bindValue(":tokenNo", sTokenNo);
        if (!query.exec()) {
            qDebug() << query.lastError().text() << query.lastQuery();
            ui->lblInfo->setText("Error: Could not delete record.");
        } else {
            qDebug() << "Record deleted successfully: " << query.lastQuery();
            ui->lblInfo->setText("Booking Cancelled and Record Deleted");
        }
        ui->txtTokenNo->clear();
    }
}

void Cancellation::on_btnCancel_clicked()
{
    QString sTokenNo = ui->txtTokenNo->text();
    int flag = 0;
    QSqlQuery query(MyDB::getInstance()->getDBInstance());

    // Check for and update the booking status in `cppbuzz_transaction`
    query.prepare("UPDATE cppbuzz_transaction SET Status='Cancelled' WHERE TokenNo = :tokenNo");
    query.bindValue(":tokenNo", sTokenNo);
    if (!query.exec()) {
        qDebug() << query.lastError().text() << query.lastQuery();
        ui->lblInfo->setText(query.lastError().text());
    } else {
        if (query.numRowsAffected() >= 1) {
            qDebug() << "Update was successful: " << query.lastQuery();
            flag++;
        } else {
            qDebug() << "Warning: Nothing was updated";
            ui->lblInfo->setText("Warning: Nothing was updated");
        }
    }

    if (flag == 1) {
        // Delete the record if the status update was successful
        query.clear();
        query.prepare("DELETE FROM cppbuzz_transaction WHERE TokenNo = :tokenNo");
        query.bindValue(":tokenNo", sTokenNo);
        if (!query.exec()) {
            qDebug() << query.lastError().text() << query.lastQuery();
            ui->lblInfo->setText("Error: Could not delete record.");
        } else {
            qDebug() << "Record deleted successfully: " << query.lastQuery();
            ui->lblInfo->setText("Booking Cancelled and Record Deleted");
        }
        ui->txtTokenNo->clear();
    }
}
