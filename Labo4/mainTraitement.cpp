#include "traitementfichier.h"
#include <QApplication>
char	Nom[30];
int	Colonne;
int	idGrp;
TraitementFichier* w;

int main(int argc, char *argv[])
{
	strcpy(Nom,argv[1]);
	Colonne = atoi(argv[2]);
//	idGrp = atoi(argv[3]);
	QApplication a(argc, argv);
	w = new TraitementFichier;
	w->show();

   return a.exec();
}
