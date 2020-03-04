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
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <string.h>
#include <signal.h>
#include <mysql.h>
#include <time.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

MYSQL		*Connexion;
MYSQL_RES	*Resultat;
MYSQL_ROW	Ligne;


#include "Ecran.h"
#include "Fichier.ini"

TABLEAU		*Tab;
int		    idQ;
int			idM;
int			idSem;
MESSAGE	    Message;
char		Buff[255];
int			hdPipe[2];

void Affichage();

void creerRessources();
void creerTableau();
int connexionMessageQueue();
int creerMessageQueue();
int creerSemaphore();
int connexionSemaphore();
int connexionShMemory();
int creerShMemory();
void creerServiceFacturation();
void creerPipe();
void creerServiceLivraison();
void creerVehiculesLivraisons();
void fermerPipe();

void substitution();

int main()
{
    // le plus simple est de demarrer la substitution au debut pour permettre à l'autre de lancer le processus
    substitution();

	// declaration de la structure pour effectuer des opération sur les sémaphores
	struct sembuf SemOp;
	
	// Creation de des ressources

    Titre("====================== DEMARRAGE ===================");
    creerRessources();

    Affichage();

    // Connect a la Base de donnees
    Connexion = mysql_init(NULL);
    mysql_real_connect(Connexion,"localhost","colletlo","Passcolletlo","Pourcolletlo",0,0,0);
    if(Connexion == NULL)
    {
        exit(1);
    }

    while (1)
    {
        // Reception du message
        Trace("(CENTRAL) Attente de reception d'un message");
        if ((msgrcv(idQ, &Message, LONGMESSAGE, 1L, 0) == -1))
        {
            perror("(CENTRALE) Erreur de reception de message");
            exit(1);
        }
 
        Trace("(CENTRAL) Recu = %d", Message.Requete);
        
        //si je suis CENTRAL 1 je verifie que CENTRAL 2 est en vie
        if(getpid() == Tab->idCentral1)
        {
        	if(Tab->idCentral2 != 0)
        	{
        		if((kill(Tab->idCentral2, 0)) == -1 )
        		{
        			printf("La central 2 est morte suppresion de la table\n");
        			Tab->idCentral2 = 0;
        		}
        	}
        }
        else //je suis CENTRAL 2 et je verifie CENTRAL 1
        {
			if((kill(Tab->idCentral1, 0)) == -1 )
       		{
       			printf("La central 1 est morte, echange + suppresion de la table\n");
       			Tab->idCentral1 = Tab->idCentral2;
       			Tab->idCentral2 = 0;
       		}
        }
        
        //verification des autres processus, s'ils sont mort on exit
 		if((kill(Tab->idServiceFacturation, 0)) == -1 )
       	{
       		printf("ServiceFacturation DEAD \n");
       		exit(1);
   		}       
 		if((kill(Tab->idServiceLivraison, 0)) == -1 )
       	{
       		printf("ServiceLivraison DEAD \n");
       		exit(1);
   		}    
 		if((kill(Tab->idVehiculeLivraison1, 0)) == -1 )
       	{
       		printf("VehiculeLivraison1 DEAD \n");
       		exit(1);
   		}    
   		if((kill(Tab->idVehiculeLivraison2, 0)) == -1 )
       	{
       		printf("VehiculeLivraison2 DEAD \n");
       		exit(1);
   		}     		
   		
   		
        switch(Message.Requete)
        {
	        case CONNECT:
	        	{
	        		//préparation de la structure pour decrementer le semaphore
	        		SemOp.sem_num = 0;
					SemOp.sem_op = -1;
					SemOp.sem_flg = 0;

					semop(idSem, &SemOp, 1);

	        		int numResult = 0;
		          	int iTab = 0;
		          	
				    //Trace("Reception de CONNECT -%s-",Message.arg.Donnee);
				    sprintf(Buff, "SELECT * FROM MagasinBd WHERE Nom = '%s';", Message.arg.Donnee);
				    mysql_query(Connexion, Buff);
				    printf(mysql_error(Connexion));
				    Resultat = mysql_store_result(Connexion);

				    while((Ligne = mysql_fetch_row(Resultat)))
				    {
				        numResult++;
				    }
					if(numResult)
					{
						// parcourir le tableau des magasins
						while(Tab->Connexion[iTab].idMagasin != 0 && iTab < 5 && strcmp(Tab->Connexion[iTab].NomMagasin, Message.arg.Donnee) != 0)
						{
						    iTab++;
						}
						
						if(strcmp(Tab->Connexion[iTab].NomMagasin, Message.arg.Donnee) == 0)
						{
						 	sleep(1); // sinon le signal n'est pas traité correctement par le magasin
						 	// envoie du signal pour aller dans le handler du magasin
				            if(kill(Message.idPid, SIGUSR1) == -1)
				            {
				            	perror ("(CENTRALE) Erreur de kill CONNECT");
								exit(1);
				            }
						    printf("(CENTRALE) Magasin deja existant !");
				            Message.Type = Message.idPid; // modification effectuée, à qui c'est destiné : celui qui envoie le message 
				            Message.idPid = 1L; // modification effectuée, de qui ça vient : serveur
				            Message.Requete = CONNECTINCORRECT;
						}
						else
						{
						   Trace("(CENTRALE) Magasin %s ajouté !", Message.arg.Donnee);
						   strcpy(Tab->Connexion[iTab].NomMagasin, Message.arg.Donnee);
						   Tab->Connexion[iTab].idMagasin = Message.idPid;
						   
				 	       Message.Type = Message.idPid;
				       	   Message.idPid = 1L;
				       	   
				       	   // requete pour avoir les 4 premiers atricles
				       	   sprintf(Buff, "SELECT * FROM StockBd LIMIT 4;");
				       	   mysql_query(Connexion, Buff);
						   printf(mysql_error(Connexion));
				 		   Resultat = mysql_store_result(Connexion);
				 		   
				 		   // mets les 4 premiers articles dans la structure Message
				 		   iTab = 0;
				 		   while((Ligne = mysql_fetch_row(Resultat)))
						   {
							  Message.arg.Art[iTab].id = atoi(Ligne[0]); // atoi car on récupère un char au lieu d'un int
							  strcpy(Message.arg.Art[iTab].NomArticle, Ligne[1]);
							  strcpy(Message.arg.Art[iTab].Image, Ligne[3]);
							  iTab ++;
						   } 	   
						}
				   }
				   else
				   {
				   		sleep(1); // sinon le signal n'est pas traité correctement par le magasin
				   		// envoie du signal pour aller dans le handler du magasin
						if(kill(Message.idPid, SIGUSR1) == -1)
				        {
				         	perror ("(CENTRALE) Erreur de kill CONNECT");
							exit(1);
			            }
				        Message.Type = Message.idPid;
				        Message.idPid = 1L;
				        Message.Requete = CONNECTINCORRECT;
						printf("(CENTRALE) Magasin non autorisé !");
				   }
				   // envoie du message pour le magasin
				   if(msgsnd(idQ, &Message, LONGMESSAGE, 0) == -1)
				   {
				   		perror("(CENTRALE) Erreur d'envoie du message CONNECT");
				   }
				   
				   //préparation de la structure pour incrementer le semaphore
	        	   SemOp.sem_num = 0;
				   SemOp.sem_op = +1;
				   SemOp.sem_flg = 0;

				   semop(idSem, &SemOp, 1);
				   
				   Affichage();
		       }
		       break;
		            
		    case CONNECTINCORRECT:
		    	{
		    	
		    	}
		        break;
		            
		    case NOUVEAUCLIENT:
		    	{
		    	
		    	}
		        break;
		            
		    case NUMEROCOMPTE:
		    	{
	        		//préparation de la structure pour decrementer le semaphore
	        		SemOp.sem_num = 0;
					SemOp.sem_op = -1;
					SemOp.sem_flg = 0;

					semop(idSem, &SemOp, 1);
					
		    		int iTab = 0;
		    		
				    Trace("(CENTRAL) Reception NUMEROCOMPTE");
					// parcourir le tableau des magasins
					while(Tab->Connexion[iTab].idMagasin != 0 && iTab < 5 && Tab->Connexion[iTab].idMagasin != Message.idPid)
					{
						iTab++;
					}
				    sprintf(Buff, "insert into ClientBd values (NULL, '%s', '%s', 0, NULL);", Tab->Connexion[iTab].Client, Message.arg.Donnee);
				    mysql_query(Connexion, Buff);
				    
				 	// envoie du signal pour aller dans le handler du magasin
				 	if(kill(Message.idPid, SIGUSR1) == -1)
				    {
				        perror ("(CENTRALE) Erreur de kill NUMEROCOMPTE");
						exit(1);
			        }
			        Message.Type = Message.idPid;
				    Message.idPid = 1L;
				    Message.Requete = CLIENTOK;
			        // envoie du message pour le magasin
					if(msgsnd(idQ, &Message, LONGMESSAGE, 0) == -1)
					{
						perror("(CENTRALE) Erreur d'envoie du message NUMEROCOMPTE");
					}	
				   //préparation de la structure pour incrementer le semaphore
	        	   	SemOp.sem_num = 0;
				   	SemOp.sem_op = +1;
					SemOp.sem_flg = 0;

					semop(idSem, &SemOp, 1);
				   		           
					Affichage();
				}
		        break;
		            
		    case CLIENT:
		    	{
	        		//préparation de la structure pour decrementer le semaphore
	        		SemOp.sem_num = 0;
					SemOp.sem_op = -1;
					SemOp.sem_flg = 0;

					semop(idSem, &SemOp, 1);
					
		    		int iTab = 0;
		    		
				    Trace("(CENTRAL) reception d'un client -%s-",Message.arg.Donnee);
				    // requete pour recuperer tous les clients
				    sprintf(Buff, "SELECT * FROM ClientBd WHERE NomClient = '%s';",Message.arg.Donnee);
				    mysql_query(Connexion, Buff);
					printf(mysql_error(Connexion));
				 	Resultat = mysql_store_result(Connexion);
					// parcourir le tableau des magasins
					while(Tab->Connexion[iTab].idMagasin != 0 && iTab < 5 && Tab->Connexion[iTab].idMagasin != Message.idPid)
					{
						iTab++;
					}
					// mettre le client comme present dans le tableau magasin
					strcpy(Tab->Connexion[iTab].Client, Message.arg.Donnee);
					
				 	if((Ligne = mysql_fetch_row(Resultat))) // le client existe
				 	{
				 		if(atoi(Ligne[3]) != 0) // le client a deja une location en cours
				 		{
					 		Message.Requete = CLIENT;
					 		strcpy(Message.arg.Art[0].NomArticle,Ligne[2]);
					 		strcpy(Message.arg.Art[0].Image, "Veuillez rendre le materiel");				 		
				 		}
				 		else // le client n'a rien en location
				 		{
					 		Message.Requete = CLIENTOK;
					 		strcpy(Message.arg.Donnee, Ligne[2]);
				 		}
				 	}		     	
				 	else //le client n'existe pas encore
				 	{
				 		Message.Requete = NOUVEAUCLIENT;
				 		strcpy(Message.arg.Donnee, "Votre n. de compte SVP");
				 	}
				 	// envoie du signal pour aller dans le handler du magasin
				 	if(kill(Message.idPid, SIGUSR1) == -1)
				    {
				        perror ("(CENTRALE) Erreur de kill CLIENT");
						exit(1);
			        }
			        Message.Type = Message.idPid;
				    Message.idPid = 1L;
			        // envoie du message pour le magasin
					if(msgsnd(idQ, &Message, LONGMESSAGE, 0) == -1)
					{
						perror("(CENTRALE) Erreur d'envoie du message CLIENT");
					}
				   //préparation de la structure pour incrementer le semaphore
	        	   	SemOp.sem_num = 0;
				   	SemOp.sem_op = +1;
				   	SemOp.sem_flg = 0;

				   	semop(idSem, &SemOp, 1);
					
					Affichage();   
				}  	    
		        break;
		            
		    case LECTURESTOCK:
		    	{
	        		//préparation de la structure pour decrementer le semaphore
	        		SemOp.sem_num = 0;
					SemOp.sem_op = -1;
					SemOp.sem_flg = 0;

					semop(idSem, &SemOp, 1);
					
		    		int iTab = 0;
		    		int numResult = 0;
		    		int numTmp = 0;
		    		
				    Trace("(CENTRAL) Reception de LECTURESTOCK");
				    // requete pour recuperer les nombre d'acticles
				    sprintf(Buff, "SELECT COUNT(*) FROM StockBd;");
				    mysql_query(Connexion, Buff);
					printf(mysql_error(Connexion));
				 	Resultat = mysql_store_result(Connexion);
				 	Ligne = mysql_fetch_row(Resultat);
				    numResult = atoi(Ligne[0]);

				    // requetes pour avoir les atricles
				    numTmp = Message.arg.Numero;
				    if(numTmp <= 0) // avoir ceux qui sont a la fin car retour a la fin par le debut
				    {
				    	iTab = (numTmp) * -1;
						sprintf(Buff, "SELECT * FROM StockBd ORDER BY (1) DESC LIMIT %d;", iTab);
						mysql_query(Connexion, Buff);
						printf(mysql_error(Connexion));
					 	Resultat = mysql_store_result(Connexion);

					 	for(int i = (iTab - 1) ; (Ligne = mysql_fetch_row(Resultat)) ; i--)
					 	{
					 		Message.arg.Art[i].id = atoi(Ligne[0]); // atoi car on récupère un char au lieu d'un int
							strcpy(Message.arg.Art[i].NomArticle, Ligne[1]);
							strcpy(Message.arg.Art[i].Image, Ligne[3]);
					 	}

						if(numTmp <= 0 && numTmp >= -3) // avoir ceux qui sont au debut
						{
							iTab = numTmp + 4;
							sprintf(Buff, "SELECT * FROM StockBd LIMIT %d;", iTab);
							mysql_query(Connexion, Buff);
							printf(mysql_error(Connexion));
						 	Resultat = mysql_store_result(Connexion);

						 	for(int i = (4 - iTab) ; (Ligne = mysql_fetch_row(Resultat)) ; i++)
						 	{
						 		Message.arg.Art[i].id = atoi(Ligne[0]); // atoi car on récupère un char au lieu d'un int
								strcpy(Message.arg.Art[i].NomArticle, Ligne[1]);
								strcpy(Message.arg.Art[i].Image, Ligne[3]);
						 	}				 		 	
						}
					}
					else
					{
						if(numTmp >= 1) // avoir ceux qui sont au millieu
						{
							sprintf(Buff, "SELECT * FROM StockBd;");
							mysql_query(Connexion, Buff);
							printf(mysql_error(Connexion));
						 	Resultat = mysql_store_result(Connexion);

							int j = 0;
						 	for(int i = 0 ; (Ligne = mysql_fetch_row(Resultat)) ; i++)
						 	{
						 		if((i+1) > numTmp && (i+1) <= (numTmp + 4))
						 		{
							 		Message.arg.Art[j].id = atoi(Ligne[0]); // atoi car on récupère un char au lieu d'un int
									strcpy(Message.arg.Art[j].NomArticle, Ligne[1]);
									strcpy(Message.arg.Art[j].Image, Ligne[3]);
									j++;
								}
						 	}	 		 	
						 	if(numTmp > (numResult - 4)) // avoir ceux qui sont au debut car retour au debut par la fin
							{
								iTab = 4 - (numResult - numTmp);
								sprintf(Buff, "SELECT * FROM StockBd LIMIT %d;", iTab);
								mysql_query(Connexion, Buff);
								printf(mysql_error(Connexion));
							 	Resultat = mysql_store_result(Connexion);

							 	while((Ligne = mysql_fetch_row(Resultat)))
							 	{
							 		Message.arg.Art[j].id = atoi(Ligne[0]); // atoi car on récupère un char au lieu d'un int
									strcpy(Message.arg.Art[j].NomArticle, Ligne[1]);
									strcpy(Message.arg.Art[j].Image, Ligne[3]);
									j++;
							 	}
							}
						}				 		 	
					}			 		 	
					
				   	//préparation de la structure pour incrementer le semaphore
	        	   	SemOp.sem_num = 0;
				   	SemOp.sem_op = +1;
				   	SemOp.sem_flg = 0;

				   	semop(idSem, &SemOp, 1);
									 	
				 	// envoie du signal pour aller dans le handler du magasin
				 	if(kill(Message.idPid, SIGUSR1) == -1)
				    {
				        perror ("(CENTRALE) Erreur de kill LECTURESTOCK");
						exit(1);
			        }
			        Message.Type = Message.idPid;
				    Message.idPid = 1L;
				    Message.Requete = LECTURESTOCK;
			        // envoie du message pour le magasin
					if(msgsnd(idQ, &Message, LONGMESSAGE, 0) == -1)
					{
						perror("(CENTRALE) Erreur d'envoie du message LECTURESTOCK");
					}
				}		     	
		        break;
		    
		    case RESERVATION:
		    	{
	        		//préparation de la structure pour decrementer le semaphore
	        		SemOp.sem_num = 0;
					SemOp.sem_op = -1;
					SemOp.sem_flg = 0;

					semop(idSem, &SemOp, 1);
					
		    		int idArt = Message.arg.Numero;
		    		
		    		Trace("(CENTRAL) Reception de RESERVATION");

					sprintf(Buff, "SELECT * FROM MagasinBd WHERE Nom = 'Central';");
					mysql_query(Connexion, Buff);
					printf(mysql_error(Connexion));
					Resultat = mysql_store_result(Connexion);		    	
					
					Ligne = mysql_fetch_row(Resultat);
					
					if(atoi(Ligne[(idArt + 1)]) > 0) // s'il y a du stock
					{
						pid_t pidTmp;
						pidTmp = Message.idPid; // retient le pid du magasin car on doit ecrire a service livraison entre temps
						
						// retire 1 a la quantité du magasin
						sprintf(Buff, "UPDATE MagasinBd SET Quantite%d = Quantite%d-1 WHERE Nom = 'Central';", idArt, idArt);
						mysql_query(Connexion, Buff);
						printf(mysql_error(Connexion));
						
						/*appel a ServiceLivraison*/
				        Message.Type = Tab->idServiceLivraison;
					    Message.idPid = 1L;						
						Message.Requete = pidTmp;
					    // envoie du message pour le ServiceLivraison
						if(msgsnd(idQ, &Message, LONGMESSAGE, 0) == -1)
						{
							perror("(CENTRALE) Erreur d'envoie du message RESERVATION");
						}						
						/*préparation du message pour le magasin*/
						Message.idPid = pidTmp;
						Message.Requete = RESERVATIONOK;
						strcpy(Message.arg.Donnee, "Reservation effectuee");
					}
					else // s'il n'y a pas de stock
					{
						Message.Requete = RESERVATIONKO;
						strcpy(Message.arg.Donnee, "L'article n'est pas disponible");
					}

				   	//préparation de la structure pour incrementer le semaphore
	        	   	SemOp.sem_num = 0;
				   	SemOp.sem_op = +1;
				   	SemOp.sem_flg = 0;

				   	semop(idSem, &SemOp, 1);

				 	// envoie du signal pour aller dans le handler du magasin
				 	if(kill(Message.idPid, SIGUSR1) == -1)
				    {
				        perror ("(CENTRALE) Erreur de kill RESERVATION");
						exit(1);
			        }
			        Message.Type = Message.idPid;
				    Message.idPid = 1L;
				    
			        // envoie du message pour le magasin
					if(msgsnd(idQ, &Message, LONGMESSAGE, 0) == -1)
					{
						perror("(CENTRALE) Erreur d'envoie du message RESERVATION");
					}								    	
		    	}
		    	break;
		    	  
		    case LOCATION:
		    	{
	        		//préparation de la structure pour decrementer le semaphore
	        		SemOp.sem_num = 0;
					SemOp.sem_op = -1;
					SemOp.sem_flg = 0;

					semop(idSem, &SemOp, 1);
					
		    		int iTab = 0;
		    		int idArt = Message.arg.Numero;

					Trace("(CENTRAL) Reception de LOCATION");
					while(Tab->Connexion[iTab].idMagasin != 0 && iTab < 5 && Tab->Connexion[iTab].idMagasin != Message.idPid)
					{
						iTab++;
					}		
	    	
					sprintf(Buff, "SELECT * FROM MagasinBd WHERE Nom = '%s';",Tab->Connexion[iTab].NomMagasin);
					mysql_query(Connexion, Buff);
					printf(mysql_error(Connexion));
					Resultat = mysql_store_result(Connexion);		    	
					
					Ligne = mysql_fetch_row(Resultat);
						
					if(atoi(Ligne[(idArt + 1)]) > 0) // s'il y a du stock
					{
						Message.Requete = LOCATIONOK;
						strcpy(Message.arg.Donnee, "Location effectuee");
						// retire 1 a la quantité du magasin
						sprintf(Buff, "UPDATE MagasinBd SET Quantite%d = Quantite%d-1 WHERE Nom = '%s';", idArt, idArt, Tab->Connexion[iTab].NomMagasin);
						mysql_query(Connexion, Buff);
						printf(mysql_error(Connexion));
						// ajoute le code article au client du client
						sprintf(Buff, "UPDATE ClientBd SET ArticleLoue = %d WHERE NomClient = '%s';", idArt, Tab->Connexion[iTab].Client);
						mysql_query(Connexion, Buff);
						printf(mysql_error(Connexion));
					}
					else // s'il n'y a pas de stock
					{
						Message.Requete = LOCATIONKO;
						strcpy(Message.arg.Donnee, "L'article n'est pas disponible immediatement");
					}

				   	//préparation de la structure pour incrementer le semaphore
	        	   	SemOp.sem_num = 0;
				   	SemOp.sem_op = +1;
				   	SemOp.sem_flg = 0;

				   	semop(idSem, &SemOp, 1);

				 	// envoie du signal pour aller dans le handler du magasin
				 	if(kill(Message.idPid, SIGUSR1) == -1)
				    {
				        perror ("(CENTRALE) Erreur de kill LOCATION");
						exit(1);
			        }
			        Message.Type = Message.idPid;
				    Message.idPid = 1L;
				    
			        // envoie du message pour le magasin
					if(msgsnd(idQ, &Message, LONGMESSAGE, 0) == -1)
					{
						perror("(CENTRALE) Erreur d'envoie du message LOCATION");
					}	
				}		    	
		        break;
		            
		    case ANNULERLOCATION:
		    	{
		    		int iTab = 0;
		    		
		    		Trace("(CENTRAL) Reception de ANNULERLOCATION");
					// parcourir le tableau des magasins
					while(Tab->Connexion[iTab].idMagasin != 0 && iTab < 5 && Tab->Connexion[iTab].idMagasin != Message.idPid)
					{
						iTab++;
					}
					// retirer le client du tableau magasin
					strcpy(Tab->Connexion[iTab].Client, " ");
					Affichage();
				}
		        break;
		            
		    case RETOURARTICLE:
		    	{
	        		//préparation de la structure pour decrementer le semaphore
	        		SemOp.sem_num = 0;
					SemOp.sem_op = -1;
					SemOp.sem_flg = 0;

					semop(idSem, &SemOp, 1);
					
					int iTab = 0;
					int idArt = 0;
					
					Trace("(CENTRAL) Reception de RETOURARTICLE");
					// parcourir le tableau des magasins
					while(Tab->Connexion[iTab].idMagasin != 0 && iTab < 5 && Tab->Connexion[iTab].idMagasin != Message.idPid)
					{
						iTab++;
					}
					// avoir le n° d'article loué par le client
					sprintf(Buff, "SELECT ArticleLoue FROM ClientBd WHERE NomClient = '%s';",Tab->Connexion[iTab].Client);
					mysql_query(Connexion, Buff);
					printf(mysql_error(Connexion));
					Resultat = mysql_store_result(Connexion);
					Ligne = mysql_fetch_row(Resultat);
					idArt = atoi(Ligne[0]);
					// mettre l'acticle loué a 0
					sprintf(Buff, "UPDATE ClientBd SET ArticleLoue = 0 WHERE NomClient = '%s';",Tab->Connexion[iTab].Client);
					mysql_query(Connexion, Buff);
					printf(mysql_error(Connexion));						
					// mettre l'article a nouveau dans le stock du magasin
					sprintf(Buff, "UPDATE MagasinBd SET Quantite%d = Quantite%d+1 WHERE Nom = '%s';", idArt, idArt, Tab->Connexion[iTab].NomMagasin);	
					mysql_query(Connexion, Buff);
					printf(mysql_error(Connexion));
					
				   	//préparation de la structure pour incrementer le semaphore
	        	   	SemOp.sem_num = 0;
				   	SemOp.sem_op = +1;
				   	SemOp.sem_flg = 0;

				   	semop(idSem, &SemOp, 1);
									
					strcpy(Message.arg.Donnee, Tab->Connexion[iTab].Client);	
					Message.Requete = Message.idPid;
			        Message.Type = Tab->idServiceFacturation;
				    Message.idPid = 1L;
			        // envoie du message pour le ServiceFacturation

			        Trace("(CENTRAL) idQ = %d | Message.Requete = %d | Message.Type = %d | Message.idPid = %d", idQ, Message.Requete, Message.Type, Message.idPid);

					if(msgsnd(idQ, &Message, LONGMESSAGE, 0) == -1)
					{
						perror("(CENTRALE) Erreur d'envoie du message RETOURARTICLE");
					}		
					
		    	}
		        break;
		    
		    case RESERVATIONOK:
		    	{
	        		//préparation de la structure pour decrementer le semaphore
	        		SemOp.sem_num = 0;
					SemOp.sem_op = -1;
					SemOp.sem_flg = 0;

					semop(idSem, &SemOp, 1);
					
					int iTab = 0;
					
					Trace("(CENTRAL) Reception de RESERVATIONOK");
					// parcourir le tableau des magasins
					while(Tab->Connexion[iTab].idMagasin != 0 && iTab < 5 && Tab->Connexion[iTab].idMagasin != Message.idPid)
					{
						iTab++;
					}
					// mettre l'acticle réservé au client
					sprintf(Buff, "UPDATE ClientBd SET ArticleLoue = %d WHERE NomClient = '%s';", Message.arg.Numero, Tab->Connexion[iTab].Client);
					mysql_query(Connexion, Buff);
					printf(mysql_error(Connexion));		
					
				   	//préparation de la structure pour incrementer le semaphore
	        	   	SemOp.sem_num = 0;
				   	SemOp.sem_op = +1;
				   	SemOp.sem_flg = 0;

				   	semop(idSem, &SemOp, 1);
		    	}
		    	break;
		    	
		    case RESERVATIONKO:
		    	{
	        		//préparation de la structure pour decrementer le semaphore
	        		SemOp.sem_num = 0;
					SemOp.sem_op = -1;
					SemOp.sem_flg = 0;

					semop(idSem, &SemOp, 1);
					
					int iTab = 0;
					
					Trace("(CENTRAL) Reception de RESERVATIONKO");
					// parcourir le tableau des magasins
					while(Tab->Connexion[iTab].idMagasin != 0 && iTab < 5 && Tab->Connexion[iTab].idMagasin != Message.idPid)
					{
						iTab++;
					}	
					// mettre l'article dans le stock du magasin
					sprintf(Buff, "UPDATE MagasinBd SET Quantite%d = Quantite%d+1 WHERE Nom = '%s';", Message.arg.Numero, Message.arg.Numero, Tab->Connexion[iTab].NomMagasin);	
					mysql_query(Connexion, Buff);
					printf(mysql_error(Connexion));
					
					//préparation de la structure pour incrementer le semaphore
	        	   	SemOp.sem_num = 0;
				   	SemOp.sem_op = +1;
				   	SemOp.sem_flg = 0;

				   	semop(idSem, &SemOp, 1);  	
		    	}
		    	break;   
		            
		    default:
		    	{
		    	
		    	}
		        break;
        }

    }
}

