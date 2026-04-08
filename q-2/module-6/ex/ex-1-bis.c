#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LG_NOM 30

typedef enum plateformeDiffusion PlateformeDiffusion;
enum plateformeDiffusion {
	AUCUNE = 0,
	YOUTUBE = 1,
	TWITCH = 2,
	INSTAGRAM = 4,
	FACEBOOK = 8,
	WHATSAPP = 16,
	TIKTOK = 32,
	SNAPCHAT = 64,
};

typedef struct createur Createur;
struct createur {
	char nom[LG_NOM];
	PlateformeDiffusion plateformes;
};

typedef struct chainonCreateur ChainonCreateur;
struct chainonCreateur {
	Createur createur;
	ChainonCreateur* pSuiv;
};

ChainonCreateur* nouveauChainon(char nom[], PlateformeDiffusion plateformes, ChainonCreateur* pSuivant){
    ChainonCreateur* pNouv = malloc(sizeof(ChainonCreateur));

    if (pNouv == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    snprintf(pNouv->createur.nom, LG_NOM, "%s", nom);
    pNouv->createur.plateformes = plateformes;
    pNouv->pSuiv = pSuivant;

    return pNouv;
}

void affichePlateformes(PlateformeDiffusion plateformes) {
    bool first = true;
    if (plateformes & TWITCH) {
        printf("Twitch");
        first = false;
    }
    if (plateformes & YOUTUBE) {
        if (!first) printf(", ");
        printf("YouTube");
        first = false;
    }
    if (plateformes & INSTAGRAM) {
        if (!first) printf(", ");
        printf("Instagram");
        first = false;
    }
    if (plateformes & FACEBOOK) {
        if (!first) printf(", ");
        printf("Facebook");
        first = false;
    }
    if (plateformes & WHATSAPP) {
        if (!first) printf(", ");
        printf("WhatsApp");
        first = false;
    }
    if (plateformes & TIKTOK) {
        if (!first) printf(", ");
        printf("TikTok");
        first = false;
    }
    if (plateformes & SNAPCHAT) {
        if (!first) printf(", ");
        printf("Snapchat");
    }

    if (first) {
        printf("Aucune");
    }
}
void afficheCreateur(Createur createur) {
    printf("Créateur: %s\n", createur.nom);
    printf("Plateformes: ");
    affichePlateformes(createur.plateformes);
    printf("\n");
}

void afficheListe(ChainonCreateur* pListe) {
    ChainonCreateur* pCourant = pListe;

    while (pCourant != NULL) {
        afficheCreateur(pCourant->createur);
        printf("\n");
        pCourant = pCourant->pSuiv;
    }
}

void videListe(ChainonCreateur* pListe){
    ChainonCreateur* pCourant = pListe;
    while (pCourant != NULL) {
        ChainonCreateur* pASupprimer = pCourant;
        pCourant = pCourant->pSuiv;
        free(pASupprimer);
    }
}

bool createurTrouve(ChainonCreateur* pListe, char nom[], ChainonCreateur** ppChainon, ChainonCreateur** ppPrec) {
    ChainonCreateur* pCourant = pListe;
    ChainonCreateur* pPrec = NULL;

    while (pCourant != NULL && strcmp(pCourant->createur.nom, nom) < 0) {
        pPrec = pCourant;
        pCourant = pCourant->pSuiv;
    }

    *ppChainon = pCourant;
    *ppPrec = pPrec;

    return pCourant != NULL && strcmp(pCourant->createur.nom, nom) == 0;
}

void ajouteCreateur(ChainonCreateur** ppListe, Createur createur) {
    ChainonCreateur* pChainon;
    ChainonCreateur* pPrec;

    if (createurTrouve(*ppListe, createur.nom, &pChainon, &pPrec)) {
        return;
    }

    ChainonCreateur* pNouv = nouveauChainon(createur.nom, createur.plateformes, pChainon);

    if (pPrec == NULL) {
        *ppListe = pNouv;
    } else {
        pPrec->pSuiv = pNouv;
    }
}


int main(void) {
	ChainonCreateur* pDeb = NULL;
    ChainonCreateur* pChainon = NULL;
    ChainonCreateur* pPrec = NULL;
    bool trouve;
	
    int nbCreateurs = 6;
	Createur createurs[] = {
		{ "Izigaur", TWITCH|YOUTUBE|INSTAGRAM },
		{ "Bidule", INSTAGRAM|YOUTUBE|TIKTOK },
		{ "Inconnu", AUCUNE },
		{ "PiPuPiRS", YOUTUBE|WHATSAPP|TIKTOK|SNAPCHAT },
		{ "Asmodeus", FACEBOOK },
		{ "CohhCarnage", TWITCH|YOUTUBE },
	};

	for (int i = 0; i < nbCreateurs; i++) {
		ajouteCreateur(&pDeb, createurs[i]);
	}

    ajouteCreateur(&pDeb, createurs[0]);

    printf("Liste triee (sans doublon) :\n\n");
    afficheListe(pDeb);

    trouve = createurTrouve(pDeb, "Inconnu", &pChainon, &pPrec);
    printf("Test 1 : Inconnu %s\n", trouve ? "trouve" : "pas trouve");
    printf("Chainon : ");
    if (pChainon == NULL)
        printf("NULL\n");
    else
        afficheCreateur(pChainon->createur);
    printf("Precedent : ");
    if (pPrec == NULL)
        printf("NULL\n\n");
    else {
        afficheCreateur(pPrec->createur);
        printf("\n");
    }

    trouve = createurTrouve(pDeb, "CohhCarnage", &pChainon, &pPrec);
    printf("Test 2 : CohhCarnage %s\n", trouve ? "trouve" : "pas trouve");
    printf("Chainon : ");
    if (pChainon == NULL)
        printf("NULL\n");
    else
        afficheCreateur(pChainon->createur);
    printf("Precedent : ");
    if (pPrec == NULL)
        printf("NULL\n\n");
    else {
        afficheCreateur(pPrec->createur);
        printf("\n");
    }

    trouve = createurTrouve(pDeb, "PasUnStreamer", &pChainon, &pPrec);
    printf("Test 3 : PasUnStreamer %s\n", trouve ? "trouve" : "pas trouve");
    printf("Insertion avant : ");
    if (pChainon == NULL)
        printf("NULL\n");
    else
        afficheCreateur(pChainon->createur);
    printf("Precedent : ");
    if (pPrec == NULL)
        printf("NULL\n");
    else
        afficheCreateur(pPrec->createur);

	videListe(pDeb);

    return EXIT_SUCCESS;
}
