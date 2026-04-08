#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int nbPC;
    double montant;

    // Demander le nombre de PC commandés
    printf("Nombre de PC commandés (entier) : ");
    scanf("%d", &nbPC);

    // Demander le montant de la commande
    printf("Montant de la commande (réel) : ");
    scanf("%f", &montant);

    // Vérifier si les PC coûtent trop cher
    if (nbPC != 0 && (montant / nbPC) > 500) {
        printf("Ces PC coutent trop cher !\n");
    }

    return EXIT_SUCCESS;
}