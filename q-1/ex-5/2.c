#include <stdio.h>
#include <stdlib.h>

#define N 10

void obtenirCotes(int cotes[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Entrez la cote %d: ", i + 1);
        scanf("%d", &cotes[i]);
    }
}

void afficherCotesEtMoyenne(int cotes[], int n) {
    int somme = 0;
    double moyenne;

    printf("\nLes cotes saisies sont:\n");
    for (int i = 0; i < n; i++) {
        printf("Cote %d: %d\n", i + 1, cotes[i]);
        somme += cotes[i];
    }
    moyenne = (double)somme / n;
    printf("Moyenne des cotes: %.2f\n", moyenne);
}

int main(void) {
    int cotes[N];

    obtenirCotes(cotes, N);
    afficherCotesEtMoyenne(cotes, N);

    return EXIT_SUCCESS;
}
