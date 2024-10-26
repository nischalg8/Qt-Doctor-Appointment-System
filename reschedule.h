#ifndef RESCHEDULE_H
#define RESCHEDULE_H

#include <QDialog>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include "mydb.h"
#include "ui_reschedule.h"  // Include the UI header

namespace Ui {
class Reschedule;
}

class Reschedule : public QDialog
{
    Q_OBJECT

public:
    explicit Reschedule(QWidget *parent = nullptr);
    ~Reschedule();
protected:
    void showEvent(QShowEvent *event) override;  // Override showEvent
    void closeEvent(QCloseEvent *event) override; // Override closeEvent
private slots:
    void on_btnSearch_clicked();
    void on_btnSave_clicked();  // Declare the new slot
    void updateTimeLimits();
private:
    Ui::Reschedule *ui;
    QString doctorName;
};

#endif // RESCHEDULE_H
