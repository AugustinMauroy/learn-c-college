#include <stdio.h>
#include <stdlib.h>

double moyenne(int valeurs[], int nbValeurs) {
	int somme = 0;

	for (int i = 0; i < nbValeurs; i++)
		somme += valeurs[i];

	return (double)somme / nbValeurs;
}


int main(void) {
	int nbInterros = 0;
	int* pCotes = NULL;

    printf("Combien d'interros avez-vous ? ");
    scanf("%d", &nbInterros);

    pCotes = (int*)malloc(nbInterros * sizeof(int));

    if (pCotes == NULL) {
        printf("Erreur d'allocation de mémoire !\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < nbInterros; i++) {
        printf("Entrez la cote de l'interro %d : ", i + 1);
        scanf("%d", &pCotes[i]);
    }

    printf("La moyenne de vos interros est : %.2f\n", moyenne(pCotes, nbInterros));

    free(pCotes);

	return EXIT_SUCCESS;
}
