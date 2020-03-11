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
#include <signal.h>

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
int			pidTmp;

int main(int argc,char*argv[])
{
	Trace("(VEHICULE LIVRAISON) Debut");
	if (argc != 3)
	{
		printf("Trop ou trop peu d'argument(s)...\n");
		exit(0);
	}
	
	hpPipeEcriture = atoi(argv[2]);
	hdPipeLecture = atoi(argv[1]);
	
	// Fermeture du Pipe en ecriture
	close(hpPipeEcriture);
	
	while (1)
	{
		Trace("(VEHICULE LIVRAISON) Attente de lecture dans le pipe");
		if ((read(hdPipeLecture, &pidTmp, sizeof(int))) < 0)
		{
			perror("(VEHICULE LIVRAISON) Erreur de read Pipe");
			exit(1);		
		}
		Trace("(VEHICULE LIVRAISON) Ping 5 sec.");
		sleep(5);
		
		// envoie du signal pour aller dans le handler du magasin
	 	if(kill(pidTmp, SIGUSR2) == -1)
		{
			perror ("(VEHICULE LIVRAISON) Erreur de kill");
			exit(1);
        }		
	}
}






