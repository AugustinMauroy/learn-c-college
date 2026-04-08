/*
┌───* AfficheUrgences
│ sortir "Nombre de patients : "
│ obtenir nbPatients
│ sortir "Urgence vitale (o/n) : "
│ obtenir reponseUrgence
│
│ urgenceVitale = reponseUrgence == "o"
│
│┌── if (nbPatients < 60)
││┌── if (urgenceVitale AND nbPatients > 20)
│││ sortir "Appeler du renfort ! "
││├── else           
│││ sortir "On peut s'en sortir !"
││└──
│├── else           
││ sortir "Envoyer vers un autre hôpital."
│└──
└──
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int nbPatients;
    char reponseUrgence;
    int urgenceVitale;

    printf("Nombre de patients : ");
    scanf("%d", &nbPatients);

    printf("Urgence vitale (o/n) : ");
    scanf(" %c", &reponseUrgence);

    urgenceVitale = reponseUrgence == 'o';

    if (nbPatients < 60) {
        if (urgenceVitale && nbPatients > 20) {
            printf("Appeler du renfort !\n");
        } else {
            printf("On peut s'en sortir !\n");
        }
    } else {
        printf("Envoyer vers un autre hôpital.\n");
    }

    return EXIT_SUCCESS;
}