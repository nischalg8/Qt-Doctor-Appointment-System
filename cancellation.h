#ifndef CANCELLATION_H
#define CANCELLATION_H

#include <QDialog>
#include "mydb.h"

namespace Ui {
class Cancellation;
}

class Cancellation : public QDialog
{
    Q_OBJECT

public:
    explicit Cancellation(QWidget *parent = nullptr);
    ~Cancellation();

protected:
    void showEvent(QShowEvent *event) override;  // Override showEvent
    void closeEvent(QCloseEvent *event) override; // Override closeEvent
private slots:


    void on_btnCancel_clicked();

private:
    Ui::Cancellation *ui;
};

#endif // CANCELLATION_H
