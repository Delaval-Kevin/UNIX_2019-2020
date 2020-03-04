/********************************************************************************
** Form generated from reading UI file 'DeuxiemeDossierUnix2019.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEUXIEMEDOSSIERUNIX2019_H
#define UI_DEUXIEMEDOSSIERUNIX2019_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainDeuxiemeDossierUnix2019
{
public:
    QWidget *centralWidget;
    QLabel *labelNom;
    QLineEdit *lineAnneeNaissance;
    QLabel *labelImage;
    QPushButton *ButtonModifier;
    QLabel *labelNomImage;
    QLineEdit *lineFichierImage;
    QLabel *labelAnneeNaissance;
    QLineEdit *lineNom;
    QPushButton *ButtonTerminer;
    QPushButton *ButtonPrecedent;
    QLineEdit *lineAdresseMail;
    QPushButton *ButtonSuivant;
    QLabel *labelAdresseMail;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainDeuxiemeDossierUnix2019)
    {
        if (MainDeuxiemeDossierUnix2019->objectName().isEmpty())
            MainDeuxiemeDossierUnix2019->setObjectName(QString::fromUtf8("MainDeuxiemeDossierUnix2019"));
        MainDeuxiemeDossierUnix2019->resize(430, 335);
        centralWidget = new QWidget(MainDeuxiemeDossierUnix2019);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        labelNom = new QLabel(centralWidget);
        labelNom->setObjectName(QString::fromUtf8("labelNom"));
        labelNom->setGeometry(QRect(20, 20, 120, 15));
        lineAnneeNaissance = new QLineEdit(centralWidget);
        lineAnneeNaissance->setObjectName(QString::fromUtf8("lineAnneeNaissance"));
        lineAnneeNaissance->setGeometry(QRect(20, 100, 50, 20));
        lineAnneeNaissance->setReadOnly(true);
        labelImage = new QLabel(centralWidget);
        labelImage->setObjectName(QString::fromUtf8("labelImage"));
        labelImage->setGeometry(QRect(260, 25, 150, 191));
        ButtonModifier = new QPushButton(centralWidget);
        ButtonModifier->setObjectName(QString::fromUtf8("ButtonModifier"));
        ButtonModifier->setGeometry(QRect(40, 220, 80, 25));
        labelNomImage = new QLabel(centralWidget);
        labelNomImage->setObjectName(QString::fromUtf8("labelNomImage"));
        labelNomImage->setGeometry(QRect(260, 230, 150, 15));
        lineFichierImage = new QLineEdit(centralWidget);
        lineFichierImage->setObjectName(QString::fromUtf8("lineFichierImage"));
        lineFichierImage->setGeometry(QRect(260, 255, 150, 20));
        labelAnneeNaissance = new QLabel(centralWidget);
        labelAnneeNaissance->setObjectName(QString::fromUtf8("labelAnneeNaissance"));
        labelAnneeNaissance->setGeometry(QRect(20, 75, 120, 15));
        lineNom = new QLineEdit(centralWidget);
        lineNom->setObjectName(QString::fromUtf8("lineNom"));
        lineNom->setGeometry(QRect(20, 45, 220, 20));
        lineNom->setReadOnly(true);
        ButtonTerminer = new QPushButton(centralWidget);
        ButtonTerminer->setObjectName(QString::fromUtf8("ButtonTerminer"));
        ButtonTerminer->setGeometry(QRect(330, 285, 80, 25));
        ButtonPrecedent = new QPushButton(centralWidget);
        ButtonPrecedent->setObjectName(QString::fromUtf8("ButtonPrecedent"));
        ButtonPrecedent->setGeometry(QRect(35, 185, 40, 25));
        lineAdresseMail = new QLineEdit(centralWidget);
        lineAdresseMail->setObjectName(QString::fromUtf8("lineAdresseMail"));
        lineAdresseMail->setGeometry(QRect(20, 155, 200, 20));
        ButtonSuivant = new QPushButton(centralWidget);
        ButtonSuivant->setObjectName(QString::fromUtf8("ButtonSuivant"));
        ButtonSuivant->setGeometry(QRect(85, 185, 40, 25));
        labelAdresseMail = new QLabel(centralWidget);
        labelAdresseMail->setObjectName(QString::fromUtf8("labelAdresseMail"));
        labelAdresseMail->setGeometry(QRect(20, 130, 120, 15));
        MainDeuxiemeDossierUnix2019->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainDeuxiemeDossierUnix2019);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainDeuxiemeDossierUnix2019->setStatusBar(statusBar);

        retranslateUi(MainDeuxiemeDossierUnix2019);

        QMetaObject::connectSlotsByName(MainDeuxiemeDossierUnix2019);
    } // setupUi

    void retranslateUi(QMainWindow *MainDeuxiemeDossierUnix2019)
    {
        MainDeuxiemeDossierUnix2019->setWindowTitle(QApplication::translate("MainDeuxiemeDossierUnix2019", "Liste Etudiants groupe 2205.", 0, QApplication::UnicodeUTF8));
        labelNom->setText(QApplication::translate("MainDeuxiemeDossierUnix2019", "Nom :", 0, QApplication::UnicodeUTF8));
        labelImage->setText(QApplication::translate("MainDeuxiemeDossierUnix2019", "TextLabel", 0, QApplication::UnicodeUTF8));
        ButtonModifier->setText(QApplication::translate("MainDeuxiemeDossierUnix2019", "Modifier", 0, QApplication::UnicodeUTF8));
        labelNomImage->setText(QApplication::translate("MainDeuxiemeDossierUnix2019", "Image :", 0, QApplication::UnicodeUTF8));
        labelAnneeNaissance->setText(QApplication::translate("MainDeuxiemeDossierUnix2019", "Ann\303\251e naissance:", 0, QApplication::UnicodeUTF8));
        ButtonTerminer->setText(QApplication::translate("MainDeuxiemeDossierUnix2019", "Terminer", 0, QApplication::UnicodeUTF8));
        ButtonPrecedent->setText(QApplication::translate("MainDeuxiemeDossierUnix2019", "<", 0, QApplication::UnicodeUTF8));
        ButtonSuivant->setText(QApplication::translate("MainDeuxiemeDossierUnix2019", ">", 0, QApplication::UnicodeUTF8));
        labelAdresseMail->setText(QApplication::translate("MainDeuxiemeDossierUnix2019", "Adresse mail :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainDeuxiemeDossierUnix2019: public Ui_MainDeuxiemeDossierUnix2019 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEUXIEMEDOSSIERUNIX2019_H
