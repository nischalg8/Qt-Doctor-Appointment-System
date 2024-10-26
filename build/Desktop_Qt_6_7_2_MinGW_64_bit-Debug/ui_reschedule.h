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

class Ui_reschedule
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label_4;

    void setupUi(QDialog *reschedule)
    {
        if (reschedule->objectName().isEmpty())
            reschedule->setObjectName("reschedule");
        reschedule->resize(597, 365);
        label = new QLabel(reschedule);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 80, 63, 20));
        label_2 = new QLabel(reschedule);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 110, 81, 20));
        lineEdit = new QLineEdit(reschedule);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(210, 70, 113, 28));
        lineEdit_2 = new QLineEdit(reschedule);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(210, 110, 113, 28));
        label_3 = new QLabel(reschedule);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 190, 381, 20));
        pushButton = new QPushButton(reschedule);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(230, 150, 83, 29));
        dateTimeEdit = new QDateTimeEdit(reschedule);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setGeometry(QRect(210, 230, 194, 29));
        label_4 = new QLabel(reschedule);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(32, 240, 141, 20));

        retranslateUi(reschedule);

        QMetaObject::connectSlotsByName(reschedule);
    } // setupUi

    void retranslateUi(QDialog *reschedule)
    {
        reschedule->setWindowTitle(QCoreApplication::translate("reschedule", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("reschedule", "Token No.", nullptr));
        label_2->setText(QCoreApplication::translate("reschedule", "Contact No.", nullptr));
        label_3->setText(QCoreApplication::translate("reschedule", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("reschedule", "Search", nullptr));
        label_4->setText(QCoreApplication::translate("reschedule", "Enter new time/date", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reschedule: public Ui_reschedule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESCHEDULE_H
