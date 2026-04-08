/*
Écrivez un programme qui, étant donnés deux nombres réels obtenus de l'utilisateur, permet de déterminer le signe du produit (positif, négatif ou nul), sans effectuer l'opération mais en se basant sur les signes de chacun des deux nombres.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double num1;
    double num2;
    
    printf("Entrez le premier nombre réel : ");
    scanf("%lf", &num1);
    printf("Entrez le deuxième nombre réel : ");
    scanf("%lf", &num2);

    if (num1 == 0 || num2 == 0) {
        printf("Le produit est nul.\n");
    } else if ((num1 > 0 && num2 > 0) || (num1 < 0 && num2 < 0)) {
        printf("Le produit est positif.\n");
    } else {
        printf("Le produit est négatif.\n");
    }

    return EXIT_SUCCESS;
}