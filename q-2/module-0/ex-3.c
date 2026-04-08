#include <stdio.h>

int aggrandissement(int surface) {
	return surface = surface * 2;
}

void main(void) {
	int surfaceNenuphars;
	printf("Entrez la surface initiale : ");
	scanf("%d", &surfaceNenuphars);
	for (int nbAnnees = 1; nbAnnees <= 10; nbAnnees++) {
		surfaceNenuphars = aggrandissement(surfaceNenuphars);
		printf("Apres %d annee(s), la surface sera de %d.\n", nbAnnees, surfaceNenuphars);
	}
}
