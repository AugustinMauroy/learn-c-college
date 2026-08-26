#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_LOCALITE 30

typedef struct chainon Chainon;
struct chainon {
	int codePostal;
	char localite[TAILLE_LOCALITE];
	Chainon* pSuiv;
};

void afficheListe(Chainon* pChainon) {
	while (pChainon != NULL) {
		printf("%d - %s\n", pChainon->codePostal, pChainon->localite);
		pChainon = pChainon->pSuiv;
	}
}

void saisieListe(Chainon** ppDeb) {
    char localite[TAILLE_LOCALITE];

    printf("Entrez une localité (XXX pour terminer) : ");
    scanf("%s", localite);
    while (strcmp(localite, "XXX") != 0) {
        int codePostal;
        printf("Entrez le code postal de %s : ", localite);
        scanf("%d", &codePostal);

        Chainon* pNouv = (Chainon*)malloc(sizeof(Chainon));
        if (pNouv == NULL) {
            printf("Erreur d'allocation de mémoire !\n");
            return;
        }

        pNouv->codePostal = codePostal;
        strncpy(pNouv->localite, localite, TAILLE_LOCALITE);
        pNouv->localite[TAILLE_LOCALITE - 1] = '\0'; // assurer la terminaison de la chaîne
        pNouv->pSuiv = *ppDeb;
        *ppDeb = pNouv;

        printf("Entrez une localité (XXX pour terminer) : ");
        scanf("%s", localite);
    }
}

void libererListe(Chainon* pListe) {
    Chainon* pCourant = pListe;
    Chainon* pASupprimer = NULL;

    while (pCourant != NULL) {
        pASupprimer = pCourant;
        pCourant = pCourant->pSuiv;
        free(pASupprimer);
    }
}

int main(void) {
    Chainon* pDeb = NULL;

    saisieListe(&pDeb);
    afficheListe(pDeb);
    libererListe(pDeb);

    return EXIT_SUCCESS;
}
