#include <stdio.h>
#include <stdlib.h>

#define MAX_INVENTAIRE 9

typedef struct objet {
    int ref;
    char nom[20];
    int poids;
} Objet;

typedef struct pileObjets {
    int ref;
    int quantite;
} PileObjets;

typedef struct inventaire {
    int nbCasesRemplies;
    PileObjets cases[MAX_INVENTAIRE];
} Inventaire;

int trouverObjet(Objet objets[], int tailleObjets, int ref) {
    int i = 0;
    while (i < tailleObjets && objets[i].ref != ref) {
        i++;
    }
    return (i < tailleObjets) ? i : -1;
}

void afficherInventaire(Inventaire inventaire, Objet objets[], int tailleObjets) {
    int poidsTotalGrammes = 0;
    
    for (int i = 0; i < inventaire.nbCasesRemplies; i++) {
        int indexObjet = trouverObjet(objets, tailleObjets, inventaire.cases[i].ref);
        
        if (indexObjet != -1) {
            printf("%d x %s\n", inventaire.cases[i].quantite, objets[indexObjet].nom);
            poidsTotalGrammes += inventaire.cases[i].quantite * objets[indexObjet].poids;
        } else {
            printf(
                "%d x Objet inconnu (ref %d)\n",
                inventaire.cases[i].quantite, inventaire.cases[i].ref
            );
        }
    }
    
    printf("Total : %d g\n", poidsTotalGrammes);
}

PileObjets obtenirPileObjets(Objet objets[], int tailleObjets) {
    PileObjets p;
    int ref, quantite;

    printf("Entrez la référence de l'objet : ");
    scanf("%d", &ref);
    while (trouverObjet(objets, tailleObjets, ref) == -1) {
        printf("Référence inconnue, veuillez réessayer.\n");
        printf("Entrez la référence de l'objet : ");
        scanf("%d", &ref);
    }

    printf("Entrez la quantité (≥ 1) : ");
    scanf("%d", &quantite);
    while (quantite < 1) {
        printf("Quantité invalide, veuillez réessayer.\n");
        printf("Entrez la quantité (≥ 1) : ");
        scanf("%d", &quantite);
    }


    p.ref = ref;
    p.quantite = quantite;
    return p;
}

Inventaire ajouterPile(Inventaire inventaire, PileObjets pile) {
    for (int i = 0; i < inventaire.nbCasesRemplies; i++) {
        if (inventaire.cases[i].ref == pile.ref) {
            inventaire.cases[i].quantite += pile.quantite;
            printf("Objets ajoutés\n");
            return inventaire;
        }
    }

    if (inventaire.nbCasesRemplies < MAX_INVENTAIRE) {
        inventaire.cases[inventaire.nbCasesRemplies] = pile;
        inventaire.nbCasesRemplies++;
        printf("Objets ajoutés\n");
        return inventaire;
    }

    printf("Inventaire plein\n");
    return inventaire;
}

Inventaire retirerPile(Inventaire inventaire, PileObjets pile) {
    int index, i =0;
    while (i < inventaire.nbCasesRemplies && inventaire.cases[i].ref != pile.ref) {
        i++;
    }
    index = (i < inventaire.nbCasesRemplies) ? i : -1;

    if (index == -1 || inventaire.cases[index].quantite < pile.quantite) {
        printf("Inventaire insuffisant\n");
        return inventaire;
    }
    inventaire.cases[index].quantite -= pile.quantite;

    if (inventaire.cases[index].quantite == 0) {
        for (int i = index; i < inventaire.nbCasesRemplies - 1; i++) {
            inventaire.cases[i] = inventaire.cases[i + 1];
        }
        inventaire.nbCasesRemplies--;
    }

    printf("Objets retirés\n");
    return inventaire;
}

Inventaire rassemblerInventaires(Inventaire inv1, Inventaire inv2) {
    for (int i = 0; i < inv2.nbCasesRemplies; i++) {
        inv1 = ajouterPile(inv1, inv2.cases[i]);
    }
    return inv1;
}

