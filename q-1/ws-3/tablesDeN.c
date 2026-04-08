#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int number;

    printf("Entrez un nombre entre entier: ");
    scanf("%d", &number);

    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", i, number, i * number);
    }

    return EXIT_SUCCESS;
}