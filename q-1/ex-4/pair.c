#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool estPair(int n) {
    return n % 2 == 0;
}

int main(void) {
    int impaire, paire;

    impaire = 3;
    paire = 4;

    printf("Le nombre %d est-il pair ? %s\n", impaire, estPair(impaire) ? "Oui" : "Non");
    printf("Le nombre %d est-il pair ? %s\n", paire, estPair(paire) ? "Oui" : "Non");

    return EXIT_SUCCESS;
}
