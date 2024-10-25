#ifndef BOOKING_H
#define BOOKING_H

#include <QDialog>
#include "mydb.h"
#include <QDateTime>  // Include this for QDateTime

namespace Ui {
class Booking;
}

class Booking : public QDialog
{
    Q_OBJECT

public:
    explicit Booking(QWidget *parent = nullptr);
    ~Booking();
    void populateData();  // This method can remain if you're still fetching available data
    // You can also add methods here if needed for date-time handling

private slots:
    void on_btnBook_clicked();  // Updated slot for booking with date-time

private:
    Ui::Booking *ui;
    // If you need any additional private members for date-time, declare them here
};

#endif // BOOKING_H
