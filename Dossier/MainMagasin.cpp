/***********************************************************/
/*Auteur : COLLETTE Loic et DELAVAL Kevin                  */
/*Groupe : 2203                                            */
/*Application : Dossier Unix                               */
/*Date de la dernière mise à jour : 06/12/2019             */
/***********************************************************/

#include "MainMagasin.h"
#include "ui_MainMagasin.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <string.h>
#include <signal.h>
#include "Ecran.h"
#include "Fichier.ini"
#include "fctUtilesMagasin.cpp"

extern	MainMagasin		*w;
extern 	char			NomMagasin[40];
extern	int				idQ;
extern MESSAGE			Message;
ARTICLE					ArtTemp[4];
RESCLIENT				*pTete;
int						Selection;
int						Choix;
struct sigaction		SigAction1;
struct sigaction		SigAction2;

void HandlerSigUsr1(int);
void HandlerSigUsr2(int);
bool pileVide();
void insererRes();
int supprimerRes();
bool verifMail();

bool Identification	= false;
bool Loc			= false;
bool Transaction	= false;
bool Res			= false;
bool Mail			= false;
bool Fact			= false;

MainMagasin::MainMagasin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMagasin)
{
	char	Buff[40];
	pTete = NULL;
	
    ui->setupUi(this);
    sprintf(Buff,"Magasin %s",NomMagasin);
    setWindowTitle(Buff);
    Trace("Debut de magasin");
    
	// Armement des signaux
	SigAction1.sa_handler = HandlerSigUsr1;
	sigemptyset(&SigAction1.sa_mask);
	SigAction1.sa_flags = 0;
	if(sigaction(SIGUSR1,&SigAction1,NULL))
	{
		perror("(MAGASIN) Erreur d'armement du signal SIGUSR1");
		exit(1);
	}
	SigAction2.sa_handler = HandlerSigUsr2;
	sigemptyset(&SigAction2.sa_mask);
	SigAction2.sa_flags = 0;
	if(sigaction(SIGUSR2,&SigAction2,NULL))
	{
		perror("(MAGASIN) Erreur d'armement du signal SIGUSR2");
		exit(1);
	}

	
	// Reception du message si pas de signal
	if((msgrcv(idQ, &Message, LONGMESSAGE, getpid(), 0)) == -1)
	{
        perror("(MAGASIN) Erreur de lecture sur la file de message");
        exit(1);
	}
	
	// Affichage de 4 premier articles
	Selection = Message.arg.Art[0].id;
	setArticle1(Message.arg.Art[0].NomArticle);
	setArticle2(Message.arg.Art[1].NomArticle);
	setArticle3(Message.arg.Art[2].NomArticle);
	setArticle4(Message.arg.Art[3].NomArticle);
	setImage(Message.arg.Art[0].Image);
	
	// Copie des articles dans le tableau ArtTemp
	for(int i = 0; i < 4 ; i++)
	{
		ArtTemp[i].id = Message.arg.Art[i].id;
		strcpy(ArtTemp[i].NomArticle, Message.arg.Art[i].NomArticle);
		strcpy(ArtTemp[i].Image, Message.arg.Art[i].Image);
	}
	
	setTextBoutonValider("Valider");
	setTextBoutonQuitter(" ");
}

MainMagasin::~MainMagasin()
{
    delete ui;
}

void MainMagasin::on_ButtonPrecedent_clicked()
{
	Trace("dans ButtonPrecedent");
	// copie des données pour le message à envoyer
	if(!Fact && !Mail)
	{
		Message.Type = 1L;
		Message.idPid = getpid();
		Message.Requete = LECTURESTOCK;
		Message.arg.Numero = (ArtTemp[0].id - 5);

		// envoie du message
		Trace("(MAGASIN demande de stock precedent)");
		if((msgsnd(idQ, &Message, LONGMESSAGE, 0)) == -1)
		{
			perror("(MAGASIN) Erreur d'ecriture sur la file de message");
			exit(1);
		}
		if(Res)
		{
			Res = false;
			setTextBoutonValider("Louer");
			setInfo("");
		}
		if(!Loc)
		{
			setInfo("");
		}
	}
	return;
}

