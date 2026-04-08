#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int tab[10];

    tab[0] = 5;
    for (int i = 1; i < 10; i++) {
        tab[i] = tab[i - 1] * 2;
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}