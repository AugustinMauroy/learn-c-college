#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int montantJeu = 0;
    int montantTotal = 0;
    
    printf("Montant du jeu : ");
    scanf("%d", &montantJeu);
    
    while (montantJeu != 0) {
        montantTotal += montantJeu;
        printf("Montant du jeu : ");
        scanf("%d", &montantJeu);
    }
    
    printf("Vous avez acheté pour un montant de %d euros.\n", montantTotal);
    
    return EXIT_SUCCESS;
}