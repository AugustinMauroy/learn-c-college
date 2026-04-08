#include <stdio.h>

char reponseValide(void) {
	char reponse;
	do { 
		printf("Reponse (o/n) : ");
		scanf("%c", &reponse);
		getchar();
	} while(reponse != 'o' && reponse != 'n');
	return reponse;
}

void main(void) {
	char reponseQ1, reponseQ2, reponseQ3;

	printf("1. Aimez-vous la Chimay bleue ?\n");
	reponseQ1 = reponseValide();

	printf("2. Aimez-vous la Blanche ?\n");
	reponseQ2 = reponseValide();

	printf("3. Aimez-vous le fromage d'abbaye ?\n");
	reponseQ3 = reponseValide();
	
	if(reponseQ1 == 'o' && reponseQ2 == 'o' && reponseQ3 == 'o') {
		printf("Vous avez toutes vos chances en C...") ;
	} else {
		printf("Vous allez devoir étudier à fond !");
	}
}
