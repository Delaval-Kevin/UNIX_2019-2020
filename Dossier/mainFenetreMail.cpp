/***********************************************************/
/*Auteur : COLLETTE Loic et DELAVAL Kevin                  */
/*Groupe : 2203                                            */
/*Application : Dossier Unix                               */
/*Date de la dernière mise à jour : 06/12/2019             */
/***********************************************************/

#include "MainMail.h"
#include <QApplication>
#include <stdio.h>
#include <string.h>

char	NomClient[20];
char	NomMagasin[20];

int main(int argc, char *argv[])
{
	if (argc != 3)
	{ 
		exit(1);
	}
	
	strcpy(NomClient,argv[1]);
	strcpy(NomMagasin,argv[2]);
	printf("Debut\n");
    QApplication a(argc, argv);
    MainMail w;
    w.show();

    return a.exec();
}
