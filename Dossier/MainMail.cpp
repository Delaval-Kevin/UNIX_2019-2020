/***********************************************************/
/*Auteur : COLLETTE Loic et DELAVAL Kevin                  */
/*Groupe : 2203                                            */
/*Application : Dossier Unix                               */
/*Date de la dernière mise à jour : 06/12/2019             */
/***********************************************************/

#include "MainMail.h"
#include "ui_MainMail.h"

extern char NomClient[20];
extern char NomMagasin[20];

MainMail::MainMail(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMail)
{
	printf("--%s--\n",NomMagasin);
		ui->setupUi(this);
	ui->labelMagasin->setText(NomMagasin);
	ui->labelClient->setText(NomClient);
	ui->labelClient1->setText(NomClient);
}

MainMail::~MainMail()
{
    delete ui;
}

void MainMail::on_pushButton_clicked()
{
    exit(0);
}
