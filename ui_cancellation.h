/********************************************************************************
** Form generated from reading UI file 'cancellation.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANCELLATION_H
#define UI_CANCELLATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Cancellation
{
public:
    QPushButton *btnCancel;
    QLineEdit *txtTokenNo;
    QLabel *label_2;
    QLabel *lblInfo;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *txtContactNo;

    void setupUi(QDialog *Cancellation)
    {
        if (Cancellation->objectName().isEmpty())
            Cancellation->setObjectName("Cancellation");
        Cancellation->setWindowModality(Qt::WindowModality::WindowModal);
        Cancellation->resize(598, 345);
        btnCancel = new QPushButton(Cancellation);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(240, 220, 81, 41));
        QFont font;
        font.setBold(true);
        btnCancel->setFont(font);
        btnCancel->setStyleSheet(QString::fromUtf8(" background-color: white;\n"
"    border: 2px solid #3498db;\n"
"    color: #3498db;\n"
"    padding: 5px 10px;\n"
"    border-radius: 8px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;                   "));
        txtTokenNo = new QLineEdit(Cancellation);
        txtTokenNo->setObjectName("txtTokenNo");
        txtTokenNo->setGeometry(QRect(240, 120, 171, 31));
        QFont font1;
        font1.setPointSize(10);
        txtTokenNo->setFont(font1);
        txtTokenNo->setStyleSheet(QString::fromUtf8("border:none;"));
        label_2 = new QLabel(Cancellation);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(120, 120, 101, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Comic Sans MS")});
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("font-family: 'Comic Sans MS', cursive, sans-serif;\n"
"font-size:20px;"));
        lblInfo = new QLabel(Cancellation);
        lblInfo->setObjectName("lblInfo");
        lblInfo->setGeometry(QRect(100, 290, 371, 31));
        lblInfo->setStyleSheet(QString::fromUtf8("font-family: 'Comic Sans MS', cursive, sans-serif;\n"
"font-size:20px;"));
        label = new QLabel(Cancellation);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 50, 251, 41));
        label->setStyleSheet(QString::fromUtf8("font-family: 'Comic Sans MS', cursive, sans-serif;\n"
"font-size:20px;"));
        label_3 = new QLabel(Cancellation);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(120, 170, 101, 31));
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("font-family: 'Comic Sans MS', cursive, sans-serif;\n"
"font-size:20px;"));
        txtContactNo = new QLineEdit(Cancellation);
        txtContactNo->setObjectName("txtContactNo");
        txtContactNo->setGeometry(QRect(240, 170, 171, 31));
        txtContactNo->setFont(font1);
        txtContactNo->setStyleSheet(QString::fromUtf8("border:none;"));

        retranslateUi(Cancellation);

        QMetaObject::connectSlotsByName(Cancellation);
    } // setupUi

    void retranslateUi(QDialog *Cancellation)
    {
        Cancellation->setWindowTitle(QCoreApplication::translate("Cancellation", "Cancel Booking", nullptr));
        btnCancel->setText(QCoreApplication::translate("Cancellation", "CANCEL", nullptr));
        label_2->setText(QCoreApplication::translate("Cancellation", "Token no.", nullptr));
        lblInfo->setText(QString());
        label->setText(QCoreApplication::translate("Cancellation", "Cancel your appointment !", nullptr));
        label_3->setText(QCoreApplication::translate("Cancellation", "Contact no.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Cancellation: public Ui_Cancellation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANCELLATION_H
