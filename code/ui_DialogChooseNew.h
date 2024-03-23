/********************************************************************************
** Form generated from reading UI file 'DialogChooseNew.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCHOOSENEW_H
#define UI_DIALOGCHOOSENEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_DialogChooseNew
{
public:
    QRadioButton *radioButton;
    QRadioButton *radioButton2;
    QRadioButton *radioButton3;
    QRadioButton *radioButton4;
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;

    void setupUi(QDialog *DialogChooseNew)
    {
        if (DialogChooseNew->objectName().isEmpty())
            DialogChooseNew->setObjectName(QStringLiteral("DialogChooseNew"));
        DialogChooseNew->resize(174, 188);
        radioButton = new QRadioButton(DialogChooseNew);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setEnabled(false);
        radioButton->setGeometry(QRect(9, 18, 71, 16));
        radioButton2 = new QRadioButton(DialogChooseNew);
        radioButton2->setObjectName(QStringLiteral("radioButton2"));
        radioButton2->setEnabled(false);
        radioButton2->setGeometry(QRect(9, 49, 41, 16));
        radioButton3 = new QRadioButton(DialogChooseNew);
        radioButton3->setObjectName(QStringLiteral("radioButton3"));
        radioButton3->setEnabled(false);
        radioButton3->setGeometry(QRect(9, 80, 35, 16));
        radioButton4 = new QRadioButton(DialogChooseNew);
        radioButton4->setObjectName(QStringLiteral("radioButton4"));
        radioButton4->setGeometry(QRect(9, 111, 77, 16));
        buttonBox = new QDialogButtonBox(DialogChooseNew);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(9, 142, 156, 23));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(DialogChooseNew);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(30, 110, 113, 20));

        retranslateUi(DialogChooseNew);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogChooseNew, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogChooseNew, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogChooseNew);
    } // setupUi

    void retranslateUi(QDialog *DialogChooseNew)
    {
        DialogChooseNew->setWindowTitle(QApplication::translate("DialogChooseNew", "Dialog", 0));
        radioButton->setText(QApplication::translate("DialogChooseNew", "yuuta", 0));
        radioButton2->setText(QApplication::translate("DialogChooseNew", "fhh", 0));
        radioButton3->setText(QApplication::translate("DialogChooseNew", "yr", 0));
        radioButton4->setText(QApplication::translate("DialogChooseNew", "character", 0));
        lineEdit->setText(QApplication::translate("DialogChooseNew", "character1", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogChooseNew: public Ui_DialogChooseNew {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCHOOSENEW_H
