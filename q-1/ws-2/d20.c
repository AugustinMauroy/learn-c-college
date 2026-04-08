/*
Dans le fichier source d20.c, dans la fonction principale, écrivez les instructions qui permettent de demander le résultat d’un lancer de dé à 20 faces à l’utilisateur. 

Si le résultat du lancer de dé est supérieur ou égal à 10, on considère que c’est un bon résultat. Dans ce cas, le message "Beau lancer ! " est affiché, sinon rien n’est affiché.
Attention, lisez bien l’énoncé ! Le but n’est pas de vérifier que la valeur est bien entre 1 et 20 (inclus), c’est une condition supposée déjà respectée par l’utilisateur.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int lancer;

    // Demander le résultat du lancer de dé
    printf("Entrez le résultat du lancer de dé à 20 faces : ");
    scanf("%d", &lancer);

    // Vérifier si le lancer est un bon résultat
    if (lancer >= 10) {
        printf("Beau lancer !\n");
    }

    return EXIT_SUCCESS;
}