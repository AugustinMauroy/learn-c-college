#include <stdio.h>
#include <stdlib.h>

#define PRIX_ADULTE 6.5
#define PRIX_JEUNE 5.5

int main(void) {
    int nbAdultes, nbJeunes;
    float montant;

    printf("Nombre de places adultes : ");
    scanf("%d", &nbAdultes);
    printf("Nombre de places jeunes : ");
    scanf("%d", &nbJeunes);

    montant = nbAdultes * PRIX_ADULTE + nbJeunes * PRIX_JEUNE;

    printf("Montant à payer : \033[0;32m%.2f\033[0m €\n", montant);

    return EXIT_SUCCESS;
}