/*
Étant donné un nombre entier n strictement positif obtenu de l’utilisateur, faites imprimer les n premiers nombres pairs et leur carré.
example
Nombre : 6
Nombres pairs	Carrés 
2 	4
4	16
6	36
8	64
10	100
12	144
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int nombre;

    printf("Nombre : ");
    scanf("%d", &nombre);

    printf("Nombres pairs\tCarrés\n");
    for (int i = 1; i <= nombre; i++) {
        int pair = i * 2;
        //printf("%d\t\t%d\n", pair, pair * pair);
        printf("%d\t\t%.0f\n", pair, pow(pair, 2));
    }

    return EXIT_SUCCESS;
}

