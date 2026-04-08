#include <stdio.h>
#include <stdlib.h>

struct Livre {
    char auteur[50];
    char titre[50];
    int annee;
    int nbTomes;
    char serie[50];
};
typedef struct Livre Livre;

typedef struct Maillon Maillon;
struct Maillon {
    Livre livre;
    Maillon* pSuiv;
};

void afficheLivre(Livre livre) {
    printf("\"\033[32m%s\033[0m\"", livre.titre);
    if (livre.nbTomes > 0) {
        printf(", (%s Tome %d)", livre.serie, livre.nbTomes);
    }
    printf(", %s, %d", livre.auteur, livre.annee);
    printf("\n");
}

void ajouteLivre(Maillon** ppListe, Livre livre) {
    Maillon* pNouv = malloc(sizeof(Maillon));

    if (pNouv == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    pNouv->livre = livre;
    pNouv->pSuiv = *ppListe;
    *ppListe = pNouv;
}

void afficheListe(Maillon* pListe) {
    Maillon* pCourant = pListe;

    while (pCourant != NULL) {
        afficheLivre(pCourant->livre);
        pCourant = pCourant->pSuiv;
    }
}

void videListe(Maillon* pListe){
    Maillon* pCourant = pListe;
    while (pCourant != NULL) {
        Maillon* pASupprimer = pCourant;
        pCourant = pCourant->pSuiv;
        free(pASupprimer);
    }
}

int main(void) {
    Livre biblioTest[] = {
        { "Antoine de Saint-Exupery", "Le Petit Prince", 1943, 0, ""},
        { "John Green", "Qui es-tu Alaska ?", 2005, 0, "" },
        { "Antoine de Saint-Exupery", "Le Petit Prince", 1943, 0, ""},
        { "J.R.R.Tolkien", "La Communaute de l'Anneau", 1954, 1, "Le Seigneur des anneaux" },
        { "Suzanne Collins", "Hunger Games", 2008, 1, "Hunger Games" },
        { "John Green", "Nos etoiles contraires", 2012, 0, "" },
        { "Christelle Dabos", "Les Fiances de l'hiver", 2013, 0, "" },
        { "Suzanne Collins", "L'embrasement", 2009, 2, "Hunger Games" },
        { "J.R.R.Tolkien", "Bilbo le Hobbit", 1937, 0, "" },
        { "Eoin Colfer", "Artemis Fowl", 2001, 0, "" },
        { "Pierre Bottero", "La Quete d'Ewilan - L'integrale", 2003, 0, "" },
        { "John Green", "Nos etoiles contraires", 2012, 0, "" },
        { "J.R.R.Tolkien", "Le Retour du roi", 1955, 3, "Le Seigneur des anneaux" },
        { "Lois Lowry", "Le Passeur", 1993, 0, "" },
        { "Pierre Bottero", "La Quete d'Ewilan - L'integrale", 2003, 0, "" },
        { "J.R.R.Tolkien", "Les Deux Tours", 1954, 2, "Le Seigneur des anneaux" },
        { "J.R.R.Tolkien", "Le Retour du roi", 1955, 3, "Le Seigneur des anneaux" },
        { "Suzanne Collins", "La revolte", 2010, 3, "Hunger Games" },
    };

    Maillon* pDeb = NULL;
    int nbLivres = sizeof(biblioTest) / sizeof(Livre);
    for (int i = 0; i < nbLivres; i++) {
        ajouteLivre(&pDeb, biblioTest[i]);
    }
    afficheListe(pDeb);

    videListe(pDeb);

    return EXIT_SUCCESS;
}
