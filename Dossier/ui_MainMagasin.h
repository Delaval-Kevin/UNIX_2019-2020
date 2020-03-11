/********************************************************************************
** Form generated from reading UI file 'MainMagasin.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMAGASIN_H
#define UI_MAINMAGASIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMagasin
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *ButtonPrecedent;
    QPushButton *ButtonSuivant;
    QLineEdit *lineArticle1;
    QLineEdit *lineArticle2;
    QLineEdit *lineArticle3;
    QLineEdit *lineArticle4;
    QLabel *labelClient;
    QLineEdit *lineClient;
    QLabel *labelNumCompte;
    QLineEdit *lineNumCompte;
    QLineEdit *lineInfo;
    QLabel *labelInfo;
    QPushButton *ButtonValider;
    QPushButton *ButtonQuitter;
    QLabel *labelImage;
    QRadioButton *radioButton1;
    QRadioButton *radioButton2;
    QRadioButton *radioButton3;
    QRadioButton *radioButton4;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainMagasin)
    {
        if (MainMagasin->objectName().isEmpty())
            MainMagasin->setObjectName(QString::fromUtf8("MainMagasin"));
        MainMagasin->resize(400, 310);
        centralWidget = new QWidget(MainMagasin);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 61, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        ButtonPrecedent = new QPushButton(centralWidget);
        ButtonPrecedent->setObjectName(QString::fromUtf8("ButtonPrecedent"));
        ButtonPrecedent->setGeometry(QRect(30, 170, 40, 25));
        ButtonSuivant = new QPushButton(centralWidget);
        ButtonSuivant->setObjectName(QString::fromUtf8("ButtonSuivant"));
        ButtonSuivant->setGeometry(QRect(100, 170, 40, 25));
        lineArticle1 = new QLineEdit(centralWidget);
        lineArticle1->setObjectName(QString::fromUtf8("lineArticle1"));
        lineArticle1->setGeometry(QRect(30, 50, 113, 20));
        lineArticle1->setReadOnly(true);
        lineArticle2 = new QLineEdit(centralWidget);
        lineArticle2->setObjectName(QString::fromUtf8("lineArticle2"));
        lineArticle2->setGeometry(QRect(30, 80, 113, 20));
        lineArticle2->setReadOnly(true);
        lineArticle3 = new QLineEdit(centralWidget);
        lineArticle3->setObjectName(QString::fromUtf8("lineArticle3"));
        lineArticle3->setGeometry(QRect(30, 110, 113, 20));
        lineArticle3->setReadOnly(true);
        lineArticle4 = new QLineEdit(centralWidget);
        lineArticle4->setObjectName(QString::fromUtf8("lineArticle4"));
        lineArticle4->setGeometry(QRect(30, 140, 113, 20));
        lineArticle4->setReadOnly(true);
        labelClient = new QLabel(centralWidget);
        labelClient->setObjectName(QString::fromUtf8("labelClient"));
        labelClient->setGeometry(QRect(30, 210, 61, 16));
        labelClient->setFont(font);
        lineClient = new QLineEdit(centralWidget);
        lineClient->setObjectName(QString::fromUtf8("lineClient"));
        lineClient->setGeometry(QRect(100, 210, 113, 20));
        labelNumCompte = new QLabel(centralWidget);
        labelNumCompte->setObjectName(QString::fromUtf8("labelNumCompte"));
        labelNumCompte->setGeometry(QRect(30, 240, 61, 16));
        labelNumCompte->setFont(font);
        lineNumCompte = new QLineEdit(centralWidget);
        lineNumCompte->setObjectName(QString::fromUtf8("lineNumCompte"));
        lineNumCompte->setGeometry(QRect(100, 240, 113, 20));
        lineInfo = new QLineEdit(centralWidget);
        lineInfo->setObjectName(QString::fromUtf8("lineInfo"));
        lineInfo->setGeometry(QRect(100, 270, 271, 20));
        lineInfo->setReadOnly(true);
        labelInfo = new QLabel(centralWidget);
        labelInfo->setObjectName(QString::fromUtf8("labelInfo"));
        labelInfo->setGeometry(QRect(30, 270, 61, 16));
        labelInfo->setFont(font);
        ButtonValider = new QPushButton(centralWidget);
        ButtonValider->setObjectName(QString::fromUtf8("ButtonValider"));
        ButtonValider->setGeometry(QRect(310, 210, 60, 25));
        ButtonQuitter = new QPushButton(centralWidget);
        ButtonQuitter->setObjectName(QString::fromUtf8("ButtonQuitter"));
        ButtonQuitter->setGeometry(QRect(310, 240, 60, 25));
        labelImage = new QLabel(centralWidget);
        labelImage->setObjectName(QString::fromUtf8("labelImage"));
        labelImage->setGeometry(QRect(240, 50, 111, 141));
        radioButton1 = new QRadioButton(centralWidget);
        radioButton1->setObjectName(QString::fromUtf8("radioButton1"));
        radioButton1->setGeometry(QRect(10, 50, 21, 17));
        radioButton1->setChecked(true);
        radioButton2 = new QRadioButton(centralWidget);
        radioButton2->setObjectName(QString::fromUtf8("radioButton2"));
        radioButton2->setGeometry(QRect(10, 80, 21, 17));
        radioButton3 = new QRadioButton(centralWidget);
        radioButton3->setObjectName(QString::fromUtf8("radioButton3"));
        radioButton3->setGeometry(QRect(10, 110, 21, 17));
        radioButton4 = new QRadioButton(centralWidget);
        radioButton4->setObjectName(QString::fromUtf8("radioButton4"));
        radioButton4->setGeometry(QRect(10, 140, 21, 17));
        MainMagasin->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainMagasin);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainMagasin->setStatusBar(statusBar);

        retranslateUi(MainMagasin);

        QMetaObject::connectSlotsByName(MainMagasin);
    } // setupUi

    void retranslateUi(QMainWindow *MainMagasin)
    {
        MainMagasin->setWindowTitle(QApplication::translate("MainMagasin", "Magasin", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainMagasin", "Articles:", 0, QApplication::UnicodeUTF8));
        ButtonPrecedent->setText(QApplication::translate("MainMagasin", "<<", 0, QApplication::UnicodeUTF8));
        ButtonSuivant->setText(QApplication::translate("MainMagasin", ">>", 0, QApplication::UnicodeUTF8));
        labelClient->setText(QApplication::translate("MainMagasin", "Client :", 0, QApplication::UnicodeUTF8));
        labelNumCompte->setText(QApplication::translate("MainMagasin", "Compte :", 0, QApplication::UnicodeUTF8));
        labelInfo->setText(QApplication::translate("MainMagasin", "Info:", 0, QApplication::UnicodeUTF8));
        ButtonValider->setText(QApplication::translate("MainMagasin", "Valider", 0, QApplication::UnicodeUTF8));
        ButtonQuitter->setText(QApplication::translate("MainMagasin", "Quitter", 0, QApplication::UnicodeUTF8));
        labelImage->setText(QApplication::translate("MainMagasin", "TextLabel", 0, QApplication::UnicodeUTF8));
        radioButton1->setText(QString());
        radioButton2->setText(QString());
        radioButton3->setText(QString());
        radioButton4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainMagasin: public Ui_MainMagasin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMAGASIN_H
