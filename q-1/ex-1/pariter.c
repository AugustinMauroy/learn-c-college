#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i;

    printf("Veuillez saisir un entier : ");
    scanf("%d", &i);
    printf("%d est %s\n", i, (i % 2 == 0) ? "pair" : "impair");

    return EXIT_SUCCESS;
}