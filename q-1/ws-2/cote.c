#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int cote;
    printf("Cote /20: ");
    scanf("%d", &cote);
    if (cote < 10) {
        printf("Aie, c'est un echec !");
    }

    return EXIT_SUCCESS;
}