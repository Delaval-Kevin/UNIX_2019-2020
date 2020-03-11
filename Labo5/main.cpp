#include "fenetreclient.h"
#include "Ecran.h"
#include <QApplication>
#include <QTextCodec>

#include <sys/types.h>
#include <sys/msg.h>

#include "Fichier.ini"

int	idQ;
FenetreClient* w;

int main(int argc, char *argv[])
{
	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));


	if ((idQ = msgget(CLE,0)) == -1)
	{ 
		perror("\t(CLIENT) Erreur de msgget(READQUEUE)");
		exit(1);
	}

	Trace("Connexion a la file de message idQ = %d \n",idQ);

	QApplication a(argc, argv);
	w = new FenetreClient;
	w->show();

	return a.exec();
}
