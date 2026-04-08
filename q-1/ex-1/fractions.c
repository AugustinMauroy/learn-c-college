#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int numerateur, denominateur;
    double divisionReelle;
    int divisionEntiere;

    printf("Numerateur : ");
    scanf("%d", &numerateur);
    printf("Denominateur : ");
    scanf("%d", &denominateur);

    if (denominateur == 0) {
        printf("Erreur : le denominateur ne peut pas etre zero.\n");
        return EXIT_FAILURE;
    }

    divisionReelle = numerateur / denominateur;
    divisionEntiere = numerateur / denominateur;

    printf("%d/%d = %.4f = %d\n", numerateur, denominateur, divisionReelle, divisionEntiere);

    return EXIT_SUCCESS;
}