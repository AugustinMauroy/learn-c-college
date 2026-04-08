#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double tva, montantTVAC, quantite;

    printf("Quantite d'articles : ");
    scanf("%lf", &quantite);
    printf("Montant total (TVAC) : ");
    scanf("%lf", &montantTVAC);
    printf("Taux de TVA (en %%): ");
    scanf("%lf", &tva);


    double montantHTVA = montantTVAC / (1 + tva / 100);
    double montantTVA = montantTVAC - montantHTVA;

    printf(
        "A payer : \033[0;32m%.2f\033[0m euros pour vos %.0f article%s\n",
        montantTVAC,
        quantite,
        quantite > 1 ? "s" : ""
    );

    return EXIT_SUCCESS;
}
