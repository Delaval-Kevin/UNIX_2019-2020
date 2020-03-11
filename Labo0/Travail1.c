#include <stdio.h>
#include <stdlib.h>

struct Eleve
{
	char nom[25];
	char prenom[25];
	short age;
};

int main ()
{
	struct Eleve eleve;

	printf("Entrer votre nom : ");
	scanf("%s",eleve.nom);
	printf("Entrer votre prenom : ");
	scanf("%s",eleve.prenom);
	printf("Entrer votre age : ");
	scanf("%hd",&eleve.age);
	
	printf("\n\nVous etes %s %s age de %hd \n",eleve.nom, eleve.prenom, eleve.age);

	return 0;
}
