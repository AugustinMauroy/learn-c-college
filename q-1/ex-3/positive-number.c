/*
Écrivez le programme qui demande et récupère un nombre entier. Son contenu doit normalement être un nombre positif. Votre programme affiche "Erreur…" tant que le nombre ne respecte pas la condition. Lorsque le nombre est correcte le message "Correct ! " est affiché.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int nombre;

    do {
        printf("Entrez un nombre positif : ");
        scanf("%d", &nombre);

        if (nombre < 0) {
            printf("Erreur... Le nombre doit être positif.\n");
        }
    } while (nombre < 0);

    printf("Correct !\n");

    return 0;
}