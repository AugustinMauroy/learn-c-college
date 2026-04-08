/*
Sur base d’un choix (M, D ou I) obtenu de l’utilisateur, un message est affiché :
•	Marvel 	➜ “Captain America will save us!”
•	DC	➜ “Superman will save us!”
•	Image	➜ “SuperPatriot will save us!”
Si le choix de l’utilisateur est erroné, le message à afficher est : “Nobody will save us!”.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char choix;

    // Demander le choix à l'utilisateur
    printf("Choisissez une option (M pour Marvel, D pour DC, I pour Image) : ");
    scanf(" %c", &choix);

    // Afficher le message correspondant au choix
    switch (choix) {
        case 'M':
            printf("Captain America will save us!\n");
            break;
        case 'D':
            printf("Superman will save us!\n");
            break;
        case 'I':
            printf("SuperPatriot will save us!\n");
            break;
        default:
            printf("Nobody will save us!\n");
            break;
    }

    return EXIT_SUCCESS;
}