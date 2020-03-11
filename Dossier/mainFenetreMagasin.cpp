/***********************************************************/
/*Auteur : COLLETTE Loic et DELAVAL Kevin                  */
/*Groupe : 2203                                            */
/*Application : Dossier Unix                               */
/*Date de la dernière mise à jour : 06/12/2019             */
/***********************************************************/

#include "MainMagasin.h"
#include <QApplication>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <string.h>
#include <signal.h>

#include "Fichier.ini"
#include "Ecran.h"

char			NomMagasin[40];
int				idQ;
MESSAGE			Message;
MainMagasin*	w;

int main(int argc, char *argv[])
{
	Trace("Debut");
	if (argc !=2)
	{
		printf("Trop ou trop peu d'argument(s)...\n");
		exit(0);
	}
	// recuperation des ressources	
	while ((idQ = msgget(CLE, 0)) == -1)
	{ 
		perror("(MAGASIN) Erreur connexion a la file de message, tentative en cours...");
		sleep(1);
	}
	printf("IdQ = %d\n",idQ);
		
	// identification du magasin
	Trace("On continue");
	strcpy(NomMagasin, argv[1]);
	
	// copie des données pour le message à envoyer
	Message.Type = 1L;
	Message.idPid = getpid();
	Message.Requete = CONNECT;
	strcpy(Message.arg.Donnee, argv[1]);

	// envoie du message
    Trace("Authentification en cours...");
	if((msgsnd(idQ, &Message, LONGMESSAGE, 0)) == -1)
	{
		perror("(MAGASIN) Erreur d'ecriture sur la file de message");
		exit(1);
	}

	QApplication a(argc, argv);
	w = new MainMagasin;
	w->show();

	return a.exec();
}
