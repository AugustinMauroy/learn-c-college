#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char classe;

    printf("Choisissez votre classe :\n");
    printf("(M)agicien\n");
    printf("(O)racle\n");
    printf("(R)oublard\n");
    printf("(P)rêtre\n");
    printf("(G)uerrier\n");
    printf("Votre choix : ");
    scanf(" %c", &classe);

    // Version if/else imbriqué
    /*
    if (classe == 'M') {
        printf("Magicien\n");
    } else {
        if (classe == 'O') {
            printf("Oracle\n");
        } else {
            if (classe == 'R') {
                printf("Roublard\n");
            } else {
                if (classe == 'P') {
                    printf("Prêtre\n");
                } else {
                    if (classe == 'G') {
                        printf("Guerrier\n");
                    } else {
                        printf("Tu n'as pas de classe\n");
                    }
                }
            }
        }
    }

    if (classe == 'M') {
        printf("Magicien\n");
    } else if (classe == 'O') {
        printf("Oracle\n");
    } else if (classe == 'R') {
        printf("Roublard\n");
    } else if (classe == 'P') {
        printf("Prêtre\n");
    } else if (classe == 'G') {
        printf("Guerrier\n");
    } else {
        printf("Tu n'as pas de classe\n");
    }
    */

    switch (classe) {
        case 'M':
            printf("Magicien\n");
            break;
        case 'O':
            printf("Oracle\n");
            break;
        case 'R':
            printf("Roublard\n");
            break;
        case 'P':
            printf("Prêtre\n");
            break;
        case 'G':
            printf("Guerrier\n");
            break;
        default:
            printf("Tu n'as pas de classe\n");
            break;
    }
    
    return EXIT_SUCCESS;
}