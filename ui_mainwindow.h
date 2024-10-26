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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *btnBooking;
    QPushButton *btnCancellation;
    QPushButton *btnRecords;
    QLabel *label_4;
    QPushButton *btnReschedule;
    QLabel *label_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(905, 629);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 260, 161, 16));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        btnBooking = new QPushButton(centralWidget);
        btnBooking->setObjectName("btnBooking");
        btnBooking->setGeometry(QRect(110, 410, 131, 101));
        btnBooking->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; /* Green */\n"
"    color: white;\n"
"    font-size: 20px;\n"
"    border: none;\n"
"    padding: 12px 24px;\n"
"    border-radius: 8px;\n"
"\n"
"font-family: 'Comic Sans MS', cursive, sans-serif;\n"
"\n"
"  "));
        btnCancellation = new QPushButton(centralWidget);
        btnCancellation->setObjectName("btnCancellation");
        btnCancellation->setGeometry(QRect(270, 410, 161, 101));
        btnCancellation->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; /* Green */\n"
"    color: white;\n"
"    font-size: 20px;\n"
"    border: none;\n"
"    padding: 12px 24px;\n"
"    border-radius: 8px;\n"
"    cursor: pointer;\n"
"font-family: 'Comic Sans MS', cursive, sans-serif;\n"
"  "));
        btnRecords = new QPushButton(centralWidget);
        btnRecords->setObjectName("btnRecords");
        btnRecords->setGeometry(QRect(650, 410, 151, 101));
        btnRecords->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; /* Green */\n"
"    color: white;\n"
"    font-size: 20px;\n"
"    border: none;\n"
"    padding: 12px 24px;\n"
"    border-radius: 8px;\n"
"  font-family: 'Comic Sans MS', cursive, sans-serif;"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(190, 50, 521, 61));
        label_4->setStyleSheet(QString::fromUtf8("\n"
"    color: black;\n"
"    font-size: 30px;\n"
"    border: none;\n"
"    padding: 12px 24px;\n"
"    border-radius: 8px;\n"
"\n"
"font-family: 'Comic Sans MS', cursive, sans-serif;\n"
"\n"
"  "));
        btnReschedule = new QPushButton(centralWidget);
        btnReschedule->setObjectName("btnReschedule");
        btnReschedule->setGeometry(QRect(460, 410, 161, 101));
        btnReschedule->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; /* Green */\n"
"    color: white;\n"
"    font-size: 20px;\n"
"    border: none;\n"
"    padding: 12px 24px;\n"
"    border-radius: 8px;\n"
"    cursor: pointer;\n"
"font-family: 'Comic Sans MS', cursive, sans-serif;\n"
"  "));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(340, 190, 191, 121));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/medappoint logo.png")));
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
        label->setText(QString());
        btnBooking->setText(QCoreApplication::translate("MainWindow", "Booking", nullptr));
        btnCancellation->setText(QCoreApplication::translate("MainWindow", "Cancellation", nullptr));
        btnRecords->setText(QCoreApplication::translate("MainWindow", "Records", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", " Book your appointment today!", nullptr));
        btnReschedule->setText(QCoreApplication::translate("MainWindow", "Reschedule", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
