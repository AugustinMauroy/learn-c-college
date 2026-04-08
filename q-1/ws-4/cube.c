#include <stdio.h>
#include <stdlib.h>

int cube(int nombre) {
    return nombre * nombre * nombre;
}

int main(void) {
    int nombre = 3;
    int resultat = cube(nombre);

    printf("Le cube de %d est %d\n", nombre, resultat);

    return EXIT_SUCCESS;
}