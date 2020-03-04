#include "MainListeEtudiants2019.h"
#include "ui_MainListeEtudiants2019.h"

#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>

#include "Ecran.h"

MainListeEtudiants2019::MainListeEtudiants2019(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainListeEtudiants2019)
{
Trace("Debut de l'appic.");
ui->setupUi(this);
struct sigaction Act;
Act.sa_handler = SIG_DFL;
sigaction(SIGCHLD,&Act,NULL);
}

MainListeEtudiants2019::~MainListeEtudiants2019()
{
delete ui;
}

void MainListeEtudiants2019::on_ButtonOk_clicked()
{
Trace("Dans Ok.");
Trace("Groupe 1 : %s",getGroupe1());
Trace("Groupe 2 : %s",getGroupe2());
Trace("Groupe 3 : %s",getGroupe3());

pid_t IdFils1;
pid_t IdFils2;
pid_t IdFils3;
int 	Statut1;
int 	Statut2;
int 	Statut3;

	if ((IdFils1 = fork()) == -1)
	{ 
		perror("(CreationFils1) Err de fork");
		exit(1);
	}
	if (IdFils1)
	{ // processus pere
		wait(&Statut1);
		setNbEtud1(WEXITSTATUS(Statut1));
	}
	else
	{// processus fils
		exit(execl("Lect","Lect", getGroupe1(), NULL));
	}
	
	if ((IdFils2 = fork()) == -1)
	{ 
		perror("(CreationFils2) Err de fork");
		exit(1);
	}
	if (IdFils2)
	{ // processus pere
		wait(&Statut2);
		setNbEtud2(WEXITSTATUS(Statut2));
	}
	else
	{// processus fils
		exit(execl("Lect","Lect", getGroupe2(), NULL));
	}
	
	if ((IdFils3 = fork()) == -1)
	{ 
		perror("(CreationFils3) Err de fork");
		exit(1);
	}
	if (IdFils3)
	{ // processus pere
		wait(&Statut3);
		setNbEtud3(WEXITSTATUS(Statut3));
	}
	else
	{// processus fils
		exit(execl("Lect","Lect", getGroupe3(), NULL));
	}
}
	
	

void MainListeEtudiants2019::on_ButtonEffacer_clicked()
{
Trace("Dans Effacer.");
setGroupe1("");
setNbEtud1(-1);
setGroupe2("");
setNbEtud2(-1);
setGroupe3("");
setNbEtud3(-1);
}

void MainListeEtudiants2019::on_ButtonTerminer_clicked()
{
Trace("Dans Terminer.");
exit(0);
}

#include "fctUtiles.cpp"
