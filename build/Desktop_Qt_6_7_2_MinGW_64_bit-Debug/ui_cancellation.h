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
    QLabel *label_2;
    QLineEdit *txtTokenNo;
    QLabel *lblInfo;
    QLineEdit *txtContactNo;
    QLabel *label;

    void setupUi(QDialog *Cancellation)
    {
        if (Cancellation->objectName().isEmpty())
            Cancellation->setObjectName("Cancellation");
        Cancellation->setWindowModality(Qt::WindowModality::WindowModal);
        Cancellation->resize(419, 232);
        btnCancel = new QPushButton(Cancellation);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(160, 120, 75, 30));
        QFont font;
        font.setPointSize(10);
        btnCancel->setFont(font);
        label_2 = new QLabel(Cancellation);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 40, 91, 21));
        label_2->setFont(font);
        txtTokenNo = new QLineEdit(Cancellation);
        txtTokenNo->setObjectName("txtTokenNo");
        txtTokenNo->setGeometry(QRect(150, 40, 113, 20));
        txtTokenNo->setFont(font);
        lblInfo = new QLabel(Cancellation);
        lblInfo->setObjectName("lblInfo");
        lblInfo->setGeometry(QRect(50, 170, 321, 20));
        txtContactNo = new QLineEdit(Cancellation);
        txtContactNo->setObjectName("txtContactNo");
        txtContactNo->setGeometry(QRect(150, 70, 113, 21));
        label = new QLabel(Cancellation);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 70, 81, 20));

        retranslateUi(Cancellation);

        QMetaObject::connectSlotsByName(Cancellation);
    } // setupUi

    void retranslateUi(QDialog *Cancellation)
    {
        Cancellation->setWindowTitle(QCoreApplication::translate("Cancellation", "Cancel Booking", nullptr));
        btnCancel->setText(QCoreApplication::translate("Cancellation", "CANCEL", nullptr));
        label_2->setText(QCoreApplication::translate("Cancellation", "Token No", nullptr));
        lblInfo->setText(QString());
        label->setText(QCoreApplication::translate("Cancellation", "Contact No", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Cancellation: public Ui_Cancellation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANCELLATION_H
