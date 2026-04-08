#include <stdio.h>
#include <stdlib.h>


void echangeDeuxReels(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int a=5, b=10;

    printf("Avant l'échange : a = %d, b = %d\n", a, b);

    echangeDeuxReels(&a, &b);

    printf("Après l'échange : a = %d, b = %d\n", a, b);

    return EXIT_SUCCESS;
}
