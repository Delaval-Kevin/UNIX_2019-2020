/********************************************************************************
** Form generated from reading UI file 'MainListeEtudiants2019.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINLISTEETUDIANTS2019_H
#define UI_MAINLISTEETUDIANTS2019_H

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

class Ui_MainListeEtudiants2019
{
public:
    QWidget *centralWidget;
    QLabel *labelPremier;
    QLabel *labelSecond;
    QLabel *labelTroisieme;
    QLabel *labelGroupe1;
    QLabel *labelNbEtud1;
    QLabel *labelGroupe2;
    QLabel *labelNbEtud2;
    QLabel *labelGroupe3;
    QLabel *labelNbEtud3;
    QPushButton *ButtonOk;
    QPushButton *ButtonEffacer;
    QPushButton *ButtonTerminer;
    QLineEdit *lineGroupe1;
    QLineEdit *lineNbEtud1;
    QLineEdit *lineGroupe2;
    QLineEdit *lineNbEtud2;
    QLineEdit *lineGroupe3;
    QLineEdit *lineNbEtud3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainListeEtudiants2019)
    {
        if (MainListeEtudiants2019->objectName().isEmpty())
            MainListeEtudiants2019->setObjectName(QString::fromUtf8("MainListeEtudiants2019"));
        MainListeEtudiants2019->resize(400, 300);
        centralWidget = new QWidget(MainListeEtudiants2019);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        labelPremier = new QLabel(centralWidget);
        labelPremier->setObjectName(QString::fromUtf8("labelPremier"));
        labelPremier->setGeometry(QRect(20, 10, 120, 15));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        labelPremier->setFont(font);
        labelSecond = new QLabel(centralWidget);
        labelSecond->setObjectName(QString::fromUtf8("labelSecond"));
        labelSecond->setGeometry(QRect(20, 90, 150, 15));
        labelSecond->setFont(font);
        labelTroisieme = new QLabel(centralWidget);
        labelTroisieme->setObjectName(QString::fromUtf8("labelTroisieme"));
        labelTroisieme->setGeometry(QRect(20, 170, 150, 15));
        labelTroisieme->setFont(font);
        labelGroupe1 = new QLabel(centralWidget);
        labelGroupe1->setObjectName(QString::fromUtf8("labelGroupe1"));
        labelGroupe1->setGeometry(QRect(20, 35, 150, 15));
        labelNbEtud1 = new QLabel(centralWidget);
        labelNbEtud1->setObjectName(QString::fromUtf8("labelNbEtud1"));
        labelNbEtud1->setGeometry(QRect(20, 60, 120, 15));
        labelGroupe2 = new QLabel(centralWidget);
        labelGroupe2->setObjectName(QString::fromUtf8("labelGroupe2"));
        labelGroupe2->setGeometry(QRect(20, 115, 120, 15));
        labelNbEtud2 = new QLabel(centralWidget);
        labelNbEtud2->setObjectName(QString::fromUtf8("labelNbEtud2"));
        labelNbEtud2->setGeometry(QRect(20, 140, 120, 15));
        labelGroupe3 = new QLabel(centralWidget);
        labelGroupe3->setObjectName(QString::fromUtf8("labelGroupe3"));
        labelGroupe3->setGeometry(QRect(20, 190, 120, 15));
        labelNbEtud3 = new QLabel(centralWidget);
        labelNbEtud3->setObjectName(QString::fromUtf8("labelNbEtud3"));
        labelNbEtud3->setGeometry(QRect(20, 220, 120, 15));
        ButtonOk = new QPushButton(centralWidget);
        ButtonOk->setObjectName(QString::fromUtf8("ButtonOk"));
        ButtonOk->setGeometry(QRect(20, 255, 80, 25));
        ButtonEffacer = new QPushButton(centralWidget);
        ButtonEffacer->setObjectName(QString::fromUtf8("ButtonEffacer"));
        ButtonEffacer->setGeometry(QRect(120, 255, 80, 25));
        ButtonTerminer = new QPushButton(centralWidget);
        ButtonTerminer->setObjectName(QString::fromUtf8("ButtonTerminer"));
        ButtonTerminer->setGeometry(QRect(300, 255, 80, 25));
        lineGroupe1 = new QLineEdit(centralWidget);
        lineGroupe1->setObjectName(QString::fromUtf8("lineGroupe1"));
        lineGroupe1->setGeometry(QRect(170, 30, 120, 20));
        lineNbEtud1 = new QLineEdit(centralWidget);
        lineNbEtud1->setObjectName(QString::fromUtf8("lineNbEtud1"));
        lineNbEtud1->setGeometry(QRect(170, 60, 50, 20));
        lineGroupe2 = new QLineEdit(centralWidget);
        lineGroupe2->setObjectName(QString::fromUtf8("lineGroupe2"));
        lineGroupe2->setGeometry(QRect(170, 110, 120, 20));
        lineNbEtud2 = new QLineEdit(centralWidget);
        lineNbEtud2->setObjectName(QString::fromUtf8("lineNbEtud2"));
        lineNbEtud2->setGeometry(QRect(170, 140, 50, 20));
        lineGroupe3 = new QLineEdit(centralWidget);
        lineGroupe3->setObjectName(QString::fromUtf8("lineGroupe3"));
        lineGroupe3->setGeometry(QRect(170, 190, 120, 20));
        lineNbEtud3 = new QLineEdit(centralWidget);
        lineNbEtud3->setObjectName(QString::fromUtf8("lineNbEtud3"));
        lineNbEtud3->setGeometry(QRect(170, 220, 50, 20));
        MainListeEtudiants2019->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainListeEtudiants2019);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainListeEtudiants2019->setStatusBar(statusBar);

        retranslateUi(MainListeEtudiants2019);

        QMetaObject::connectSlotsByName(MainListeEtudiants2019);
    } // setupUi

    void retranslateUi(QMainWindow *MainListeEtudiants2019)
    {
        MainListeEtudiants2019->setWindowTitle(QApplication::translate("MainListeEtudiants2019", "Lance 3 processus.", 0, QApplication::UnicodeUTF8));
        labelPremier->setText(QApplication::translate("MainListeEtudiants2019", "Premier Groupe :", 0, QApplication::UnicodeUTF8));
        labelSecond->setText(QApplication::translate("MainListeEtudiants2019", "Deuxi\303\250me Groupe :", 0, QApplication::UnicodeUTF8));
        labelTroisieme->setText(QApplication::translate("MainListeEtudiants2019", "Troisi\303\250me Groupe :", 0, QApplication::UnicodeUTF8));
        labelGroupe1->setText(QApplication::translate("MainListeEtudiants2019", "Groupe \303\240 traiter :", 0, QApplication::UnicodeUTF8));
        labelNbEtud1->setText(QApplication::translate("MainListeEtudiants2019", "Nombre etudiants :", 0, QApplication::UnicodeUTF8));
        labelGroupe2->setText(QApplication::translate("MainListeEtudiants2019", "Groupe \303\240 traiter :", 0, QApplication::UnicodeUTF8));
        labelNbEtud2->setText(QApplication::translate("MainListeEtudiants2019", "Nombre etudiants :", 0, QApplication::UnicodeUTF8));
        labelGroupe3->setText(QApplication::translate("MainListeEtudiants2019", "Groupe \303\240 traiter :", 0, QApplication::UnicodeUTF8));
        labelNbEtud3->setText(QApplication::translate("MainListeEtudiants2019", "Nombre etudiants :", 0, QApplication::UnicodeUTF8));
        ButtonOk->setText(QApplication::translate("MainListeEtudiants2019", "Ok", 0, QApplication::UnicodeUTF8));
        ButtonEffacer->setText(QApplication::translate("MainListeEtudiants2019", "Effacer", 0, QApplication::UnicodeUTF8));
        ButtonTerminer->setText(QApplication::translate("MainListeEtudiants2019", "Terminer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainListeEtudiants2019: public Ui_MainListeEtudiants2019 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINLISTEETUDIANTS2019_H
