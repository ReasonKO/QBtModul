/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Mon 8. Jul 20:21:57 2013
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QCheckBox>
#include <QComboBox>
#include <QGroupBox>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_9;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QGroupBox *GB_remote;
    QPushButton *B_RC_back;
    QPushButton *B_RC_q;
    QPushButton *B_RC_e;
    QPushButton *B_RC_b;
    QComboBox *CB_RC_port;
    QPushButton *B_RC_sensor_start;
    QLabel *B_RC_sensor_label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_18;
    QGroupBox *GB_search;
    QListWidget *listWidget;
    QPushButton *Search_back;
    QGroupBox *GB_ost;
    QComboBox *comboBox;
    QPushButton *B_SEARCH;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QCheckBox *checkBox;
    QPushButton *B_AUT;
    QPushButton *B_Disconnect;
    QCheckBox *C_Connect;
    QPushButton *B_Connect;
    QPushButton *B_Send;
    QLineEdit *lineEdit_3;
    QPushButton *B_remcontrol;
    QCheckBox *C_pipe;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(660, 473);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 310, 75, 23));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 310, 75, 23));
        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(180, 310, 75, 23));
        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(190, 260, 75, 23));
        pushButton_5 = new QPushButton(Widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(30, 260, 75, 23));
        pushButton_6 = new QPushButton(Widget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(110, 260, 75, 23));
        pushButton_9 = new QPushButton(Widget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(180, 350, 75, 23));
        pushButton_11 = new QPushButton(Widget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(20, 340, 75, 23));
        pushButton_12 = new QPushButton(Widget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(100, 350, 75, 23));
        GB_remote = new QGroupBox(Widget);
        GB_remote->setObjectName(QString::fromUtf8("GB_remote"));
        GB_remote->setGeometry(QRect(300, 0, 300, 200));
        GB_remote->setFlat(false);
        B_RC_back = new QPushButton(GB_remote);
        B_RC_back->setObjectName(QString::fromUtf8("B_RC_back"));
        B_RC_back->setGeometry(QRect(275, 10, 21, 21));
        B_RC_q = new QPushButton(GB_remote);
        B_RC_q->setObjectName(QString::fromUtf8("B_RC_q"));
        B_RC_q->setGeometry(QRect(120, 90, 31, 23));
        B_RC_e = new QPushButton(GB_remote);
        B_RC_e->setObjectName(QString::fromUtf8("B_RC_e"));
        B_RC_e->setGeometry(QRect(160, 90, 31, 23));
        B_RC_b = new QPushButton(GB_remote);
        B_RC_b->setObjectName(QString::fromUtf8("B_RC_b"));
        B_RC_b->setGeometry(QRect(120, 120, 71, 23));
        CB_RC_port = new QComboBox(GB_remote);
        CB_RC_port->setObjectName(QString::fromUtf8("CB_RC_port"));
        CB_RC_port->setGeometry(QRect(30, 150, 61, 21));
        B_RC_sensor_start = new QPushButton(GB_remote);
        B_RC_sensor_start->setObjectName(QString::fromUtf8("B_RC_sensor_start"));
        B_RC_sensor_start->setGeometry(QRect(100, 150, 41, 21));
        B_RC_sensor_label = new QLabel(GB_remote);
        B_RC_sensor_label->setObjectName(QString::fromUtf8("B_RC_sensor_label"));
        B_RC_sensor_label->setGeometry(QRect(170, 150, 61, 21));
        label_2 = new QLabel(GB_remote);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 120, 31, 21));
        label_3 = new QLabel(GB_remote);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 90, 21, 20));
        label = new QLabel(GB_remote);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 30, 46, 13));
        label_4 = new QLabel(GB_remote);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 60, 31, 20));
        label_5 = new QLabel(GB_remote);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(100, 60, 46, 13));
        label_6 = new QLabel(GB_remote);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(130, 60, 46, 13));
        pushButton_18 = new QPushButton(Widget);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));
        pushButton_18->setGeometry(QRect(120, 210, 75, 23));
        GB_search = new QGroupBox(Widget);
        GB_search->setObjectName(QString::fromUtf8("GB_search"));
        GB_search->setGeometry(QRect(300, 200, 300, 200));
        listWidget = new QListWidget(GB_search);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(5, 15, 290, 180));
        Search_back = new QPushButton(GB_search);
        Search_back->setObjectName(QString::fromUtf8("Search_back"));
        Search_back->setGeometry(QRect(275, 10, 21, 21));
        GB_ost = new QGroupBox(Widget);
        GB_ost->setObjectName(QString::fromUtf8("GB_ost"));
        GB_ost->setGeometry(QRect(0, 0, 300, 200));
        comboBox = new QComboBox(GB_ost);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(5, 5, 231, 21));
        B_SEARCH = new QPushButton(GB_ost);
        B_SEARCH->setObjectName(QString::fromUtf8("B_SEARCH"));
        B_SEARCH->setGeometry(QRect(140, 40, 101, 23));
        lineEdit = new QLineEdit(GB_ost);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 40, 111, 21));
        lineEdit->setReadOnly(true);
        lineEdit_2 = new QLineEdit(GB_ost);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(20, 70, 111, 21));
        lineEdit_2->setReadOnly(true);
        checkBox = new QCheckBox(GB_ost);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setEnabled(false);
        checkBox->setGeometry(QRect(140, 70, 21, 17));
        B_AUT = new QPushButton(GB_ost);
        B_AUT->setObjectName(QString::fromUtf8("B_AUT"));
        B_AUT->setGeometry(QRect(160, 70, 75, 23));
        B_Disconnect = new QPushButton(GB_ost);
        B_Disconnect->setObjectName(QString::fromUtf8("B_Disconnect"));
        B_Disconnect->setGeometry(QRect(150, 100, 75, 23));
        C_Connect = new QCheckBox(GB_ost);
        C_Connect->setObjectName(QString::fromUtf8("C_Connect"));
        C_Connect->setGeometry(QRect(30, 100, 16, 17));
        B_Connect = new QPushButton(GB_ost);
        B_Connect->setObjectName(QString::fromUtf8("B_Connect"));
        B_Connect->setGeometry(QRect(60, 100, 75, 23));
        B_Send = new QPushButton(GB_ost);
        B_Send->setObjectName(QString::fromUtf8("B_Send"));
        B_Send->setGeometry(QRect(20, 130, 71, 23));
        lineEdit_3 = new QLineEdit(GB_ost);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(110, 130, 113, 20));
        B_remcontrol = new QPushButton(GB_ost);
        B_remcontrol->setObjectName(QString::fromUtf8("B_remcontrol"));
        B_remcontrol->setGeometry(QRect(230, 150, 31, 23));
        C_pipe = new QCheckBox(GB_ost);
        C_pipe->setObjectName(QString::fromUtf8("C_pipe"));
        C_pipe->setEnabled(false);
        C_pipe->setGeometry(QRect(250, 10, 41, 17));
        pushButton->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        pushButton_6->raise();
        pushButton_9->raise();
        pushButton_11->raise();
        pushButton_12->raise();
        GB_remote->raise();
        pushButton_18->raise();
        GB_ost->raise();
        GB_search->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        pushButton->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_2->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_3->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_4->setText(QApplication::translate("Widget", "Refresh", 0));
        pushButton_5->setText(QApplication::translate("Widget", "ReadPipe", 0));
        pushButton_6->setText(QApplication::translate("Widget", "Sleep", 0));
        pushButton_9->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_11->setText(QApplication::translate("Widget", "test1", 0));
        pushButton_12->setText(QApplication::translate("Widget", "test0", 0));
        GB_remote->setTitle(QApplication::translate("Widget", "Remote control", 0));
        B_RC_back->setText(QApplication::translate("Widget", "\302\253", 0));
        B_RC_q->setText(QApplication::translate("Widget", "q", 0));
        B_RC_e->setText(QApplication::translate("Widget", "e", 0));
        B_RC_b->setText(QApplication::translate("Widget", "b", 0));
        CB_RC_port->clear();
        CB_RC_port->insertItems(0, QStringList()
         << QApplication::translate("Widget", "1", 0)
         << QApplication::translate("Widget", "2", 0)
         << QApplication::translate("Widget", "3", 0)
         << QApplication::translate("Widget", "4", 0)
        );
        B_RC_sensor_start->setText(QApplication::translate("Widget", "start", 0 ));
        B_RC_sensor_label->setText(QApplication::translate("Widget", "0", 0 ));
        label_2->setText(QApplication::translate("Widget", "beep", 0 ));
        label_3->setText(QApplication::translate("Widget", "kick", 0 ));
        label->setText(QApplication::translate("Widget", "\342\206\221 - w", 0 ));
        label_4->setText(QApplication::translate("Widget", "\342\206\220 - a", 0 ));
        label_5->setText(QApplication::translate("Widget", "\342\206\223- s", 0 ));
        label_6->setText(QApplication::translate("Widget", "\342\206\222 - d", 0 ));
        pushButton_18->setText(QApplication::translate("Widget", "PushButton", 0 ));
        GB_search->setTitle(QApplication::translate("Widget", "Search", 0 ));
        Search_back->setText(QApplication::translate("Widget", "\302\253", 0 ));
        GB_ost->setTitle(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "1", 0 )
         << QApplication::translate("Widget", "2", 0 )
         << QApplication::translate("Widget", "3", 0 )
         << QApplication::translate("Widget", "4", 0 )
         << QApplication::translate("Widget", "5", 0 )
         << QApplication::translate("Widget", "6", 0 )
         << QApplication::translate("Widget", "7", 0 )
         << QApplication::translate("Widget", "8", 0 )
         << QApplication::translate("Widget", "9", 0 )
         << QApplication::translate("Widget", "10", 0 )
        );
        B_SEARCH->setText(QApplication::translate("Widget", "Search Devices", 0 ));
        lineEdit->setText(QApplication::translate("Widget", "00:00:00:00:00:00", 0 ));
        lineEdit_2->setText(QString());
        checkBox->setText(QString());
        B_AUT->setText(QApplication::translate("Widget", "Authenticate", 0 ));
        B_Disconnect->setText(QApplication::translate("Widget", "Disconnect", 0 ));
        C_Connect->setText(QString());
        B_Connect->setText(QApplication::translate("Widget", "Connect", 0 ));
        B_Send->setText(QApplication::translate("Widget", "Send", 0 ));
        B_remcontrol->setText(QApplication::translate("Widget", "RM", 0 ));
        C_pipe->setText(QApplication::translate("Widget", "pipe", 0 ));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
