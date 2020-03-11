/***********************************************************/
/*Auteur : COLLETTE Loic et DELAVAL Kevin                  */
/*Groupe : 2203                                            */
/*Application : Dossier Unix                               */
/*Date de la dernière mise à jour : 06/12/2019             */
/***********************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <string.h>
#include <signal.h>
#include <mysql.h>
#include <time.h>
#include <string.h>

MYSQL		*Connexion;
MYSQL_RES	*Resultat;
MYSQL_ROW	Ligne;


#include "Ecran.h"
#include "Fichier.ini"

TABLEAU		*Tab;
int			idQ;
MESSAGE		Message;
char		Buff[255];


int main(int argc,char*argv[])
{
	srand(time(NULL));
	
	int montant;
	
	// recuperation des ressources	
	while ((idQ = msgget(CLE, 0)) == -1)
	{ 
		perror("(SERVICE FACTURATION) Erreur connexion a la file de message, tentative en cours...");
	}
	printf("IdQ = %d\n",idQ);
	
	while(1)
	{	
		Trace("(SERVICE FACTURATION) En attente d'un message...");
		// Reception du message
		if((msgrcv(idQ, &Message, LONGMESSAGE, getpid(), 0)) == -1)
		{
		    perror("(SERVICE FACTURATION) Erreur de lecture sur la file de message");
		    exit(1);
		}	
		
		montant = (rand()%50) * (rand()%5);
		sprintf(Buff, "La somme de %d euro vous sera debitee", montant);
			
		if(kill(Message.Requete, SIGUSR1) == -1)
	    {
	       	perror ("(SERVICE FACTURATION) Erreur de kill CONNECT");
			exit(1);
		}
			
		Message.Type = Message.Requete;
		Message.idPid = getpid();
		Message.Requete = RETOURARTICLE;
		strcpy(Message.arg.Donnee, Buff);
		// envoie du message pour le ServiceFacturation
		if(msgsnd(idQ, &Message, LONGMESSAGE, 0) == -1)
		{
			perror("(SERVICE FACTURATION) Erreur d'envoie du message RETOURARTICLE");
		}
	}
	

}
