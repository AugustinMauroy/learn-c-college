#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char reponse;

    do {
        printf("Avez-vous joué une autre partie ? Réponse (o/n) : ");
        scanf(" %c", &reponse);
    } while (reponse != 'o' && reponse != 'n');

    printf("Merci pour votre réponse : %c\n", reponse);

    return EXIT_SUCCESS;
}