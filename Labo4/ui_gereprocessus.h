/********************************************************************************
** Form generated from reading UI file 'gereprocessus.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GEREPROCESSUS_H
#define UI_GEREPROCESSUS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GereProcessus
{
public:
    QWidget *centralWidget;
    QLabel *label1;
    QLabel *labelNom1;
    QLabel *labelNb1;
    QLabel *label2;
    QLabel *labelNom2;
    QLabel *labelNb2;
    QLabel *label3;
    QLabel *labelNom3;
    QLabel *labelNb3;
    QLineEdit *lineNomGroupe1;
    QLineEdit *lineNbEtud1;
    QLineEdit *lineNomGroupe2;
    QLineEdit *lineNbEtud2;
    QLineEdit *lineNomGroupe3;
    QLineEdit *lineNbEtud3;
    QPushButton *ButtonTerminer1;
    QPushButton *ButtonTerminer2;
    QPushButton *ButtonTerminer3;
    QPushButton *ButtonGo;
    QPushButton *ButtonEffacer;
    QPushButton *ButtonTerminer;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GereProcessus)
    {
        if (GereProcessus->objectName().isEmpty())
            GereProcessus->setObjectName(QString::fromUtf8("GereProcessus"));
        GereProcessus->resize(420, 300);
        centralWidget = new QWidget(GereProcessus);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label1 = new QLabel(centralWidget);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setGeometry(QRect(20, 20, 150, 13));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label1->setFont(font);
        labelNom1 = new QLabel(centralWidget);
        labelNom1->setObjectName(QString::fromUtf8("labelNom1"));
        labelNom1->setGeometry(QRect(20, 40, 150, 13));
        labelNb1 = new QLabel(centralWidget);
        labelNb1->setObjectName(QString::fromUtf8("labelNb1"));
        labelNb1->setGeometry(QRect(20, 65, 150, 13));
        label2 = new QLabel(centralWidget);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(20, 90, 150, 13));
        label2->setFont(font);
        labelNom2 = new QLabel(centralWidget);
        labelNom2->setObjectName(QString::fromUtf8("labelNom2"));
        labelNom2->setGeometry(QRect(20, 110, 150, 13));
        labelNb2 = new QLabel(centralWidget);
        labelNb2->setObjectName(QString::fromUtf8("labelNb2"));
        labelNb2->setGeometry(QRect(20, 135, 150, 13));
        label3 = new QLabel(centralWidget);
        label3->setObjectName(QString::fromUtf8("label3"));
        label3->setGeometry(QRect(20, 160, 150, 13));
        label3->setFont(font);
        labelNom3 = new QLabel(centralWidget);
        labelNom3->setObjectName(QString::fromUtf8("labelNom3"));
        labelNom3->setGeometry(QRect(20, 180, 150, 13));
        labelNb3 = new QLabel(centralWidget);
        labelNb3->setObjectName(QString::fromUtf8("labelNb3"));
        labelNb3->setGeometry(QRect(20, 205, 150, 13));
        lineNomGroupe1 = new QLineEdit(centralWidget);
        lineNomGroupe1->setObjectName(QString::fromUtf8("lineNomGroupe1"));
        lineNomGroupe1->setGeometry(QRect(180, 40, 120, 20));
        lineNbEtud1 = new QLineEdit(centralWidget);
        lineNbEtud1->setObjectName(QString::fromUtf8("lineNbEtud1"));
        lineNbEtud1->setGeometry(QRect(180, 65, 50, 20));
        lineNbEtud1->setReadOnly(true);
        lineNomGroupe2 = new QLineEdit(centralWidget);
        lineNomGroupe2->setObjectName(QString::fromUtf8("lineNomGroupe2"));
        lineNomGroupe2->setGeometry(QRect(180, 110, 120, 20));
        lineNbEtud2 = new QLineEdit(centralWidget);
        lineNbEtud2->setObjectName(QString::fromUtf8("lineNbEtud2"));
        lineNbEtud2->setGeometry(QRect(180, 135, 50, 20));
        lineNbEtud2->setReadOnly(true);
        lineNomGroupe3 = new QLineEdit(centralWidget);
        lineNomGroupe3->setObjectName(QString::fromUtf8("lineNomGroupe3"));
        lineNomGroupe3->setGeometry(QRect(180, 180, 120, 20));
        lineNbEtud3 = new QLineEdit(centralWidget);
        lineNbEtud3->setObjectName(QString::fromUtf8("lineNbEtud3"));
        lineNbEtud3->setGeometry(QRect(180, 205, 50, 20));
        lineNbEtud3->setReadOnly(true);
        ButtonTerminer1 = new QPushButton(centralWidget);
        ButtonTerminer1->setObjectName(QString::fromUtf8("ButtonTerminer1"));
        ButtonTerminer1->setGeometry(QRect(315, 40, 85, 23));
        ButtonTerminer2 = new QPushButton(centralWidget);
        ButtonTerminer2->setObjectName(QString::fromUtf8("ButtonTerminer2"));
        ButtonTerminer2->setGeometry(QRect(315, 110, 85, 23));
        ButtonTerminer3 = new QPushButton(centralWidget);
        ButtonTerminer3->setObjectName(QString::fromUtf8("ButtonTerminer3"));
        ButtonTerminer3->setGeometry(QRect(315, 180, 85, 23));
        ButtonGo = new QPushButton(centralWidget);
        ButtonGo->setObjectName(QString::fromUtf8("ButtonGo"));
        ButtonGo->setGeometry(QRect(20, 230, 85, 23));
        ButtonEffacer = new QPushButton(centralWidget);
        ButtonEffacer->setObjectName(QString::fromUtf8("ButtonEffacer"));
        ButtonEffacer->setGeometry(QRect(110, 230, 85, 23));
        ButtonTerminer = new QPushButton(centralWidget);
        ButtonTerminer->setObjectName(QString::fromUtf8("ButtonTerminer"));
        ButtonTerminer->setGeometry(QRect(315, 230, 85, 23));
        GereProcessus->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GereProcessus);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 420, 21));
        GereProcessus->setMenuBar(menuBar);
        statusBar = new QStatusBar(GereProcessus);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GereProcessus->setStatusBar(statusBar);

        retranslateUi(GereProcessus);

        QMetaObject::connectSlotsByName(GereProcessus);
    } // setupUi

    void retranslateUi(QMainWindow *GereProcessus)
    {
        GereProcessus->setWindowTitle(QApplication::translate("GereProcessus", "Gere \303\251tudiants.", 0, QApplication::UnicodeUTF8));
        label1->setText(QApplication::translate("GereProcessus", "Premier processus :", 0, QApplication::UnicodeUTF8));
        labelNom1->setText(QApplication::translate("GereProcessus", "Groupe \303\240 traiter:", 0, QApplication::UnicodeUTF8));
        labelNb1->setText(QApplication::translate("GereProcessus", "Nb d'\303\251tudiants trait\303\251s :", 0, QApplication::UnicodeUTF8));
        label2->setText(QApplication::translate("GereProcessus", "Deuxi\303\250me processus :", 0, QApplication::UnicodeUTF8));
        labelNom2->setText(QApplication::translate("GereProcessus", "Groupe \303\240 traiter:", 0, QApplication::UnicodeUTF8));
        labelNb2->setText(QApplication::translate("GereProcessus", "Nb d'\303\251tudiants trait\303\251s :", 0, QApplication::UnicodeUTF8));
        label3->setText(QApplication::translate("GereProcessus", "Troisi\303\250me processus :", 0, QApplication::UnicodeUTF8));
        labelNom3->setText(QApplication::translate("GereProcessus", "Groupe \303\240 traiter:", 0, QApplication::UnicodeUTF8));
        labelNb3->setText(QApplication::translate("GereProcessus", "Nb d'\303\251tudiants trait\303\251s :", 0, QApplication::UnicodeUTF8));
        ButtonTerminer1->setText(QApplication::translate("GereProcessus", "Annuler", 0, QApplication::UnicodeUTF8));
        ButtonTerminer2->setText(QApplication::translate("GereProcessus", "Annuler", 0, QApplication::UnicodeUTF8));
        ButtonTerminer3->setText(QApplication::translate("GereProcessus", "Annuler", 0, QApplication::UnicodeUTF8));
        ButtonGo->setText(QApplication::translate("GereProcessus", "Go", 0, QApplication::UnicodeUTF8));
        ButtonEffacer->setText(QApplication::translate("GereProcessus", "Effacer", 0, QApplication::UnicodeUTF8));
        ButtonTerminer->setText(QApplication::translate("GereProcessus", "Terminer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GereProcessus: public Ui_GereProcessus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GEREPROCESSUS_H