void MainMagasin::on_ButtonSuivant_clicked()
{
	Trace("dans ButtonSuivant");
	// copie des données pour le message à envoyer
	if(!Fact && !Mail)
	{
		Message.Type = 1L;
		Message.idPid = getpid();
		Message.Requete = LECTURESTOCK;
		Message.arg.Numero = ArtTemp[3].id;

		// envoie du message
		Trace("(MAGASIN demande de stock suivant)");
		if((msgsnd(idQ, &Message, LONGMESSAGE, 0)) == -1)
		{
			perror("(MAGASIN) Erreur d'ecriture sur la file de message");
			exit(1);
		}
		if(Res)
		{
			Res = false;
			setTextBoutonValider("Louer");
			setInfo("");
		}
		if(!Loc)
		{
			setInfo("");
		}
	}
	return;
}

void MainMagasin::on_ButtonValider_clicked()
{
	Trace("dans Valider %d",Transaction);
	if(!Fact)
	{
		if (!Transaction)
		{
			if (!Identification)
			{
				if(getClient() != NULL)
				{
					// recuperation du nom du client qui vient d'arriver
					Message.Type = 1L;
					Message.idPid = getpid();
					Message.Requete = CLIENT;
					strcpy(Message.arg.Donnee, getClient());
					if((msgsnd(idQ, &Message, LONGMESSAGE, 0)) == -1)
					{
						perror("(MAGASIN) Erreur d'ecriture sur la file de message");
						exit(1);
					}
					Identification = true;	
				}
				return;
			}
			if(getNumCompte() != NULL)
			{		
				Trace("Emission du n compte");
				// c'est un nouveau client car son n° de compte n'est pas connu
				Message.Type = 1L;
				Message.idPid = getpid();
				Message.Requete = NUMEROCOMPTE;
				strcpy(Message.arg.Donnee, getNumCompte());
				if((msgsnd(idQ, &Message, LONGMESSAGE, 0)) == -1)
				{
					perror("(MAGASIN) Erreur d'ecriture sur la file de message");
					exit(1);
				}
			}
			return;
		}

		// cas de la transaction
		if (!Loc)
		{
			if(Mail)
			{
				// prendre l'article arrive 
				Message.Type = 1L;
				Message.idPid = getpid();
				Message.Requete = RESERVATIONOK;
				Message.arg.Numero = supprimerRes();
				if((msgsnd(idQ, &Message, LONGMESSAGE, 0)) == -1)
				{
					perror("(MAGASIN) Erreur d'ecriture sur la file de message");
					exit(1);
				}
				Mail = false;
				Loc = true;
				Res = false;
				setTextBoutonValider("Rendre");
				setTextBoutonQuitter("Quitter");	
				setInfo("Article emporte");
				return;		
			}
			if(Res)
			{
				// reservation d'article
				Message.Type = 1L;
				Message.idPid = getpid();
				Message.Requete = RESERVATION;
				Message.arg.Numero = Selection;
				if((msgsnd(idQ, &Message, LONGMESSAGE, 0)) == -1)
				{
					perror("(MAGASIN) Erreur d'ecriture sur la file de message");
					exit(1);
				}		
				return;		
			}
			// pas de retour
			Message.Type = 1L;
			Message.idPid = getpid();
			Message.Requete = LOCATION;
			Message.arg.Numero = Selection;
			if((msgsnd(idQ, &Message, LONGMESSAGE, 0)) == -1)
			{
				perror("(MAGASIN) Erreur d'ecriture sur la file de message");
				exit(1);
			}		
			return;
		}
		// cas du retour 
		Message.Type = 1L;
		Message.idPid = getpid();
		Message.Requete = RETOURARTICLE;
		if((msgsnd(idQ, &Message, LONGMESSAGE, 0)) == -1)
		{
			perror("(MAGASIN) Erreur d'ecriture sur la file de message");
			exit(1);
		}	
		return;
	}
	else
	{
		Fact = false;
		if(verifMail())
		{
			char Buff[40];
			RESCLIENT *tmp;
			tmp = pTete;
			//recherche du client pour l'article
			while(strcmp(tmp->nomClient,w->getClient()) != 0)
			{
				tmp = tmp->pSuiv;
			}
			w->setTextBoutonValider("Prendre");
			w->setTextBoutonQuitter("Laisser");
			sprintf(Buff,"Votre article id %d est arrive",tmp->idArt);
			w->setInfo(Buff);
			Mail = true;
		}
		else
		{
			w->setTextBoutonValider("Louer");
			w->setTextBoutonQuitter("Quitter");
			w->setInfo("");
		}
	}
}

