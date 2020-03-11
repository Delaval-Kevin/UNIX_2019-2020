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
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *ButtonQuiContacte;
    QPushButton *ButtonPersonnel;
    QPushButton *ButtonAContacter1;
    QPushButton *ButtonAContacter2;
    QPushButton *ButtonTerminer;
    QLabel *labelQuiContacte;
    QLabel *labelAContacter;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(300, 255);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ButtonQuiContacte = new QPushButton(centralWidget);
        ButtonQuiContacte->setObjectName(QString::fromUtf8("ButtonQuiContacte"));
        ButtonQuiContacte->setGeometry(QRect(90, 10, 120, 40));
        ButtonPersonnel = new QPushButton(centralWidget);
        ButtonPersonnel->setObjectName(QString::fromUtf8("ButtonPersonnel"));
        ButtonPersonnel->setGeometry(QRect(90, 80, 120, 40));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        ButtonPersonnel->setFont(font);
        ButtonAContacter1 = new QPushButton(centralWidget);
        ButtonAContacter1->setObjectName(QString::fromUtf8("ButtonAContacter1"));
        ButtonAContacter1->setGeometry(QRect(20, 150, 120, 40));
        ButtonAContacter2 = new QPushButton(centralWidget);
        ButtonAContacter2->setObjectName(QString::fromUtf8("ButtonAContacter2"));
        ButtonAContacter2->setGeometry(QRect(160, 150, 120, 40));
        ButtonTerminer = new QPushButton(centralWidget);
        ButtonTerminer->setObjectName(QString::fromUtf8("ButtonTerminer"));
        ButtonTerminer->setGeometry(QRect(200, 200, 80, 23));
        labelQuiContacte = new QLabel(centralWidget);
        labelQuiContacte->setObjectName(QString::fromUtf8("labelQuiContacte"));
        labelQuiContacte->setGeometry(QRect(90, 60, 120, 15));
        labelAContacter = new QLabel(centralWidget);
        labelAContacter->setObjectName(QString::fromUtf8("labelAContacter"));
        labelAContacter->setGeometry(QRect(90, 130, 120, 15));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Personnes \303\240 contacter.", 0, QApplication::UnicodeUTF8));
        ButtonQuiContacte->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        ButtonPersonnel->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        ButtonAContacter1->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        ButtonAContacter2->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        ButtonTerminer->setText(QApplication::translate("MainWindow", "Terminer", 0, QApplication::UnicodeUTF8));
        labelQuiContacte->setText(QApplication::translate("MainWindow", "Qui contacte :", 0, QApplication::UnicodeUTF8));
        labelAContacter->setText(QApplication::translate("MainWindow", "A contacter:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
