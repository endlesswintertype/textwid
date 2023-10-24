/********************************************************************************
** Form generated from reading UI file 'talkDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TALKDIALOG_H
#define UI_TALKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_talkDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QPushButton *hestoryBtn;
    QPushButton *closeBtn;
    QTextEdit *textContent;
    QPushButton *nextBtn;
    QTextEdit *textName;
    QListWidget *listWidget;
    QWidget *widgetChoose;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *textLabel1;
    QPushButton *optionBtn;
    QHBoxLayout *horizontalLayout_3;
    QLabel *textLabel2;
    QPushButton *optionBtn2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *textLabel3;
    QPushButton *optionBtn3;

    void setupUi(QDialog *talkDialog)
    {
        if (talkDialog->objectName().isEmpty())
            talkDialog->setObjectName(QStringLiteral("talkDialog"));
        talkDialog->resize(736, 300);
        horizontalLayout = new QHBoxLayout(talkDialog);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(talkDialog);
        widget->setObjectName(QStringLiteral("widget"));
        hestoryBtn = new QPushButton(widget);
        hestoryBtn->setObjectName(QStringLiteral("hestoryBtn"));
        hestoryBtn->setGeometry(QRect(10, 10, 75, 23));
        closeBtn = new QPushButton(widget);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setGeometry(QRect(280, 10, 75, 23));
        textContent = new QTextEdit(widget);
        textContent->setObjectName(QStringLiteral("textContent"));
        textContent->setGeometry(QRect(10, 90, 351, 121));
        nextBtn = new QPushButton(widget);
        nextBtn->setObjectName(QStringLiteral("nextBtn"));
        nextBtn->setGeometry(QRect(280, 250, 75, 23));
        textName = new QTextEdit(widget);
        textName->setObjectName(QStringLiteral("textName"));
        textName->setGeometry(QRect(10, 50, 71, 31));
        listWidget = new QListWidget(widget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 40, 341, 141));

        horizontalLayout->addWidget(widget);

        widgetChoose = new QWidget(talkDialog);
        widgetChoose->setObjectName(QStringLiteral("widgetChoose"));
        verticalLayout = new QVBoxLayout(widgetChoose);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        textLabel1 = new QLabel(widgetChoose);
        textLabel1->setObjectName(QStringLiteral("textLabel1"));

        horizontalLayout_2->addWidget(textLabel1);

        optionBtn = new QPushButton(widgetChoose);
        optionBtn->setObjectName(QStringLiteral("optionBtn"));

        horizontalLayout_2->addWidget(optionBtn);

        horizontalLayout_2->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        textLabel2 = new QLabel(widgetChoose);
        textLabel2->setObjectName(QStringLiteral("textLabel2"));

        horizontalLayout_3->addWidget(textLabel2);

        optionBtn2 = new QPushButton(widgetChoose);
        optionBtn2->setObjectName(QStringLiteral("optionBtn2"));

        horizontalLayout_3->addWidget(optionBtn2);

        horizontalLayout_3->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        textLabel3 = new QLabel(widgetChoose);
        textLabel3->setObjectName(QStringLiteral("textLabel3"));

        horizontalLayout_4->addWidget(textLabel3);

        optionBtn3 = new QPushButton(widgetChoose);
        optionBtn3->setObjectName(QStringLiteral("optionBtn3"));

        horizontalLayout_4->addWidget(optionBtn3);

        horizontalLayout_4->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout->addWidget(widgetChoose);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

        retranslateUi(talkDialog);

        QMetaObject::connectSlotsByName(talkDialog);
    } // setupUi

    void retranslateUi(QDialog *talkDialog)
    {
        talkDialog->setWindowTitle(QApplication::translate("talkDialog", "Dialog", 0));
        hestoryBtn->setText(QApplication::translate("talkDialog", "PushButton", 0));
        closeBtn->setText(QApplication::translate("talkDialog", "return", 0));
        nextBtn->setText(QApplication::translate("talkDialog", "PushButton", 0));
        textLabel1->setText(QApplication::translate("talkDialog", "TextLabel", 0));
        optionBtn->setText(QApplication::translate("talkDialog", "PushButton", 0));
        textLabel2->setText(QApplication::translate("talkDialog", "TextLabel", 0));
        optionBtn2->setText(QApplication::translate("talkDialog", "PushButton", 0));
        textLabel3->setText(QApplication::translate("talkDialog", "TextLabel", 0));
        optionBtn3->setText(QApplication::translate("talkDialog", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class talkDialog: public Ui_talkDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TALKDIALOG_H
