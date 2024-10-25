#include "records.h"
#include "ui_records.h"

Records::Records(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Records)
{
    ui->setupUi(this);
    //populateData();
}

Records::~Records()
{
    delete ui;
}

void Records::populateData()
{
    qDebug() << "in init()";

    // Create a new query model
    QSqlQueryModel *model = new QSqlQueryModel(this);

    // Set the query directly to the model
    model->setQuery("SELECT * FROM cppbuzz_transaction ORDER BY Id DESC", MyDB::getInstance()->getDBInstance());

    // Check for any errors in executing the query
    if (model->lastError().isValid()) {
        qDebug() << model->lastError().text();
        ui->lblinfo->setText("Error fetching records");
    } else {
        qDebug() << "Query executed successfully";
    }

    // Assign the model to the table view
    ui->tableView->setModel(model);
    qDebug() << "rows are : " << model->rowCount();
    ui->tableView->show();
}
