/*
Soit un nombre à deviner (fixé dans le programme), l'utilisateur doit deviner celui-ci en 10 coups maximum.
S'il introduit un nombre plus grand, le message affiché est "Votre nombre est trop élevé…" ; s'il introduit un nombre plus petit, le message affiché est "Votre nombre est trop petit…".
S'il ne le devine pas au bout des 10 essais, le message affiché est "Perdu !". 
En cas de victoire, le message affiché est "Gagné en x essais !" (où x est le nombre d'essais effectués) ou "Gagné au premier coup!".
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ESSAIS 10
#define NOMBRE_A_DEVINER 42

int main() {
    int essai;
    int tentative;

    printf("Bienvenue au jeu de devinette ! Vous avez %d essais pour deviner le nombre.\n", MAX_ESSAIS);

    tentative = 0;

    while (tentative <= MAX_ESSAIS && essai != NOMBRE_A_DEVINER) {
        printf("Essai %d: Entrez votre nombre: ", tentative);
        scanf("%d", &essai);
        tentative++;

        if (essai < NOMBRE_A_DEVINER) {
            printf("Votre nombre est trop petit...\n");
        } else if (essai > NOMBRE_A_DEVINER) {
            printf("Votre nombre est trop élevé...\n");
        } else {
            if (tentative == 1) {
                printf("Gagné au premier coup!\n");
            } else {
                printf("Gagné en %d essais !\n", tentative);
            }
        }
    }

    if (essai == NOMBRE_A_DEVINER) {
        printf("Félicitations ! Vous avez deviné le nombre %d en %d essais.\n", NOMBRE_A_DEVINER, tentative);
    } else {
        printf("Perdu ! Le nombre à deviner était %d.\n", NOMBRE_A_DEVINER);
    }

    return EXIT_SUCCESS;
}