void Affichage()
{
	Titre("Suivi : ");
	printf("\n\n\t------ MON PID = %d ------- \n\n", getpid());
	printf("idCentral1           : %d\n",Tab->idCentral1);
	printf("idCentral2           : %d\n",Tab->idCentral2);
	printf("idServiceFacturation : %d\n",Tab->idServiceFacturation);
	printf("idServiceLivraison   : %d\n",Tab->idServiceLivraison);
	printf("idVehiculeLivraison1 : %d\n",Tab->idVehiculeLivraison1);
	printf("idVehiculeLivraison2 : %d\n",Tab->idVehiculeLivraison2);
	int i = 0;
	while (i < 5)
	{
        printf("Magasin        : %-20s - %d\n",Tab->Connexion[i].NomMagasin,Tab->Connexion[i].idMagasin);
        printf("    Client[%d]  : %-20s - %d\n",i,Tab->Connexion[i].Client,Tab->Connexion[i].Location);
		i++;
	}
	printf("\n");
}



void creerRessources()
{

    if(!connexionMessageQueue())
    {
        creerMessageQueue();
        creerSemaphore();
        creerShMemory();
        creerTableau();
        creerServiceFacturation();
        creerPipe();
        creerServiceLivraison();
        creerVehiculesLivraisons();
        fermerPipe();
    }
    else
    {
    	connexionSemaphore();
    	connexionShMemory();

	/*if(Tab->idCentral2 != 0)
	{
		printf("Impossible de connecter plus de 2 centrales !\n");
		exit(1);
	}*/    	

    	Tab->idCentral2 = getpid();
    }
    Trace("(CENTRAL) idQueue     : %d", idQ);
    Trace("(CENTRAL) idSemaphore : %d", idSem);    
    Trace("(CENTRAL) idShMemory  : %d", idM);
}

