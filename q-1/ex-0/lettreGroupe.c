#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char groupe;

    printf("Entrez votre groupe : ");
    scanf("%c", &groupe);
    printf("Votre groupe est %c", groupe);

    return EXIT_SUCCESS;
}
