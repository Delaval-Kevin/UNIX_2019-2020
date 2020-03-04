#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Ecran.h"
#include "Fichier.dat"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{	 
    ui->setupUi(this);
    setNom(Elem->Nom);
    setMail(Elem->Mail);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ButtonPrecedent_clicked()
{
	if((Elem-1)->id!=0)
	{
		Elem--;
    	setNom(Elem->Nom);
    	setMail(Elem->Mail);
   }
	Trace("ButtonPrecedent");
}

void MainWindow::on_ButtonSuivant_clicked()
{
	if((Elem+1)->id!=0)
	{
		Elem++;
    	setNom(Elem->Nom);
   	setMail(Elem->Mail);
   }
	Trace("ButtonSuivant");
}

void MainWindow::on_ButtonTerminer_clicked()
{
	Trace("ButtonTerminer");
	exit(0);

}

#include "fctUtiles.cpp"