void MainMagasin::on_ButtonQuitter_clicked()
{
	Trace("dans ButtonQuitter");
	if(!Fact)
	{
		if(Mail)
		{
			// prendre l'article arrive 
			Message.Type = 1L;
			Message.idPid = getpid();
			Message.Requete = RESERVATIONKO;
			Message.arg.Numero = supprimerRes();
			if((msgsnd(idQ, &Message, LONGMESSAGE, 0)) == -1)
			{
				perror("(MAGASIN) Erreur d'ecriture sur la file de message");
				exit(1);
			}
			Mail = false;
			Res = false;
			setTextBoutonValider("Louer");
			setTextBoutonQuitter("Quitter");	
			setInfo("Article mis en stock");
			return;		
		}
		else
		{
			if (Transaction)
			{
				setTextBoutonValider("Valider");
				setTextBoutonQuitter(" ");
				setClient("");	
				setNumCompte("");	
				setInfo("");
				// Le client quitte le magasin en ayant donné son n° de compte
				Message.Type = 1L;
				Message.idPid = getpid();
				Message.Requete = ANNULERLOCATION;
				if((msgsnd(idQ, &Message, LONGMESSAGE, 0)) == -1)
				{
					perror("(MAGASIN) Erreur d'ecriture sur la file de message");
					exit(1);
				}
				Identification = false;
				Transaction = false;
				Loc = false;		
				return;
			}
			else
			{	
				Trace("pas de location en cours");
				if(Identification)
				{
					setTextBoutonValider("Valider");
					setTextBoutonQuitter(" ");
					setClient("");	
					setNumCompte("");	
					setInfo("");
					// Le client quitte le magasin sans avoir donné son n° de compte
					Message.Type = 1L;
					Message.idPid = getpid();
					Message.Requete = ANNULERLOCATION;
					if((msgsnd(idQ, &Message, LONGMESSAGE, 0)) == -1)
					{
						perror("(MAGASIN) Erreur d'ecriture sur la file de message");
						exit(1);
					}
					Identification = false;	
				}
			}
		}
	}
}

void MainMagasin::on_radioButton1_clicked()
{
	Selection = ArtTemp[0].id;
	setImage(ArtTemp[0].Image);
	Choix = 0;
	if(!Fact && !Mail)
	{
		if(Res)
		{
			Res = false;
			setTextBoutonValider("Louer");
			setInfo("");
		}
		if(!Loc)
		{
			setInfo("");
		}
	}
}

void MainMagasin::on_radioButton2_clicked()
{
	Selection = ArtTemp[1].id;
	setImage(ArtTemp[1].Image);
	Choix = 1;
	if(!Fact && !Mail)
	{
		if(Res)
		{
			Res = false;
			setTextBoutonValider("Louer");
			setInfo("");
		}
		if(!Loc)
		{
			setInfo("");
		}
	}
}

void MainMagasin::on_radioButton3_clicked()
{
	Selection = ArtTemp[2].id;
	setImage(ArtTemp[2].Image);
	Choix = 2;
	if(!Fact && !Mail)
	{
		if(Res)
		{
			Res = false;
			setTextBoutonValider("Louer");
			setInfo("");
		}
		if(!Loc)
		{
			setInfo("");
		}
	}
}

