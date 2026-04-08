#include <stdio.h>

#define PRIX_DAGO 4.50

double prixTotal(double prixArticle, int nbArticles) {
	return prixArticle * nbArticles;
}


void main(void) {
	int nbDagos;
	printf("Combien de dago voulez-vous commander ?");
	scanf("%d", &nbDagos);
	printf("Vous devez payer %f Euros.", prixTotal(PRIX_DAGO, nbDagos));
}