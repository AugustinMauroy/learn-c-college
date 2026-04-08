#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double montant;
    printf("Montant à payer (€) : ");
    scanf("%lf", &montant);
    printf("Vous devez payer %.2f euros", montant);

    return EXIT_SUCCESS;
}
