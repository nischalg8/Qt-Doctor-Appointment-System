/********************************************************************************
** Form generated from reading UI file 'booking.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKING_H
#define UI_BOOKING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Booking
{
public:
    QLabel *label;
    QLineEdit *txtName;
    QLabel *label_2;
    QPushButton *btnBook;
    QLabel *label_3;
    QLineEdit *txtContactNo;
    QLabel *lblinfo;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label_4;
    QComboBox *doctorComboBox;
    QLabel *label_5;

    void setupUi(QDialog *Booking)
    {
        if (Booking->objectName().isEmpty())
            Booking->setObjectName("Booking");
        Booking->setWindowModality(Qt::WindowModality::WindowModal);
        Booking->resize(721, 467);
        label = new QLabel(Booking);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 80, 121, 16));
        QFont font;
        font.setFamilies({QString::fromUtf8("Comic Sans MS")});
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font-family: 'Comic Sans MS', cursive, sans-serif;\n"
"font-size:20px;"));
        txtName = new QLineEdit(Booking);
        txtName->setObjectName("txtName");
        txtName->setGeometry(QRect(250, 190, 191, 31));
        QFont font1;
        font1.setPointSize(10);
        txtName->setFont(font1);
        txtName->setStyleSheet(QString::fromUtf8("border:none;"));
        label_2 = new QLabel(Booking);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 200, 171, 21));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("font-family: 'Comic Sans MS', cursive, sans-serif;\n"
"font-size:20px;"));
        btnBook = new QPushButton(Booking);
        btnBook->setObjectName("btnBook");
        btnBook->setGeometry(QRect(300, 349, 75, 41));
        QFont font2;
        font2.setBold(true);
        btnBook->setFont(font2);
        btnBook->setStyleSheet(QString::fromUtf8("\n"
"    QPushButton {\n"
"        background-color: white;\n"
"        border: 2px solid #3498db;\n"
"        color: #3498db;\n"
"        padding: 5px 10px;\n"
"        border-radius: 8px;\n"
"        font-size: 14px;\n"
"        font-weight: bold;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: #3498db;\n"
"        color: white;\n"
"    }\n"
"    "));
        label_3 = new QLabel(Booking);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 260, 171, 21));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("font-family: 'Comic Sans MS', cursive, sans-serif;\n"
"font-size:20px;"));
        txtContactNo = new QLineEdit(Booking);
        txtContactNo->setObjectName("txtContactNo");
        txtContactNo->setGeometry(QRect(250, 250, 191, 31));
        txtContactNo->setFont(font1);
        txtContactNo->setStyleSheet(QString::fromUtf8("border:none;"));
        lblinfo = new QLabel(Booking);
        lblinfo->setObjectName("lblinfo");
        lblinfo->setGeometry(QRect(82, 409, 541, 31));
        lblinfo->setStyleSheet(QString::fromUtf8("font-family: 'Comic Sans MS', cursive, sans-serif;\n"
"font-size:20px;"));
        dateTimeEdit = new QDateTimeEdit(Booking);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setGeometry(QRect(250, 70, 194, 31));
        dateTimeEdit->setStyleSheet(QString::fromUtf8("QDateTimeEdit {\n"
"    font-size: 14px;\n"
"    padding: 6px;\n"
"    border: 1px solid #c3cfd9;\n"
"    border-radius: 5px;\n"
"    background-color: #ffffff;\n"
"    color: #333;\n"
"    min-width: 150px;\n"
"}\n"
""));
        dateTimeEdit->setMaximumDateTime(QDateTime(QDate(9999, 5, 30), QTime(23, 59, 59)));
        label_4 = new QLabel(Booking);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(160, 0, 301, 61));
        label_4->setStyleSheet(QString::fromUtf8("font-family: 'Comic Sans MS', cursive, sans-serif;\n"
"font-size:20px;"));
        doctorComboBox = new QComboBox(Booking);
        doctorComboBox->setObjectName("doctorComboBox");
        doctorComboBox->setGeometry(QRect(250, 130, 191, 31));
        label_5 = new QLabel(Booking);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(70, 140, 171, 21));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("font-family: 'Comic Sans MS', cursive, sans-serif;\n"
"font-size:20px;"));

        retranslateUi(Booking);

        QMetaObject::connectSlotsByName(Booking);
    } // setupUi

    void retranslateUi(QDialog *Booking)
    {
        Booking->setWindowTitle(QCoreApplication::translate("Booking", "Booking", nullptr));
        label->setText(QCoreApplication::translate("Booking", "Select Slot", nullptr));
        label_2->setText(QCoreApplication::translate("Booking", "Name of Patient *", nullptr));
        btnBook->setText(QCoreApplication::translate("Booking", "BOOK", nullptr));
        label_3->setText(QCoreApplication::translate("Booking", "Contact Number *", nullptr));
        lblinfo->setText(QString());
        label_4->setText(QCoreApplication::translate("Booking", "Enter time from 8 am to 5 pm", nullptr));
        label_5->setText(QCoreApplication::translate("Booking", "Doctor list ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Booking: public Ui_Booking {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKING_H
