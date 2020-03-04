#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mysql.h>
#include <string.h>

MYSQL			*Connexion;
MYSQL_RES	*Resultat;
MYSQL_ROW	Ligne;

#include "Ecran.h"

int main(int argc,char*argv[])
{
Trace("Debut pour le groupe %s",argv[1]);
//int Cpt = 0;
char 	Buff[255];
if (argc != 2) 
	{
	printf("Err.: Trop ou trop peu d\'argument(s)...\n");
	exit(1);
	}
Connexion = mysql_init(NULL);
mysql_real_connect(Connexion,"localhost","student","PassStudent","PourStudent",0,0,0);
sprintf(Buff,"select count(*) from Bd2019 where Groupe = '%s'",argv[1]);
mysql_query(Connexion,Buff);
Resultat = mysql_store_result(Connexion);
Ligne = mysql_fetch_row(Resultat);
Trace("(%d) sort du  fichier %s  (%d)",getpid(),argv[1],atoi(Ligne[0]));
exit(atoi(Ligne[0]));
}
