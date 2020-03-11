#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <time.h>
#include <string.h>

MYSQL			*Connexion;
MYSQL_RES	*Resultat;
MYSQL_ROW	Ligne;
int main(int argc,char *argv[])
{
char		Buff[256];

if (argc != 2) 
	{
	printf("Err.: Trop ou trop peu d\'argument(s)...\n");
	exit(1);
	}
Connexion = mysql_init(NULL);
mysql_real_connect(Connexion,"localhost","student","PassStudent","PourStudent",0,0,0);
mysql_query(Connexion,"create table Bd2019 (id INT(4) auto_increment primary key, Nom varchar(12),Groupe varchar(8));");
int i;
char	G[80],N[80];
FILE * hf= fopen(argv[1],"r");
while (fgets(Buff,255,hf))
	{
	Buff[6] = 0;
	strcpy(N,Buff);
	i = 7;
	while (Buff[i] != 'g') i++;
	strcpy(G,&Buff[i]);
	G[5] = 0;
	printf("--%s--%s--\n",N,G);
	sprintf(Buff,"insert into Bd2019 values (NULL,'%s','%s');",N,G);

	mysql_query(Connexion,Buff);
	}
exit(0);
}
