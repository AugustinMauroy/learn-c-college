#include <stdio.h>
#include <stdlib.h>

/*
Écrivez une fonction qui, après avoir initialiser un tableau de 20 entiers, demande un entier à l’utilisateur et affiche l’indice de la cellule où se trouve cet entier (-1 s’il ne s’y trouve pas).
*/
int trouverIndice(int tableau[], int taille, int valeur) {
    for (int i = 0; i < taille; i++) {
        if (tableau[i] == valeur) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    int tableau[20];

    for (int i = 0; i < 20; i++) {
        tableau[i] = i * 2;
    }

    int valeur;
    printf("Entrez un entier à rechercher dans le tableau: ");
    scanf("%d", &valeur);

    int indice = trouverIndice(tableau, 20, valeur);
    if (indice == -1) {
        printf("L'entier %d ne se trouve pas dans le tableau.\n", valeur);
    } else {
        printf("L'entier %d se trouve à l'indice %d.\n", valeur, indice);
    }

    return EXIT_SUCCESS;
}