#include <stdio.h>

double moyenne3Cotes(int cote1, int cote2, int cote3) {
	return (cote1 + cote2 + cote3) / 3.0;
}

void main(void) {
	int coteMax;
    double cote;
	int cotes[3];

	printf("Cote maximale (ou 0 pour la cote max standard de 20) : ");
	scanf("%d", &coteMax);
	if (coteMax == 0) {
		coteMax = 20;
	}

	for (int iCote = 0; iCote < 3; iCote++) {
		printf("Cote %d : ", iCote + 1);
		scanf("%d", &cotes[iCote]);
	}

	cote = moyenne3Cotes(cotes[0], cotes[1], cotes[2]);
	printf("Moyenne : %lf / %d\n", cote, coteMax);
}
