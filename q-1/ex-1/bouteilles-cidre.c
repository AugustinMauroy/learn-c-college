#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int productionLitres;
    int bouteillesPleines;
    int cidreRestantCl;

    printf("Production totale (en litres) : ");
    scanf("%d", &productionLitres);

    bouteillesPleines = productionLitres * 100 / 80;
    cidreRestantCl = productionLitres * 100 % 80;

    printf(
        "Vous pouvez remplir %d bouteille%s de 80 cl et il restera %d cl de cidre.\n",
        bouteillesPleines,
        bouteillesPleines > 1 ? "s" : "",
        cidreRestantCl
    );

    return EXIT_SUCCESS;
}