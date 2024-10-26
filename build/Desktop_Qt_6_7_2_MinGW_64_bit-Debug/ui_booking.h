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
    QComboBox *doctorComboBox;
    QLabel *label_4;

    void setupUi(QDialog *Booking)
    {
        if (Booking->objectName().isEmpty())
            Booking->setObjectName("Booking");
        Booking->setWindowModality(Qt::WindowModality::WindowModal);
        Booking->resize(721, 467);
        label = new QLabel(Booking);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 60, 91, 16));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        txtName = new QLineEdit(Booking);
        txtName->setObjectName("txtName");
        txtName->setGeometry(QRect(270, 160, 113, 20));
        txtName->setFont(font);
        label_2 = new QLabel(Booking);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 160, 131, 21));
        label_2->setFont(font);
        btnBook = new QPushButton(Booking);
        btnBook->setObjectName("btnBook");
        btnBook->setGeometry(QRect(300, 360, 75, 30));
        btnBook->setFont(font);
        label_3 = new QLabel(Booking);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 200, 131, 21));
        label_3->setFont(font);
        txtContactNo = new QLineEdit(Booking);
        txtContactNo->setObjectName("txtContactNo");
        txtContactNo->setGeometry(QRect(270, 200, 113, 20));
        txtContactNo->setFont(font);
        lblinfo = new QLabel(Booking);
        lblinfo->setObjectName("lblinfo");
        lblinfo->setGeometry(QRect(82, 420, 491, 20));
        dateTimeEdit = new QDateTimeEdit(Booking);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setGeometry(QRect(270, 60, 194, 29));
        dateTimeEdit->setMaximumDateTime(QDateTime(QDate(9999, 5, 30), QTime(23, 59, 59)));
        doctorComboBox = new QComboBox(Booking);
        doctorComboBox->setObjectName("doctorComboBox");
        doctorComboBox->setGeometry(QRect(280, 110, 201, 28));
        label_4 = new QLabel(Booking);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(100, 120, 71, 20));

        retranslateUi(Booking);

        QMetaObject::connectSlotsByName(Booking);
    } // setupUi

    void retranslateUi(QDialog *Booking)
    {
        Booking->setWindowTitle(QCoreApplication::translate("Booking", "Booking", nullptr));
        label->setText(QCoreApplication::translate("Booking", "Select Slot", nullptr));
        label_2->setText(QCoreApplication::translate("Booking", "Name of Patient", nullptr));
        btnBook->setText(QCoreApplication::translate("Booking", "BOOK", nullptr));
        label_3->setText(QCoreApplication::translate("Booking", "Contact Number", nullptr));
        lblinfo->setText(QCoreApplication::translate("Booking", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("Booking", "Doctor list", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Booking: public Ui_Booking {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKING_H