void MainMagasin::on_radioButton4_clicked()
{
	Selection = ArtTemp[3].id;
	setImage(ArtTemp[3].Image);
	Choix = 3;
	if(!Fact && !Mail)
	{
		if(Res)
		{
			Res = false;
			setTextBoutonValider("Louer");
			setInfo("");
		}
		if(!Loc)
		{
			setInfo("");
		}
	}
}


void HandlerSigUsr1(int Sig)
{
	Trace("Reception d'un SigUsr1 (%d)",Sig);
	if((msgrcv(idQ, &Message, LONGMESSAGE, getpid(), 0)) == -1)
	{
        perror("(MAGASIN) Erreur de lecture sur la file de message");
        exit(1);
	}
	else
	{
		switch (Message.Requete)
		{
			case CONNECTINCORRECT:
				//verification si la connection est autorisée
				Trace("Réponse reçue : %d", Message.Requete);
				if(Message.Requete == CONNECTINCORRECT)
				{
					Trace("Authentification non autorisée. Au revoir.");
					exit(1);
				}				
				break;
				
			case LECTURESTOCK:

				for(int i = 0; i < 4 ; i++)
				{
					Trace("%d",Message.arg.Art[i].id);
					Trace("%s",Message.arg.Art[i].NomArticle);
					Trace("%s",Message.arg.Art[i].Image);
				}
				// Affichage des 4  articles
				Selection = Message.arg.Art[Choix].id;
				w->setArticle1(Message.arg.Art[0].NomArticle);
				w->setArticle2(Message.arg.Art[1].NomArticle);
				w->setArticle3(Message.arg.Art[2].NomArticle);
				w->setArticle4(Message.arg.Art[3].NomArticle);
				w->setImage(Message.arg.Art[Choix].Image);
	
				// Copie des articles dans le tableau ArtTemp
				for(int i = 0; i < 4 ; i++)
				{
					ArtTemp[i].id = Message.arg.Art[i].id;
					strcpy(ArtTemp[i].NomArticle, Message.arg.Art[i].NomArticle);
					strcpy(ArtTemp[i].Image, Message.arg.Art[i].Image);
				}
				break;
				
			case NOUVEAUCLIENT:
				Trace("reception NOUVEAUCLIENT");
				w->setTextBoutonValider("Confirmer");
				w->setTextBoutonQuitter("Annuler");
				w->setInfo(Message.arg.Donnee);		
				break;
				
			case CLIENT:
				Trace("reception CLIENT");			
				w->setTextBoutonValider("Rendre");
				w->setTextBoutonQuitter("Quitter");
				w->setNumCompte(Message.arg.Art[0].NomArticle);	
				w->setInfo(Message.arg.Art[0].Image);	
				Transaction = true;
				Loc = true;
				break;
				
			case CLIENTOK:
				Trace("reception CLIENTOK");
				if(verifMail())
				{
					char Buff[40];
					RESCLIENT *tmp;
					tmp = pTete;
					//recherche du client pour l'article
					while(strcmp(tmp->nomClient,w->getClient()) != 0)
					{
						tmp = tmp->pSuiv;
					}
					w->setTextBoutonValider("Prendre");
					w->setTextBoutonQuitter("Laisser");
					sprintf(Buff,"Votre article id %d est arrive",tmp->idArt);
					w->setInfo(Buff);
					Mail = true;
				}
				else
				{
					w->setTextBoutonValider("Louer");
					w->setTextBoutonQuitter("Quitter");
					w->setInfo("");
				}
				w->setNumCompte(Message.arg.Donnee);
				Transaction = true;	
				break;
				
			case LOCATIONOK:
				Trace("reception LOCATIONOK");
				w->setTextBoutonValider("Rendre");
				w->setTextBoutonQuitter("Quitter");
				w->setInfo(Message.arg.Donnee);	
				Loc = true;			
				break;
				
			case LOCATIONKO:
				Trace("reception LOCATIONKO");
				w->setTextBoutonValider("Reserver");
				w->setTextBoutonQuitter("Quitter");
				w->setInfo(Message.arg.Donnee);
				Res = true;
				break;
				
			case RETOURARTICLE:
				Trace("reception RETOURARTICLE");
				w->setTextBoutonValider("Accepter");
				w->setTextBoutonQuitter(" ");
				w->setInfo(Message.arg.Donnee);
				Fact = true;
				Loc = false;
				break;
				
			case RESERVATIONOK:
				Trace("reception RESERVATIONOK");
				w->setTextBoutonValider("Louer");
				w->setTextBoutonQuitter("Quitter");
				w->setInfo(Message.arg.Donnee);
				insererRes();	
				break;
			
			case RESERVATIONKO:
				Trace("reception RESERVATIONKO");
				w->setTextBoutonValider("Louer");
				w->setTextBoutonQuitter("Quitter");
				w->setInfo(Message.arg.Donnee);				
				break;
		}
	}
}

