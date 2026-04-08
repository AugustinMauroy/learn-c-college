/*
Écrivez le programme qui demande et récupère un nombre entier. Son contenu doit normalement être un nombre positif, inférieur à 10. Votre programme affiche respectivement "Correct !" ou "Erreur…" suivant la valeur de l'entier.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int nombre;

    printf("Entrez un nombre entier (positif et < 10) : ");
    scanf("%d", &nombre);

    if (nombre >= 0 && nombre < 10) {
        printf("Correct !\n");
    } else {
        printf("Erreur : le nombre doit être positif et inférieur à 10.\n");
    }

    return EXIT_SUCCESS;
}