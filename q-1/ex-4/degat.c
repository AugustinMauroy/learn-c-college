#include <stdio.h>
#include <stdlib.h>

double degatsEffectifs(int points, double mod) {
    return points * mod;
}

int main(void) {
    int points;
    double mod;

    printf("Points de dégât du personnage (entier) : ");
    scanf("%d", &points);

    printf("Modificateur (réel <= 1) : ");
    scanf("%lf", &mod);

    double total = degatsEffectifs(points, mod);
    printf("Points de dégâts effectifs : %.2f\n", total);

    return EXIT_SUCCESS;
}