int connexionMessageQueue()
{
    if((idQ = msgget(CLE, 0)) == -1)
    {
        perror("(CENTRALE) Erreur de connexion a la file de message");
        return 0;
    }
    else
    {
        printf("Connexion a la file de message reussie !\n");
        return 1;
    }
}

int creerMessageQueue()
{
    if((idQ = msgget(CLE, IPC_CREAT | IPC_EXCL | 0600)) == -1)
    {
        perror("(CENTRALE) Erreur de creation de la file de message");
        exit(1);
    }
    else
    {
        printf("Creation de la file de message reussie !\n");

	struct msqid_ds queue;

	if(msgctl(idQ, IPC_STAT, &queue) == -1){
		perror("(CENTRALE) Erreur de msgctl IPC_STAT.");
		exit(1);
	}else{
		if(getuid() == LOIC){
			queue.msg_perm.uid = LOIC;
		}else{
			queue.msg_perm.uid = KEVIN;
		}	
		if((msgctl(idQ, IPC_SET, &queue)) == -1){
			perror("(CENTRAL) Erreur de IPC_SET (msgctl)");
			exit(1);		
		}
	}

        return 1;
    }

}

int connexionSemaphore()
{
	if ((idSem = semget(SEMA,0,0)) == -1)
	{ 
		perror("(CENTRALE) Erreur de connexion au semaphore");
		exit(1);
	}
	else
	{
        printf("Connexion au semaphore reussie !\n");

        return 1;
	}
}

