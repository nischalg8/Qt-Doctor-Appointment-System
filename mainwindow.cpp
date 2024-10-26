#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ptrBooking = new Booking(this);
    ptrCancellation = new Cancellation(this);
    ptrRecords = new Records(this);
}

MainWindow::~MainWindow()
{

    delete ptrBooking;        ptrBooking = nullptr;
    delete ptrCancellation;   ptrCancellation = nullptr;
    delete ptrRecords;        ptrRecords = nullptr;
    delete ui;
}

void MainWindow::on_btnBooking_clicked()
{

    ptrBooking->show();
}

void MainWindow::on_btnCancellation_clicked()
{

    ptrCancellation->show();
}



void MainWindow::on_btnRecords_clicked()
{
    ptrRecords->populateData();
    ptrRecords->show();
}
void MainWindow::on_btnReschedule_clicked()
{
    ptrReschedule = new Reschedule(this);
    ptrReschedule->show();
}
