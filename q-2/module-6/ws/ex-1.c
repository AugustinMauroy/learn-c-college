#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int* pNombre;
	pNombre = (int*)malloc(sizeof(int));

	printf("Entrez un nombre entier : ");
	scanf("%d", pNombre);
	printf("Le nombre entre est %d !\n", *pNombre);

	free(pNombre);

    return EXIT_SUCCESS;
}
