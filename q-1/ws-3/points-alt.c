#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PARTIES 5

int main(void) {
    int nbParties;
    int sommePoints = 0;
    int pointsPartie;

    printf("Points de la partie : ");
    scanf("%d", &pointsPartie);
    nbParties = 1;
    while (pointsPartie != 0 && nbParties < MAX_PARTIES) {
        sommePoints += pointsPartie;
        printf("Points de la partie : ");
        scanf("%d", &pointsPartie);
        nbParties++;
    }

    if (pointsPartie == 0) {
        nbParties--;
    } else {
        sommePoints += pointsPartie;
    }
    
    
    if (nbParties > 0) {
        printf("Score moyen : %.2f\n", (double)sommePoints / nbParties);
    } else {
        printf("Aucune partie jouée.\n");
    }

    return EXIT_SUCCESS;
}