#include <stdio.h> 
#include <stdlib.h>

#define TAILLE_TAB 5

int main(void) {
    int nombres[TAILLE_TAB] = {42, 17, 23, 8, 15};
    int min = nombres[0];

    for (int i = 1; i < TAILLE_TAB; i++) {
        if (nombres[i] < min) {
            min = nombres[i];
        }
    }

    printf("Le minimum est: %d\n", min);

    return EXIT_SUCCESS;
}