int creerSemaphore()
{
	if ((idSem = semget(SEMA, 1, IPC_CREAT | IPC_EXCL | 0600)) == -1)
	{ 
		perror("(CENTRALE) Erreur de creation du semaphore");
		exit(1);
	}
	else
	{
        printf("Creation du semaphore reussie !\n");
        if (semctl(idSem, 0, SETVAL, 1) == -1)
	{
		perror("(CENTRALE) Erreur de semctl(0)");
		exit(1);
	}
	printf("Initialisation du semaphore reussie !\n");

	struct semid_ds semaphore;
	if((semctl(idSem,0, IPC_STAT, &semaphore)) == -1){
		perror("(CENTRALE) Erreur de semctl IPC_STAT.");
		exit(1);
	}else{
		if(getuid() == LOIC){
			semaphore.sem_perm.uid = LOIC;
		}else{
			semaphore.sem_perm.uid = KEVIN;
		}	
		if((semctl(idSem,0, IPC_SET, &semaphore)) == -1){
			perror("(CENTRAL) Erreur de IPC_SET (semctl)");
			exit(1);		
		}
	}

        return 1;	
	}
}

int connexionShMemory()
{
		
	struct shmid_ds shared;	

	if ((idM = shmget(SHM, 0, 0)) == -1)
	{ 
		perror("(CENTRALE) Erreur de connexion a la Sh memory");
		exit(1);
	}
	else
	{
        printf("Connexion a la Sh memory reussie !\n");


	if(shmctl(idM, IPC_STAT, &shared)){
		perror("(CENTRALE) Erreur de IPC_STAT");
	}

	if(shared.shm_nattch >= 2){
		perror("Impossible de démarrer plus de 2 centrale.");
		exit(1);
	}

		
	
	if ((Tab = (TABLEAU*)shmat(idM, NULL, 0)) == (TABLEAU*)-1)
	{
		perror("(CENTRALE) Erreur de shmat()");
		exit(1);
	}

	printf("Assignation du pointeur reussie !\n");
        return 1;		
	}
}

