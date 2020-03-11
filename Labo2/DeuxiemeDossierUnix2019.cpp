#include "DeuxiemeDossierUnix2019.h"
#include "ui_DeuxiemeDossierUnix2019.h"
#include <QMessageBox>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include "Ecran.h"
#include "Donnee.dat"

int             Pos = 0;
bool Modification = false;

MainDeuxiemeDossierUnix2019::MainDeuxiemeDossierUnix2019(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainDeuxiemeDossierUnix2019)
{
	int hdF,i=0;

	hdF = open("G2205.dat",O_RDONLY);
	if(hdF != -1)
	{
		while(Elm[i].AnneeNaissance != 0)
		{
			read(hdF,&Elm[i],sizeof(ELEMENT));
			i++;
		}
		::close(hdF);
	}
		ui->setupUi(this);
		setNom(Elm[Pos].Nom);
		setAnneeNaissance(Elm[Pos].AnneeNaissance);
		setFichierImage(Elm[Pos].AdrImage);
		setAdresseMail(Elm[Pos].Mail);
		setImage(Elm[Pos].AdrImage);	
}

MainDeuxiemeDossierUnix2019::~MainDeuxiemeDossierUnix2019()
{
    delete ui;
}

void MainDeuxiemeDossierUnix2019::on_ButtonPrecedent_clicked()
{
	if(Pos!=0)
	{
		Pos--;
		setNom(Elm[Pos].Nom);
		setAnneeNaissance(Elm[Pos].AnneeNaissance);
		setFichierImage(Elm[Pos].AdrImage);
		setAdresseMail(Elm[Pos].Mail);
		setImage(Elm[Pos].AdrImage);
   }
	Trace("Dans Precedent %d",Pos);
	return;
}

void MainDeuxiemeDossierUnix2019::on_ButtonSuivant_clicked()
{
	if(Elm[Pos+1].AnneeNaissance!=0)
	{
		Pos++;
		setNom(Elm[Pos].Nom);
		setAnneeNaissance(Elm[Pos].AnneeNaissance);
		setFichierImage(Elm[Pos].AdrImage);
		setAdresseMail(Elm[Pos].Mail);
		setImage(Elm[Pos].AdrImage);
   }
	Trace("Dans Suivant %d",Pos);
	return;
}

void MainDeuxiemeDossierUnix2019::on_ButtonModifier_clicked()
{
	Trace("Dans Modifier");
	if (Modification)
		{setImage(getFichierImage());
		if (MessageConfirmation("Modification","Enregistrement va être modifier\nConfirmer..."))
		{ 
			Trace("Ok");
			strcpy(Elm[Pos].Mail,getAdresseMail());
			strcpy(Elm[Pos].AdrImage,getFichierImage());
			Modification = true;
			setTextModifier("Modifier");
			return;
		}
		Trace("Faux");
	}
	Modification = true;
	setTextModifier("Continuer");
	return;
}

void MainDeuxiemeDossierUnix2019::on_ButtonTerminer_clicked()
{
	Trace("Dans Terminer");
	if (Modification)
		{	 
		if (MessageConfirmation("Terminer","Modification en cours\nEnregistrer...")) 
			{
				Trace("Ok");
				int hdF,i=0;
				
				hdF = open("G2205.dat",O_CREAT | O_TRUNC | O_WRONLY, 0644);
				while(Elm[i].AnneeNaissance != 0)
				{
					write(hdF,&Elm[i],sizeof(ELEMENT));
					i++;
				}
				::close(hdF);
			}
		else 
			{
				Trace("Faux");
			}
		}
	exit(0);
}

#include "fctUtiles.cpp"
