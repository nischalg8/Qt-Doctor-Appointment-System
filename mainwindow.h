#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "booking.h"
#include "cancellation.h"
#include "records.h"
#include "reschedule.h"  // Include the reschedule header

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnBooking_clicked();
    void on_btnCancellation_clicked();
    void on_btnRecords_clicked();
    void on_btnReschedule_clicked();  // Declare the new slot

private:
    Ui::MainWindow *ui;

    Booking *ptrBooking;
    Cancellation *ptrCancellation;
    Records *ptrRecords;
    Reschedule *ptrReschedule;  // Add a pointer to the Reschedule class
};

#endif // MAINWINDOW_H
