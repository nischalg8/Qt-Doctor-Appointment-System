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

private:
    void setupDateTimeEdit();          // Set up the DateTimeEdit
    void clearFields();                // Clear input fields
    void setupTimeRestrictions();       // Setup time restrictions for appointments
    void setupDateTimeLimits();         // Setup date and time limits

private slots:
    void on_btnSearch_clicked();        // Slot for search button
    void on_btnSave_clicked();          // Slot for save button
    void updateSaveButtonState();       // Update the state of the save button based on input

private:
    Ui::Reschedule *ui;                // Pointer to the UI class
    QString doctorName;                // Variable to store the doctor's name
};

#endif // RESCHEDULE_H
