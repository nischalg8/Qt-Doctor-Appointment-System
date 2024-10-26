/********************************************************************************
** Form generated from reading UI file 'reschedule.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESCHEDULE_H
#define UI_RESCHEDULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Reschedule
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *textLabel;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QDateTimeEdit *dateTimeEdit;
    QPushButton *btnSave;
    QPushButton *btnSearch;
    QLabel *textLabel_2;

    void setupUi(QDialog *Reschedule)
    {
        if (Reschedule->objectName().isEmpty())
            Reschedule->setObjectName("Reschedule");
        Reschedule->resize(883, 601);
        label = new QLabel(Reschedule);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 120, 151, 31));
        label->setStyleSheet(QString::fromUtf8("font-family: 'Comic Sans MS', cursive, sans-serif;\n"
"font-size:20px;"));
        label_2 = new QLabel(Reschedule);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 190, 131, 21));
        label_2->setStyleSheet(QString::fromUtf8("font-family: 'Comic Sans MS', cursive, sans-serif;\n"
"font-size:20px;"));
        label_3 = new QLabel(Reschedule);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(160, 340, 151, 21));
        label_3->setStyleSheet(QString::fromUtf8("font-family: 'Comic Sans MS', cursive, sans-serif;\n"
"font-size:20px;"));
        textLabel = new QLabel(Reschedule);
        textLabel->setObjectName("textLabel");
        textLabel->setGeometry(QRect(140, 460, 541, 31));
        textLabel->setStyleSheet(QString::fromUtf8("font-family: 'Comic Sans MS', cursive, sans-serif;\n"
"font-size:20px;"));
        lineEdit = new QLineEdit(Reschedule);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(330, 120, 181, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("border:none;"));
        lineEdit_2 = new QLineEdit(Reschedule);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(330, 180, 181, 31));
        lineEdit_2->setStyleSheet(QString::fromUtf8("border:none;"));
        dateTimeEdit = new QDateTimeEdit(Reschedule);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setGeometry(QRect(330, 330, 211, 41));
        dateTimeEdit->setStyleSheet(QString::fromUtf8("QDateTimeEdit {\n"
"    font-size: 14px;\n"
"    padding: 6px;\n"
"    border: 1px solid #c3cfd9;\n"
"    border-radius: 5px;\n"
"    background-color: #ffffff;\n"
"    color: #333;\n"
"    min-width: 150px;\n"
"}\n"
"\n"
"\n"
""));
        btnSave = new QPushButton(Reschedule);
        btnSave->setObjectName("btnSave");
        btnSave->setGeometry(QRect(350, 400, 131, 41));
        btnSave->setStyleSheet(QString::fromUtf8(" background-color: white;\n"
"    border: 2px solid #3498db;\n"
"    color: #3498db;\n"
"    padding: 5px 10px;\n"
"    border-radius: 8px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;                   "));
        btnSearch = new QPushButton(Reschedule);
        btnSearch->setObjectName("btnSearch");
        btnSearch->setGeometry(QRect(360, 230, 101, 51));
        btnSearch->setStyleSheet(QString::fromUtf8(" background-color: white;\n"
"    border: 2px solid #3498db;\n"
"    color: #3498db;\n"
"    padding: 5px 10px;\n"
"    border-radius: 8px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;                   "));
        textLabel_2 = new QLabel(Reschedule);
        textLabel_2->setObjectName("textLabel_2");
        textLabel_2->setGeometry(QRect(190, 290, 521, 31));
        textLabel_2->setStyleSheet(QString::fromUtf8("font-family: 'Comic Sans MS', cursive, sans-serif;\n"
"font-size:20px;"));

        retranslateUi(Reschedule);

        QMetaObject::connectSlotsByName(Reschedule);
    } // setupUi

    void retranslateUi(QDialog *Reschedule)
    {
        Reschedule->setWindowTitle(QCoreApplication::translate("Reschedule", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Reschedule", "Enter TokenNo", nullptr));
        label_2->setText(QCoreApplication::translate("Reschedule", "Enter Contact", nullptr));
        label_3->setText(QCoreApplication::translate("Reschedule", "New Date/Time", nullptr));
        textLabel->setText(QString());
        btnSave->setText(QCoreApplication::translate("Reschedule", "Reschedule", nullptr));
        btnSearch->setText(QCoreApplication::translate("Reschedule", "Search", nullptr));
        textLabel_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Reschedule: public Ui_Reschedule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESCHEDULE_H
