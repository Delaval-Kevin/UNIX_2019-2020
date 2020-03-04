/********************************************************************************
** Form generated from reading UI file 'MainMail.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMAIL_H
#define UI_MAINMAIL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMail
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *labelClient1;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *labelMagasin;
    QLabel *labelClient;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainMail)
    {
        if (MainMail->objectName().isEmpty())
            MainMail->setObjectName(QString::fromUtf8("MainMail"));
        MainMail->resize(400, 202);
        centralWidget = new QWidget(MainMail);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 70, 81, 20));
        labelClient1 = new QLabel(centralWidget);
        labelClient1->setObjectName(QString::fromUtf8("labelClient1"));
        labelClient1->setGeometry(QRect(120, 70, 80, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 100, 380, 16));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 120, 291, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 140, 161, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 160, 81, 16));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(310, 160, 75, 23));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 10, 30, 20));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 30, 30, 20));
        labelMagasin = new QLabel(centralWidget);
        labelMagasin->setObjectName(QString::fromUtf8("labelMagasin"));
        labelMagasin->setGeometry(QRect(60, 10, 80, 20));
        labelClient = new QLabel(centralWidget);
        labelClient->setObjectName(QString::fromUtf8("labelClient"));
        labelClient->setGeometry(QRect(60, 30, 80, 20));
        MainMail->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainMail);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainMail->setStatusBar(statusBar);

        retranslateUi(MainMail);

        QMetaObject::connectSlotsByName(MainMail);
    } // setupUi

    void retranslateUi(QMainWindow *MainMail)
    {
        MainMail->setWindowTitle(QApplication::translate("MainMail", "Commande.", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainMail", "Cher M. Mme.  ", 0, QApplication::UnicodeUTF8));
        labelClient1->setText(QApplication::translate("MainMail", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainMail", "Votre commande est disponible dans notre magasin.", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainMail", "Vous pouvez la retirer \303\240 votre convenance.", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainMail", "Bien \303\240 vous.", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainMail", "Le personnel.", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainMail", "Fermer", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainMail", "De :", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainMail", "A :", 0, QApplication::UnicodeUTF8));
        labelMagasin->setText(QApplication::translate("MainMail", "TextLabel", 0, QApplication::UnicodeUTF8));
        labelClient->setText(QApplication::translate("MainMail", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainMail: public Ui_MainMail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMAIL_H