int creerShMemory()
{
	if ((idM = shmget(SHM, 512, IPC_CREAT | IPC_EXCL | 0600)) == -1)
	{
		perror("(CENTRALE) Erreur de creation de la Sh memory");
		exit(1);
	}
	else
	{
        printf("Creation de la Sh memory reussie !\n");     
		if ((Tab = (TABLEAU*)shmat(idM, NULL, 0)) == (TABLEAU*)-1)
		{
			perror("(CENTRALE) Erreur de shmat()");
			exit(1);
		}
		printf("Assignation du pointeur reussi !\n");


	struct shmid_ds shared;	
	if(shmctl(idM, IPC_STAT, &shared)){
		perror("(CENTRALE) Erreur de shmctl IPC_STAT.");
		exit(1);
	}else{
		if(getuid() == LOIC){
			shared.shm_perm.uid = LOIC;
		}else{
			shared.shm_perm.uid = KEVIN;
		}	
		if((shmctl(idM, IPC_SET, &shared)) == -1){
			perror("(CENTRAL) Erreur de IPC_SET (shmctl)");
			exit(1);		
		}
	}

        return 1;	
	}
}

void creerServiceFacturation()
{
	int fils = 0;

	Trace("(CENTRALE) Creation ServiceFacturation");
	if((fils = fork()) == -1)
	{
		perror("(CENTRALE) (Creation ServiceFacturation) Err de fork");
		exit(1);	
	}

	if(fils == 0)
	{	// processus fils
		execl("./ServiceFacturation","ServiceFacturation",(char*)NULL);
	}
	
	Tab->idServiceFacturation = fils;
}

