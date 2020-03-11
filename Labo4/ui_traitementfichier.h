/********************************************************************************
** Form generated from reading UI file 'traitementfichier.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAITEMENTFICHIER_H
#define UI_TRAITEMENTFICHIER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TraitementFichier
{
public:
    QWidget *centralWidget;
    QLabel *labelNomFich;
    QLineEdit *lineEdit;
    QLineEdit *lineTraitement;
    QLabel *labelTraitement;
    QLineEdit *lineNbTraitement;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TraitementFichier)
    {
        if (TraitementFichier->objectName().isEmpty())
            TraitementFichier->setObjectName(QString::fromUtf8("TraitementFichier"));
        TraitementFichier->resize(390, 140);
        centralWidget = new QWidget(TraitementFichier);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        labelNomFich = new QLabel(centralWidget);
        labelNomFich->setObjectName(QString::fromUtf8("labelNomFich"));
        labelNomFich->setGeometry(QRect(20, 10, 91, 16));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 10, 113, 20));
        lineEdit->setReadOnly(true);
        lineTraitement = new QLineEdit(centralWidget);
        lineTraitement->setObjectName(QString::fromUtf8("lineTraitement"));
        lineTraitement->setGeometry(QRect(20, 80, 350, 20));
        lineTraitement->setReadOnly(true);
        labelTraitement = new QLabel(centralWidget);
        labelTraitement->setObjectName(QString::fromUtf8("labelTraitement"));
        labelTraitement->setGeometry(QRect(80, 50, 250, 16));
        lineNbTraitement = new QLineEdit(centralWidget);
        lineNbTraitement->setObjectName(QString::fromUtf8("lineNbTraitement"));
        lineNbTraitement->setGeometry(QRect(20, 50, 50, 20));
        lineNbTraitement->setReadOnly(true);
        TraitementFichier->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TraitementFichier);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 390, 21));
        TraitementFichier->setMenuBar(menuBar);
        statusBar = new QStatusBar(TraitementFichier);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TraitementFichier->setStatusBar(statusBar);

        retranslateUi(TraitementFichier);

        QMetaObject::connectSlotsByName(TraitementFichier);
    } // setupUi

    void retranslateUi(QMainWindow *TraitementFichier)
    {
        TraitementFichier->setWindowTitle(QApplication::translate("TraitementFichier", "Traitement du Groupe", 0, QApplication::UnicodeUTF8));
        labelNomFich->setText(QApplication::translate("TraitementFichier", "Groupe Trait\303\251:", 0, QApplication::UnicodeUTF8));
        labelTraitement->setText(QApplication::translate("TraitementFichier", "\303\250me \303\251tudiant en cours de Traitement.", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TraitementFichier: public Ui_TraitementFichier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAITEMENTFICHIER_H
