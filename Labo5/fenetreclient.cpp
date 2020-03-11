#include "fenetreclient.h"
#include "ui_fenetreclient.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <signal.h>
#include <string.h>
#include "Fichier.ini"
#include "Ecran.h"

extern int idQ;
extern FenetreClient* w;



MESSAGE Message;

void H(int Sig);

FenetreClient::FenetreClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FenetreClient)
{
	ui->setupUi(this);
	struct sigaction Act;
	Act.sa_handler = H;
	sigemptyset(&Act.sa_mask);
	Act.sa_flags = 0;
	sigaction(SIGUSR1,&Act,NULL);
}

FenetreClient::~FenetreClient()
{
    delete ui;
}

void FenetreClient::on_ButtonEmettre_clicked()
{
	Trace("Dans on_ButtonEmettre_clicked");

	Message.Type = (long)1;
	Message.Pid = getpid();
	strcpy(Message.M, getMessageEmettre());


	if (msgsnd(idQ,&Message,strlen(Message.M) + sizeof(long),0) == -1)
	{
		perror("\t(CLIENT) Erreur d'ecriture");
		exit(1);
	}
	
	setMessageEmettre("");
}

void FenetreClient::on_ButtonTerminer_clicked()
{
   Trace("Dans on_ButtonTerminer_clicked");
	exit(1);
}

#include "fctUtiles.cpp"

void H(int Sig)
{
	Trace("Reception du nsignal %d",Sig);
	
	if (msgrcv(idQ,&Message,sizeof(Message) - sizeof(long),getpid(),0) == -1)
	{
		perror("\t(CLIENT) Erreur de lecture");
		exit(1);
	}

	w->setMessageRecu(Message.M);
}
