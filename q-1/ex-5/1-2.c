#include <stdio.h>
#include <stdlib.h>

#define TAILLE 20

int main(void) {
    int tab[TAILLE];

    for (int i = 0; i < TAILLE; i++) {
        tab[i] = i + 1;
    }

    for (int i = TAILLE - 1; i >= 0; i--) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}