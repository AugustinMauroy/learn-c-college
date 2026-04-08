#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char destination;

    printf("Destination (B pour Belgique, E pour Etranger) : ");
    scanf("%c", &destination);

    if (destination == 'B') {
        printf("Colis simple\n");
    } else {
        printf("Colis renforcé\n");
    }

    return EXIT_SUCCESS;
}