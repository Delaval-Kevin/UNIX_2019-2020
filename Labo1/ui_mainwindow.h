/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *labelNom;
    QLabel *labelMail;
    QLineEdit *lineNom;
    QLineEdit *lineMail;
    QPushButton *ButtonPrecedent;
    QPushButton *ButtonSuivant;
    QPushButton *ButtonTerminer;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(340, 160);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        labelNom = new QLabel(centralWidget);
        labelNom->setObjectName(QString::fromUtf8("labelNom"));
        labelNom->setGeometry(QRect(80, 40, 47, 13));
        labelMail = new QLabel(centralWidget);
        labelMail->setObjectName(QString::fromUtf8("labelMail"));
        labelMail->setGeometry(QRect(80, 80, 47, 13));
        lineNom = new QLineEdit(centralWidget);
        lineNom->setObjectName(QString::fromUtf8("lineNom"));
        lineNom->setGeometry(QRect(150, 40, 113, 20));
        lineNom->setReadOnly(true);
        lineMail = new QLineEdit(centralWidget);
        lineMail->setObjectName(QString::fromUtf8("lineMail"));
        lineMail->setGeometry(QRect(150, 80, 113, 20));
        lineMail->setReadOnly(true);
        ButtonPrecedent = new QPushButton(centralWidget);
        ButtonPrecedent->setObjectName(QString::fromUtf8("ButtonPrecedent"));
        ButtonPrecedent->setGeometry(QRect(20, 60, 40, 23));
        ButtonSuivant = new QPushButton(centralWidget);
        ButtonSuivant->setObjectName(QString::fromUtf8("ButtonSuivant"));
        ButtonSuivant->setGeometry(QRect(280, 60, 40, 23));
        ButtonTerminer = new QPushButton(centralWidget);
        ButtonTerminer->setObjectName(QString::fromUtf8("ButtonTerminer"));
        ButtonTerminer->setGeometry(QRect(240, 115, 80, 23));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Premier Dossier Unix", 0, QApplication::UnicodeUTF8));
        labelNom->setText(QApplication::translate("MainWindow", "Nom :", 0, QApplication::UnicodeUTF8));
        labelMail->setText(QApplication::translate("MainWindow", "Mail:", 0, QApplication::UnicodeUTF8));
        ButtonPrecedent->setText(QApplication::translate("MainWindow", "<<", 0, QApplication::UnicodeUTF8));
        ButtonSuivant->setText(QApplication::translate("MainWindow", ">>", 0, QApplication::UnicodeUTF8));
        ButtonTerminer->setText(QApplication::translate("MainWindow", "Terminer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
