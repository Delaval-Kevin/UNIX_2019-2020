/***********************************************************/
/*Auteur : COLLETTE Loic et DELAVAL Kevin                  */
/*Groupe : 2203                                            */
/*Application : Dossier Unix                               */
/*Date de la dernière mise à jour : 06/12/2019             */
/***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <time.h>
#include <string.h>

MYSQL		*Connexion;
MYSQL_RES	*Resultat;
MYSQL_ROW	Ligne;

int main(int argc,char *argv[])
{

	Connexion = mysql_init(NULL);
	mysql_real_connect(Connexion,"localhost","colletlo","Passcolletlo","Pourcolletlo",0,0,0);

// Efface les tables
	mysql_query(Connexion,"drop table MagasinBd;");
	mysql_query(Connexion,"drop table StockBd;");
	mysql_query(Connexion,"drop table ClientBd;");


// Creation de la BD MagasinBd
	mysql_query(Connexion,"create table MagasinBd (id INT(4) auto_increment primary key, Nom varchar(12),Quantite1 INT(4),Quantite2 INT(4),Quantite3 INT(4),Quantite4 INT(4),Quantite5 INT(4),Quantite6 INT(4),Quantite7 INT(4),Quantite8 INT(4),Quantite9 INT(4));");
	mysql_query(Connexion,"insert into MagasinBd values (NULL,'Central',5,5,5,5,5,5,5,5,5);");
	mysql_query(Connexion,"insert into MagasinBd values (NULL,'AAA',1,1,1,1,1,1,1,1,1);");
	mysql_query(Connexion,"insert into MagasinBd values (NULL,'BBB',1,1,1,1,1,1,1,1,1);");
	mysql_query(Connexion,"insert into MagasinBd values (NULL,'CCC',1,1,1,1,1,1,1,1,1);");
	mysql_query(Connexion,"insert into MagasinBd values (NULL,'DDD',1,1,1,1,1,1,1,1,1);");

// Creation de la BD StockBd
	mysql_query(Connexion,"create table StockBd (id INT(4) auto_increment primary key, NomArticle varchar(12),Quantite int,Image varchar(40));");
	mysql_query(Connexion,"insert into StockBd values (NULL,'Disqueuse',2,'disqueuse.jfif');");
	mysql_query(Connexion,"insert into StockBd values (NULL,'Scie',2,'scie.jfif');");
	mysql_query(Connexion,"insert into StockBd values (NULL,'Tarriere',2,'tarriere.jfif');");
	mysql_query(Connexion,"insert into StockBd values (NULL,'Foreuse 1',2,'foreuse.jfif');");
	mysql_query(Connexion,"insert into StockBd values (NULL,'Foreuse 2',2,'foreuse2.jfif');");
	mysql_query(Connexion,"insert into StockBd values (NULL,'Soufleuse',2,'soufleuse.jfif');");
	mysql_query(Connexion,"insert into StockBd values (NULL,'Tondeuse',2,'tondeuse.jfif');");
	mysql_query(Connexion,"insert into StockBd values (NULL,'Taille haie',2,'taille haie.jfif');");
	mysql_query(Connexion,"insert into StockBd values (NULL,'Tronconeuse',2,'tronconeuse.jfif');");

// Creation de la BD ClientBd
	mysql_query(Connexion,"create table ClientBd (id INT(4) auto_increment primary key, NomClient varchar(12),NumeroCompte varchar(12),ArticleLoue int,Date int);");
	exit(0);
}
