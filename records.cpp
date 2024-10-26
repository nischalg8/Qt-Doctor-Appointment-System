#include "records.h"
#include "ui_records.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Records::Records(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Records),
    model(new QSqlQueryModel(this))  // Initialize the model
{
    ui->setupUi(this);

    // Connect the search button to the populateData slot
    connect(ui->btnSearch, &QPushButton::clicked, this, &Records::populateData);
}

Records::~Records()
{
    delete ui;
}

// Reset fields, labels, and table when the dialog is opened
void Records::showEvent(QShowEvent *event)
{
    QDialog::showEvent(event);

    ui->lineEdit->clear();           // Clear token number input
    ui->lineEdit_2->clear();         // Clear contact number input
    ui->lblinfo->clear();            // Clear information label
    model->clear();                  // Clear the data model
    ui->tableView->setModel(nullptr); // Detach model from table view
}

// Reset fields, labels, and table when the dialog is closed
void Records::closeEvent(QCloseEvent *event)
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lblinfo->clear();
    model->clear();
    ui->tableView->setModel(nullptr);

    QDialog::closeEvent(event);
}

void Records::populateData()
{
    QString sContactNo = ui->lineEdit_2->text();  // Contact number
    QString sTokenNo = ui->lineEdit->text();      // Token number

    // Set the query directly to the model, using phone number and token number
    QSqlQuery query(MyDB::getInstance()->getDBInstance());
    query.prepare("SELECT * FROM records_table WHERE CustomerContact = :contactNo AND TokenNo = :tokenNo ORDER BY Id DESC");
    query.bindValue(":contactNo", sContactNo);
    query.bindValue(":tokenNo", sTokenNo);

    if (!query.exec()) {
        qDebug() << query.lastError().text() << query.lastQuery();
        ui->lblinfo->setText("Error fetching records.");
    } else {
        model->setQuery(std::move(query));  // Move query to model
        qDebug() << "Query executed successfully";

        // Check if any records are found
        if (model->rowCount() == 0) {
            ui->lblinfo->setText("No records found.");
            ui->tableView->setModel(nullptr);  // Clear the table view if no data
        } else {
            ui->lblinfo->clear();  // Clear the label if records are found
            ui->tableView->setModel(model);  // Assign the model to the table view

            // Adjust column widths to fit contents
            ui->tableView->resizeColumnsToContents();
        }
    }
}