Inventaire consoliderInventaire(Inventaire inventaire) {
    for (int i = 0; i < inventaire.nbCasesRemplies; i++) {
        for (int j = i + 1; j < inventaire.nbCasesRemplies; j++) {
            if (inventaire.cases[i].ref == inventaire.cases[j].ref) {
                inventaire.cases[i].quantite += inventaire.cases[j].quantite;
                /* Supprimer la case j en décalant */
                for (int k = j; k < inventaire.nbCasesRemplies - 1; k++) {
                    inventaire.cases[k] = inventaire.cases[k + 1];
                }
                inventaire.nbCasesRemplies--;
                j--;
            }
        }
    }
    return inventaire;
}

int main(void) {
    Objet objets[] = {
        { 117, "arc", 1000 },
        { 135, "epee courte", 1000 },
        { 57, "fleche", 25 },
        { 10, "torche", 500 },
        { 215, "pelle", 4000 },
        { 202, "grappin", 2000 },
        { 194, "seau", 1000 }
    };
    int tailleObjets = sizeof(objets) / sizeof(Objet);

    Inventaire inventairePlein = {
        MAX_INVENTAIRE,
        {
            {117,1},{10,7},{135,1},{57,32},
            {215,1},{194,1},{117,2},{10,3},{57,5}
        }
    };
    PileObjets pileTest = {202, 1}; /* ref non présente → doit déclencher "Inventaire plein" */
    inventairePlein = ajouterPile(inventairePlein, pileTest);

    printf("\n=== Test ajout combiné (même type déjà présent) ===\n");
    Inventaire inventaireTest = {
        4,
        { {117,1},{10,7},{135,1},{57,32} }
    };
    PileObjets pileComp = {10, 5};
    inventaireTest = ajouterPile(inventaireTest, pileComp);
    afficherInventaire(inventaireTest, objets, tailleObjets);

    printf("\n=== Test ajout nouvelle case ===\n");
    PileObjets pileNew = {215, 2};
    inventaireTest = ajouterPile(inventaireTest, pileNew);
    afficherInventaire(inventaireTest, objets, tailleObjets);

    Inventaire inventaire = {
        4,
        { {117,1},{10,7},{135,1},{57,32} }
    };

    char choix;
    do {
        printf("\n--- Menu ---\n");
        printf("A - Ajouter des objets\n");
        printf("R - Retirer des objets\n");
        printf("I - Afficher l'inventaire\n");
        printf("M - Rassembler avec un second inventaire\n");
        printf("C - Consolider l'inventaire\n");
        printf("Q - Quitter\n");
        printf("Votre choix : ");
        scanf(" %c", &choix);

        switch (choix) {
            case 'A': case 'a':
                inventaire = ajouterPile(inventaire, obtenirPileObjets(objets, tailleObjets));
                break;
            case 'R': case 'r':
                inventaire = retirerPile(inventaire, obtenirPileObjets(objets, tailleObjets));
                break;
            case 'I': case 'i':
                afficherInventaire(inventaire, objets, tailleObjets);
                break;
            case 'M': case 'm': {
                printf("Composition du second inventaire :\n");
                Inventaire inv2 = { 0, {} };
                char encore;
                do {
                    inv2 = ajouterPile(inv2, obtenirPileObjets(objets, tailleObjets));
                    printf("Ajouter un autre objet au second inventaire ? (O/N) : ");
                    scanf(" %c", &encore);
                } while (encore == 'O' || encore == 'o');
                inventaire = rassemblerInventaires(inventaire, inv2);
                afficherInventaire(inventaire, objets, tailleObjets);
                break;
            }
            case 'C': case 'c':
                inventaire = consoliderInventaire(inventaire);
                printf("Inventaire consolidé.\n");
                afficherInventaire(inventaire, objets, tailleObjets);
                break;
            case 'Q': case 'q':
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 'Q' && choix != 'q');

    return EXIT_SUCCESS;
}
