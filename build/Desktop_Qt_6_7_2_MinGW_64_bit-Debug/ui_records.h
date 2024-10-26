/********************************************************************************
** Form generated from reading UI file 'records.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDS_H
#define UI_RECORDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_Records
{
public:
    QTableView *tableView;
    QLabel *lblinfo;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *btnSearch;

    void setupUi(QDialog *Records)
    {
        if (Records->objectName().isEmpty())
            Records->setObjectName("Records");
        Records->setWindowModality(Qt::WindowModality::WindowModal);
        Records->resize(880, 541);
        tableView = new QTableView(Records);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(100, 210, 671, 231));
        lblinfo = new QLabel(Records);
        lblinfo->setObjectName("lblinfo");
        lblinfo->setGeometry(QRect(240, 460, 361, 20));
        lineEdit = new QLineEdit(Records);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(300, 80, 113, 28));
        lineEdit_2 = new QLineEdit(Records);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(300, 120, 113, 28));
        label = new QLabel(Records);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 80, 63, 20));
        label_2 = new QLabel(Records);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 120, 81, 20));
        btnSearch = new QPushButton(Records);
        btnSearch->setObjectName("btnSearch");
        btnSearch->setGeometry(QRect(310, 160, 83, 29));

        retranslateUi(Records);

        QMetaObject::connectSlotsByName(Records);
    } // setupUi

    void retranslateUi(QDialog *Records)
    {
        Records->setWindowTitle(QCoreApplication::translate("Records", "Records", nullptr));
        lblinfo->setText(QString());
        label->setText(QCoreApplication::translate("Records", "Token No.", nullptr));
        label_2->setText(QCoreApplication::translate("Records", "Contact No.", nullptr));
        btnSearch->setText(QCoreApplication::translate("Records", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Records: public Ui_Records {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDS_H