void HandlerSigUsr2(int Sig)
{
	Trace("Reception d'un SigUsr2 (%d)",Sig);
    int fils = 0;
    
	RESCLIENT *tmp;
	tmp = pTete;
	while(tmp->resMail != 0)
	{
		tmp = tmp->pSuiv;
	}
	tmp->resMail = 1;
		
	//creation Mail
	Trace("(MAGASIN) Creation Mail");
	if((fils = fork()) == -1)
	{
		perror("(MAGASIN) Creation Mail Err de fork");
		exit(1);	
	}
	if(fils == 0)
	{	// processus fils
		
		execl("./Mail", "Mail", tmp->nomClient, NomMagasin, (char*)NULL);
		perror("(MAGASIN) Creation Mail");
		exit(0);
	}
	
	if(w->getClient() != NULL)
	{
		if(verifMail())
		{
			char Buff[40];
			Mail = true;

			w->setTextBoutonValider("Prendre");
			w->setTextBoutonQuitter("Laisser");
			sprintf(Buff,"Votre article id %d est arrive",tmp->idArt);
			w->setInfo(Buff);
		}
	}
}

bool pileVide()
{
	if(pTete == NULL)
		return true;
	return false;
}

void insererRes()
{
	RESCLIENT *nouv;
	
	nouv =(RESCLIENT*) malloc(sizeof(RESCLIENT));
	if(nouv == NULL)
	{
		Trace("(MAGASIN) erreur insertion");
	}
	else
	{
		
		nouv->idArt = Selection;
		nouv->resMail = 0;
		strcpy(nouv->nomClient, w->getClient());
		nouv->pSuiv = NULL;
		if(pileVide())
		{
			pTete = nouv;
		}
		else
		{
			RESCLIENT *tmp;
			tmp = pTete;
			
			while(tmp->pSuiv != NULL)
			{
				tmp = tmp->pSuiv;
			}
			tmp->pSuiv = nouv;
		}	
	}
}

int supprimerRes()
{
	int id;
	RESCLIENT *tmp, *tmpPrec;
	
	tmp = pTete;
	tmpPrec = NULL;
	
	while(strcmp(tmp->nomClient,w->getClient()) != 0)
	{
		tmpPrec = tmp;
		tmp = tmp->pSuiv;
	}
	if(tmpPrec == NULL)
	{
		pTete = tmp->pSuiv;
	}
	else
	{
		tmpPrec->pSuiv = tmp->pSuiv;
	}
	
	id = tmp->idArt;
	
	free(tmp);
	
	return id;
}

bool verifMail()
{
	if(!pileVide())
	{
		RESCLIENT *tmp;
		tmp = pTete;
		
		while(tmp->pSuiv != NULL && strcmp(tmp->nomClient,w->getClient()) != 0)
		{
			tmp = tmp->pSuiv;
		}
	
		if(strcmp(tmp->nomClient,w->getClient()) == 0 && tmp->resMail == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}




