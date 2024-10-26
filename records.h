#ifndef RECORDS_H
#define RECORDS_H

#include <QDialog>
#include <QDialog>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "mydb.h"

namespace Ui {
class Records;
}

class Records : public QDialog
{
    Q_OBJECT

public:
    explicit Records(QWidget *parent = nullptr);
    ~Records();
   // void populateData();
public slots:
      void populateData();
protected:
    void showEvent(QShowEvent *event) override;  // Override showEvent
    void closeEvent(QCloseEvent *event) override; // Override closeEvent
private:
    Ui::Records *ui;
    void getRecords();
    QSqlQueryModel *model;
};

#endif // RECORDS_H
