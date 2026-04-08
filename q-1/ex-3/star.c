/*
Écrivez un programme qui, étant donné un entier obtenu de l’utilisateur, affiche une figure étoilée comme présenté ci-dessous.

Nombre de ligne(s) : 4
      *
    *** 
  *****
*******
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int lignes;

    printf("Nombre de ligne(s) : ");
    scanf("%d", &lignes);

    for (int i = 1; i <= lignes; i++) {
        for (int j = 0; j < lignes - i; j++) {
            printf("  ");
        }
        for (int k = 0; k < 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}
