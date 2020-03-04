/********************************************************************************
** Form generated from reading UI file 'fenetreclient.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENETRECLIENT_H
#define UI_FENETRECLIENT_H

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

class Ui_FenetreClient
{
public:
    QWidget *centralWidget;
    QLabel *labelEmettre;
    QLabel *labelRecu;
    QLineEdit *lineMessageEmettre;
    QLineEdit *lineMessageRecu;
    QPushButton *ButtonEmettre;
    QPushButton *ButtonTerminer;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FenetreClient)
    {
        if (FenetreClient->objectName().isEmpty())
            FenetreClient->setObjectName(QString::fromUtf8("FenetreClient"));
        FenetreClient->resize(400, 200);
        centralWidget = new QWidget(FenetreClient);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        labelEmettre = new QLabel(centralWidget);
        labelEmettre->setObjectName(QString::fromUtf8("labelEmettre"));
        labelEmettre->setGeometry(QRect(20, 20, 100, 13));
        labelRecu = new QLabel(centralWidget);
        labelRecu->setObjectName(QString::fromUtf8("labelRecu"));
        labelRecu->setGeometry(QRect(20, 110, 47, 13));
        lineMessageEmettre = new QLineEdit(centralWidget);
        lineMessageEmettre->setObjectName(QString::fromUtf8("lineMessageEmettre"));
        lineMessageEmettre->setGeometry(QRect(20, 40, 360, 20));
        lineMessageRecu = new QLineEdit(centralWidget);
        lineMessageRecu->setObjectName(QString::fromUtf8("lineMessageRecu"));
        lineMessageRecu->setGeometry(QRect(20, 130, 360, 20));
        lineMessageRecu->setReadOnly(true);
        ButtonEmettre = new QPushButton(centralWidget);
        ButtonEmettre->setObjectName(QString::fromUtf8("ButtonEmettre"));
        ButtonEmettre->setGeometry(QRect(60, 80, 80, 23));
        ButtonTerminer = new QPushButton(centralWidget);
        ButtonTerminer->setObjectName(QString::fromUtf8("ButtonTerminer"));
        ButtonTerminer->setGeometry(QRect(240, 80, 80, 23));
        FenetreClient->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FenetreClient);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        FenetreClient->setMenuBar(menuBar);
        statusBar = new QStatusBar(FenetreClient);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        FenetreClient->setStatusBar(statusBar);

        retranslateUi(FenetreClient);

        QMetaObject::connectSlotsByName(FenetreClient);
    } // setupUi

    void retranslateUi(QMainWindow *FenetreClient)
    {
        FenetreClient->setWindowTitle(QApplication::translate("FenetreClient", "Client", 0, QApplication::UnicodeUTF8));
        labelEmettre->setText(QApplication::translate("FenetreClient", "A emettre:", 0, QApplication::UnicodeUTF8));
        labelRecu->setText(QApplication::translate("FenetreClient", "Re\303\247u:", 0, QApplication::UnicodeUTF8));
        ButtonEmettre->setText(QApplication::translate("FenetreClient", "Emettre", 0, QApplication::UnicodeUTF8));
        ButtonTerminer->setText(QApplication::translate("FenetreClient", "Terminer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FenetreClient: public Ui_FenetreClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENETRECLIENT_H
