/*
Dans un parc d’attractions, certaines attractions ne sont pas accessibles aux personnes dont la taille est soit inférieure à une taille minimum soit supérieure à une taille maximum. 
Écrivez un programme qui demande et récupère la taille d’une personne et détermine si cette personne est autorisée à accéder à l’attraction. Les différentes tailles sont exprimées en centimètres.
La variable tailleMin contient la taille minimum et la variable tailleMax, la taille maximum. Commencez par déclarer et affecter une valeur sensée à ces deux variables (par exemple 100 et 200).
Ce programme affiche le message « Accès refusé : taille trop petite » ou « Accès refusé : taille trop grande » ou « Accès autorisé ». 
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int tailleMin = 100;
    int tailleMax = 200;
    int taillePersonne;

    printf("Entrez votre taille en cm : ");
    scanf("%d", &taillePersonne);

    if (taillePersonne < tailleMin) {
        printf("Accès refusé : taille trop petite\n");
    } else if (taillePersonne > tailleMax) {
        printf("Accès refusé : taille trop grande\n");
    } else {
        printf("Accès autorisé\n");
    }

    return EXIT_SUCCESS;
}