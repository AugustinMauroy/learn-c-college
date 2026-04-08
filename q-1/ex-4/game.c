#include <stdio.h>
#include <stdlib.h>

void afficheMenu(void) {
    printf("1. Nouveau personnage\n");
    printf("2. Nouvelle partie\n");
    printf("3. Partie en cours\n");
    printf("4. Quitter\n");
}

int choixLu(void) {
    int choix;

    do {
        afficheMenu();
        printf("Entrez le numéro de l'option : ");
        scanf("%d", &choix);

        if (choix < 1 || choix > 4) {
            printf("Choix hors plage. Veuillez choisir entre 1 et 4.\n");
        }
    } while (choix < 1 || choix > 4);

    return choix;
}

int main(void) {
    int choix = choixLu();

    switch (choix) {
    case 1:
        printf("Créer un nouveau personnage\n");
        break;
    case 2:
        printf("Commencer une nouvelle partie\n");
        break;
    case 3:
        printf("Continuer la partie sauvegardée\n");
        break;
    case 4:
        return EXIT_SUCCESS;
    }

    return EXIT_SUCCESS;
}