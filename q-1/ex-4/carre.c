#include <stdio.h>
#include <stdlib.h>

int obtenirNombre(void) {
    int n;
    do {
        printf("Entrez un entier positif : ");
        scanf("%d", &n);
    } while (n <= 0);
    return n;
}

int sommeCarres(int n) {
    int somme = 0;
    for (int i = 1; i <= n; i++) {
        somme += i * i;
    }
    return somme;
}

void afficherResultat(int n, int somme) {
    printf("La somme des carrés des nombres de 1 à %d est : %d\n", n, somme);
}

int main(void) {
    int nombre = obtenirNombre();
    int resultat = sommeCarres(nombre);
    afficherResultat(nombre, resultat);
    
    return EXIT_SUCCESS;
}