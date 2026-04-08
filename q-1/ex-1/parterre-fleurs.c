#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int longueur, largeur, quantiteParM2, surface, totalPlants;

    printf("Longueur du parterre (en metres) : ");
    scanf("%d", &longueur);
    printf("Largeur du parterre (en metres) : ");
    scanf("%d", &largeur);
    printf("Quantite de fleurs a planter par m² : ");
    scanf("%d", &quantiteParM2);

    surface = longueur * largeur;
    totalPlants = surface * quantiteParM2;

    printf(
        "Il faut acheter \033[0;32m%d\033[0m plants de fleurs pour un parterre de %d m².\n",
        totalPlants,
        surface
    );

    return EXIT_SUCCESS;
}