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
        label->setGeometry(QRect(200, 130, 101, 20));
        label_2 = new QLabel(Reschedule);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(200, 190, 91, 20));
        label_3 = new QLabel(Reschedule);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(200, 330, 111, 20));
        textLabel = new QLabel(Reschedule);
        textLabel->setObjectName("textLabel");
        textLabel->setGeometry(QRect(210, 460, 401, 20));
        lineEdit = new QLineEdit(Reschedule);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(350, 120, 113, 28));
        lineEdit_2 = new QLineEdit(Reschedule);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(350, 180, 113, 28));
        dateTimeEdit = new QDateTimeEdit(Reschedule);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setGeometry(QRect(330, 330, 194, 29));
        btnSave = new QPushButton(Reschedule);
        btnSave->setObjectName("btnSave");
        btnSave->setGeometry(QRect(360, 400, 83, 29));
        btnSearch = new QPushButton(Reschedule);
        btnSearch->setObjectName("btnSearch");
        btnSearch->setGeometry(QRect(360, 230, 83, 29));
        textLabel_2 = new QLabel(Reschedule);
        textLabel_2->setObjectName("textLabel_2");
        textLabel_2->setGeometry(QRect(230, 280, 401, 21));

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
