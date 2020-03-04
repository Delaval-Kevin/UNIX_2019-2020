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
int			hpPipeEcriture;
int			hdPipeLecture;


int main(int argc,char*argv[])
{
	Trace("(SERVICE LIVRAISON) Debut");
	if (argc != 3)
	{
		printf("Trop ou trop peu d'argument(s)...\n");
		exit(0);
	}
	
	hpPipeEcriture = atoi(argv[2]);
	hdPipeLecture = atoi(argv[1]);
	
	// Fermeture du Pipe en lecture
	close(hdPipeLecture);
	
	// Connection a la file de message
	while ((idQ = msgget(CLE, 0)) == -1)
	{ 
		perror("(SERVICE LIVRAISON) Erreur connexion a la file de message, tentative en cours...");
	}
	printf("IdQ = %d\n",idQ);
	
	while(1)
	{	
		Trace("(SERVICE LIVRAISON) En attente d'un message...");
		// Reception du message
		if((msgrcv(idQ, &Message, LONGMESSAGE, getpid(), 0)) == -1)
		{
		    perror("(SERVICE LIVRAISON) Erreur de lecture sur la file de message");
		    exit(1);
		}	
		
		if(write(hpPipeEcriture, &Message.Requete, sizeof(int)) != sizeof(int))
		{
			perror("(SERVICE LIVRAISON) Erreur de write dans le Pipe");
			exit(1);
		}
		
	}	
}
