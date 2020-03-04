#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <signal.h>

#include "Fichier.ini"
#include "Ecran.h"



int main()
{
	MESSAGE Message;
	int idQ;
	pid_t lastpid;
	
	if ((idQ = msgget(CLE,IPC_CREAT | IPC_EXCL | 0600)) == -1)
	{ 
		perror("Err. de creation de READCLE");
		exit(1);
	}
	
	Trace("Creation de la file de message idQ = %d \n",idQ);

	while(1)
	{
		if (msgrcv(idQ,&Message,sizeof(Message) - sizeof(long),(long)1,0) == -1)
		{
			msgctl(idQ,IPC_RMID,NULL);
			perror("\t(SERVEUR) Erreur de lecture");
			exit(1);
		}
		Trace("(SERVEUR) Reception d'un message du process %d\n",Message.Pid);
		Message.Type = (long)Message.Pid;
		lastpid = Message.Pid;
		Message.Pid = 1;
		
		if (msgsnd(idQ,&Message,strlen(Message.M) + sizeof(long),0) == -1)
		{
			msgctl(idQ,IPC_RMID,NULL);
			perror("\t(SERVEUR) Erreur d'ecriture");
			exit(1);
		}
		kill(lastpid,SIGUSR1);
		Trace("(SERVEUR) Envoie d'un message");		
	}
	
}
