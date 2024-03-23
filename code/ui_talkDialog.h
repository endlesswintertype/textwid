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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_talkDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *historyBtn;
    QPushButton *closeHistory;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeBtn;
    QTextEdit *textContent;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *nextBtn;
    QListWidget *listWidget;
    QWidget *widgetChoose;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *eventName1;
    QPushButton *optionBtn;
    QHBoxLayout *horizontalLayout_3;
    QLabel *eventName2;
    QPushButton *optionBtn2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *eventName3;
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
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        historyBtn = new QPushButton(widget);
        historyBtn->setObjectName(QStringLiteral("historyBtn"));

        horizontalLayout_5->addWidget(historyBtn);

        closeHistory = new QPushButton(widget);
        closeHistory->setObjectName(QStringLiteral("closeHistory"));

        horizontalLayout_5->addWidget(closeHistory);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        closeBtn = new QPushButton(widget);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));

        horizontalLayout_5->addWidget(closeBtn);


        verticalLayout_2->addLayout(horizontalLayout_5);

        textContent = new QTextEdit(widget);
        textContent->setObjectName(QStringLiteral("textContent"));

        verticalLayout_2->addWidget(textContent);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        nextBtn = new QPushButton(widget);
        nextBtn->setObjectName(QStringLiteral("nextBtn"));

        horizontalLayout_6->addWidget(nextBtn);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout_3->addLayout(verticalLayout_2);

        listWidget = new QListWidget(widget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_3->addWidget(listWidget);


        horizontalLayout->addWidget(widget);

        widgetChoose = new QWidget(talkDialog);
        widgetChoose->setObjectName(QStringLiteral("widgetChoose"));
        verticalLayout = new QVBoxLayout(widgetChoose);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        eventName1 = new QLabel(widgetChoose);
        eventName1->setObjectName(QStringLiteral("eventName1"));

        horizontalLayout_2->addWidget(eventName1);

        optionBtn = new QPushButton(widgetChoose);
        optionBtn->setObjectName(QStringLiteral("optionBtn"));

        horizontalLayout_2->addWidget(optionBtn);

        horizontalLayout_2->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        eventName2 = new QLabel(widgetChoose);
        eventName2->setObjectName(QStringLiteral("eventName2"));

        horizontalLayout_3->addWidget(eventName2);

        optionBtn2 = new QPushButton(widgetChoose);
        optionBtn2->setObjectName(QStringLiteral("optionBtn2"));

        horizontalLayout_3->addWidget(optionBtn2);

        horizontalLayout_3->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        eventName3 = new QLabel(widgetChoose);
        eventName3->setObjectName(QStringLiteral("eventName3"));

        horizontalLayout_4->addWidget(eventName3);

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
        historyBtn->setText(QApplication::translate("talkDialog", "\345\233\236\351\241\276", 0));
        closeHistory->setText(QApplication::translate("talkDialog", "\345\205\263\351\227\255\345\233\236\351\241\276", 0));
        closeBtn->setText(QApplication::translate("talkDialog", "\350\277\224\345\233\236", 0));
        nextBtn->setText(QApplication::translate("talkDialog", "\347\273\247\347\273\255", 0));
        eventName1->setText(QApplication::translate("talkDialog", "TextLabel", 0));
        optionBtn->setText(QApplication::translate("talkDialog", "\351\200\211\346\213\251", 0));
        eventName2->setText(QApplication::translate("talkDialog", "eventName1", 0));
        optionBtn2->setText(QApplication::translate("talkDialog", "\351\200\211\346\213\251", 0));
        eventName3->setText(QApplication::translate("talkDialog", "eventName3", 0));
        optionBtn3->setText(QApplication::translate("talkDialog", "\351\200\211\346\213\251", 0));
    } // retranslateUi

};

namespace Ui {
    class talkDialog: public Ui_talkDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TALKDIALOG_H
