/*
Écrivez un programme qui demande et récupère 3 nombres entiers.
Ce programme affiche "Correct !" si le troisième nombre entré est bien la somme des deux premiers ; sinon, il affiche un message d'erreur et la bonne solution…
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int num1;
    int num2;
    int somme;
    int sommeCalculee;

    printf("Entrez le premier nombre entier : ");
    scanf("%d", &num1);
    printf("Entrez le deuxième nombre entier : ");
    scanf("%d", &num2);
    printf("Entrez la somme des deux nombres : ");
    scanf("%d", &somme);

    sommeCalculee = num1 + num2;

    if (somme == sommeCalculee) {
        printf("Correct !\n");
    } else {
        printf("Erreur : la bonne somme est %d\n", sommeCalculee);
    }

    return EXIT_SUCCESS;
}