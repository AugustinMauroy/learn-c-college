#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int nbParties;
    int sommePoints = 0;

    nbParties = 0;
    /*while (nbParties < 10) {
        int pointsPartie;
        printf("Points de la partie : ");
        scanf("%d", &pointsPartie);
        sommePoints += pointsPartie;
        nbParties++;
    }
    printf("Score moyen : %.2f", (double)sommePoints / nbParties);*/

    for (nbParties = 0; nbParties < 10; nbParties++) {
        int pointsPartie;
        printf("Points de la partie : ");
        scanf("%d", &pointsPartie);
        sommePoints += pointsPartie;
    }
    printf("Score moyen : %.2f\n", (double)sommePoints / nbParties);

    return EXIT_SUCCESS;
}