void creerPipe()
{
	Trace("(CENTRALE) Creation du Pipe");
	if (pipe(hdPipe) == -1)
	{
		perror("(CENTRALE) Erreur creation du pipe()...");
		exit(1);
	}
}

void creerServiceLivraison()
{
	int fils = 0;

    char entreePipe[20], sortiePipe[20];

	Trace("(CENTRALE) Creation ServiceLivraison");
	if((fils = fork()) == -1)
	{
		perror("(CENTRALE) (Creation ServiceLivraison) Err de fork");
		exit(1);	
	}
	if(fils == 0)
	{	// processus fils


	    // l'entree est + grande que la lecture
        sprintf(entreePipe, "%d", hdPipe[1]);
        sprintf(sortiePipe, "%d", hdPipe[0]);

		execl("./ServiceLivraison", "ServiceLivraison", sortiePipe, entreePipe, (char*)NULL);
	}
	
	Tab->idServiceLivraison = fils;
}

void creerVehiculesLivraisons()
{
    int fils = 0;

    char entreePipe[20], sortiePipe[20];

	//creation VehiculeLivraison 1
	Trace("(CENTRALE) Creation VehiculeLivraison1");
	if((fils = fork()) == -1)
	{
		perror("(CENTRALE) (Creation VehiculeLivraison1) Err de fork");
		exit(1);	
	}
	if(fils == 0)
	{	// processus fils


        // l'entree est + grande que la lecture
        sprintf(entreePipe, "%d", hdPipe[1]);
        sprintf(sortiePipe, "%d", hdPipe[0]);

		execl("./VehiculeLivraison", "VehiculeLivraison", sortiePipe, entreePipe, (char*)NULL);
		perror("(CENTRALE) (creation vehiculle1)");
		exit(0);
	}

	Tab->idVehiculeLivraison1 = fils;
	fils = 0;

	//creation VehiculeLivraison 2

	Trace("(CENTRALE) Creation VehiculeLivraison2");
	if((fils = fork()) == -1)
	{
		perror("(CENTRALE) (Creation VehiculeLivraison2) Err de fork");
		exit(1);	
	}
	if(fils == 0)
	{	// processus fils


        // l'entree est + grande que la lecture
        sprintf(entreePipe, "%d", hdPipe[1]);
        sprintf(sortiePipe, "%d", hdPipe[0]);

        execl("./VehiculeLivraison", "VehiculeLivraison", sortiePipe, entreePipe, (char*)NULL);
        perror("(CENTRALE) (creation vehiculle2)");
        exit(0);
	}

    Tab->idVehiculeLivraison2 = fils;
}

