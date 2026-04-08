#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int nombre;
    int somme = 0;

    /*for (int i = 1 ; i <= 5 ; i++) {
        printf("Nombre : ");
        scanf("%d", &nombre);
        somme += nombre;
    }
    printf("Somme : %d", somme);*/

    // Version avec while
    int i = 1;
    while (i <= 5) {
        printf("Nombre : ");
        scanf("%d", &nombre);
        somme += nombre;
        i++;
    }
    printf("Somme : %d\n", somme);

    return EXIT_SUCCESS;
}