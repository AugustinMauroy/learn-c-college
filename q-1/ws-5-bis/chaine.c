#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    /* Remplacez les valeurs ci-dessous par vos informations si vous le souhaitez */
    char prenom[] = "Augustin";
    char nom[] = "Mauroy";
    char login[20] = "";
    char message[50] = "";
    char bienvenue[] = "Bienvenue";

    /* B. Récupérer la longueur d'une chaîne */
    int taillePrenom;
    /* avec la variable prenom */
    taillePrenom = strlen(prenom);
    printf("Taille de prenom (variable) : %d\n", taillePrenom);

    /* sans utiliser la variable prenom (exemple avec "Dennis") */
    taillePrenom = strlen("Dennis");
    printf("Taille de \"Dennis\" : %d\n", taillePrenom);

    /* C. Comparer des chaînes */
    int cmp = strcmp(prenom, "Dennis");
    if (cmp == 0) {
        printf("Quelle chance d'avoir le meme prenom que l'inventeur du C !\n");
    } else {
        printf("Zut ! Pas de chance.\n");
    }
    if (cmp < 0) {
        printf("Avant\n");
    } else if (cmp > 0) {
        printf("Apres\n");
    }

    /* Comparer la première lettre avec 'D' */
    if (strncmp(prenom, "D", 1) == 0) {
        printf("C'est deja un debut...\n");
    }

    /* D. Copier des chaînes */
    strcpy(login, "IG1"); /* copie complète */
    /* copie bienvenue dans message */
    strcpy(message, bienvenue);

    /* E. Concaténer : ajouter un espace puis le prénom au message */
    strcat(message, " ");
    strcat(message, prenom);
    printf("Message : %s\n", message);

    /* Concaténer des parties de chaînes dans login */
    /* ajouter les 3 premières lettres du nom */
    strncat(login, nom, 3);
    /* ajouter les 2 premières lettres du prénom */
    strncat(login, prenom, 2);
    printf("Login : %s\n", login);

    return EXIT_SUCCESS;
}