void fermerPipe()
{
	Trace("(CENTRALE) Fermeture des descripteurs");
	if (close(hdPipe[0]))
	{
		perror("(CENTRALE) (CENTRAL) Erreur de close()");
		exit(1);
	}
	if (close(hdPipe[1]))
	{
		perror("(CENTRALE) (CENTRAL) Erreur de close()");
		exit(1);
	}
}

void creerTableau()
{
    Tab->idCentral1 = getpid();
    for(int i = 0; i < 5; i++)
    {
        Tab->Connexion[i].idMagasin = 0;
    }
}

void substitution()
{

    Titre("----- Substitution ! -----");

    struct passwd pass;
    struct group grp;


    memcpy(&pass, getpwuid(getuid()), sizeof(pass));
    memcpy(&grp, getgrgid(getgid()), sizeof(grp));

    printf("(CENTRALE) (Sub.) realUser : %5d (%s) // realGroup : %5d (%s)\n", getuid(), pass.pw_name, getgid(), grp.gr_name);

    memcpy(&pass, getpwuid(geteuid()), sizeof(pass));
    memcpy(&grp, getgrgid(getegid()), sizeof(grp));

    printf("(CENTRALE) (Sub.) effectiveUser : %5d (%s) // effectiveGroup : %5d (%s)\n", geteuid(), pass.pw_name, getegid(), grp.gr_name);

    

    if (getuid() == LOIC){
        setreuid(LOIC, KEVIN);
    } else {
        setreuid(KEVIN, LOIC);
    }

}








