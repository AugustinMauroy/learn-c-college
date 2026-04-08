#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int num1, num2, temp;

    printf("Entrez le premier entier : ");
    scanf("%d", &num1);
    printf("Entrez le deuxieme entier : ");
    scanf("%d", &num2);
    printf("Avant echange : num1 = %d, num2 = %d\n", num1, num2);

    temp = num1;
    num1 = num2;
    num2 = temp;

    printf("Apres echange : num1 = %d, num2 = %d\n", num1, num2);

    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;
    printf("Apres re-echange sans variable temporaire : num1 = %d, num2 = %d\n", num1, num2);

    return EXIT_SUCCESS;
}