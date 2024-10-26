#include "records.h"
#include "ui_records.h"

Records::Records(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Records)
{
    ui->setupUi(this);
    // Connect the search button to the populateData slot
    connect(ui->btnSearch, &QPushButton::clicked, this, &Records::populateData);
}

Records::~Records()
{
    delete ui;
}

void Records::populateData()
{
    QString sContactNo = ui->lineEdit_2->text();  // Updated to lineEdit_2 for contact number
    QString sTokenNo = ui->lineEdit->text();      // Updated to lineEdit for token number

    qDebug() << "in init()";

    // Create a new query model
    QSqlQueryModel *model = new QSqlQueryModel(this);

    // Set the query directly to the model, using phone number and token number
    QSqlQuery query(MyDB::getInstance()->getDBInstance());
    query.prepare("SELECT * FROM cppbuzz_transaction WHERE CustomerContact = :contactNo AND TokenNo = :tokenNo ORDER BY Id DESC");
    query.bindValue(":contactNo", sContactNo);
    query.bindValue(":tokenNo", sTokenNo);

    if (!query.exec()) {
        qDebug() << query.lastError().text() << query.lastQuery();
        ui->lblinfo->setText("Error fetching records");
    } else {
        model->setQuery(query);
        qDebug() << "Query executed successfully";
        qDebug() << "rows are : " << model->rowCount();

        // Assign the model to the table view
        ui->tableView->setModel(model);
        ui->tableView->show();
    }
}
