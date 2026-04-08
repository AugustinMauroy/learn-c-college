#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char destination;
    int nbProduits;

    // Prompt for destination
    printf("Destination (B pour Belgique, E pour Etranger) : ");
    scanf("%c", &destination);

    // Prompt for number of products
    printf("Nombre de produits : ");
    scanf("%d", &nbProduits);

    // Determine shipping cost
    if (destination == 'B' || nbProduits > 10) {
        printf("Livraison gratuite\n");
    } else {
        if (nbProduits > 7) {
            printf("Frais de port de 5%%\n");
        } else {
            printf("Frais de port de 8%%\n");
        }
    }

    return EXIT_SUCCESS;
}