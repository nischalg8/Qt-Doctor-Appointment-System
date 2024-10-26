/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btnBooking;
    QPushButton *btnCancellation;
    QPushButton *btnReschedule;
    QPushButton *btnRecords;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(758, 438);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        btnBooking = new QPushButton(centralWidget);
        btnBooking->setObjectName("btnBooking");
        btnBooking->setGeometry(QRect(10, 10, 75, 61));
        btnCancellation = new QPushButton(centralWidget);
        btnCancellation->setObjectName("btnCancellation");
        btnCancellation->setGeometry(QRect(100, 10, 75, 61));
        btnReschedule = new QPushButton(centralWidget);
        btnReschedule->setObjectName("btnReschedule");
        btnReschedule->setGeometry(QRect(190, 10, 81, 61));
        btnRecords = new QPushButton(centralWidget);
        btnRecords->setObjectName("btnRecords");
        btnRecords->setGeometry(QRect(280, 10, 75, 61));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Doctor Appointment 1.0", nullptr));
        btnBooking->setText(QCoreApplication::translate("MainWindow", "Booking", nullptr));
        btnCancellation->setText(QCoreApplication::translate("MainWindow", "Cancellation", nullptr));
        btnReschedule->setText(QCoreApplication::translate("MainWindow", "Reschedule", nullptr));
        btnRecords->setText(QCoreApplication::translate("MainWindow", "Records", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
