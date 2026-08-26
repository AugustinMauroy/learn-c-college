#include <stdlib.h>
#include <stdio.h>

typedef struct noeud Noeud;
struct noeud {
    int val;
    Noeud* pSuiv;
};

void insererListe(Noeud** pListe, int val) {
    Noeud* pNouv = malloc(sizeof(Noeud));
    
    if (pNouv == NULL) {
        printf("ERREUR `malloc`\n");
        return;
    }

    pNouv->val = val;
    pNouv->pSuiv = NULL;

    // insertion en tête ou liste vide
    if (*pListe == NULL || (*pListe)->val >= val) {
        pNouv->pSuiv = *pListe;
        *pListe = pNouv;
    } else {
        Noeud* courant = *pListe;

        // recherche position
        while (courant->pSuiv != NULL && courant->pSuiv->val < val) {
            courant = courant->pSuiv;
        }

        pNouv->pSuiv = courant->pSuiv;
        courant->pSuiv = pNouv;
    }
}

void retirerListe(Noeud** pListe, int val) {
    if (*pListe == NULL) {
        printf("La liste est vide\n");
        return;
    }
    Noeud* temp;

    // suppression en tête
    if ((*pListe)->val == val) {
        temp = *pListe;
        *pListe = (*pListe)->pSuiv;
        free(temp);
        return;
    }

    Noeud* courant = *pListe;

    // recherche de l'élément à supprimer
    while (courant->pSuiv != NULL && courant->pSuiv->val != val) {
        courant = courant->pSuiv;
    }

    if (courant->pSuiv == NULL) {
        printf("Valeur non trouvée dans la liste\n");
        return;
    }

    temp = courant->pSuiv;
    courant->pSuiv = temp->pSuiv;
    free(temp);
}

void afficheListe(Noeud* list) {
    if (list == NULL) {
        printf("Aucun élément dans la liste\n");
    }

    Noeud* p = list;

    while (p != NULL) {
        printf("------\n");
        printf("| %d%s |\n", p->val, p->val >= 10 ? "" : " ");
        printf("------\n");

        if (p->pSuiv != NULL) {
            printf("  |\n");
        }

        p = p->pSuiv; // IMPORTANT
    }
}

int main(void) {
    Noeud* list = NULL;
    int userVal;

    printf("Entrez une valeur (<= 0 pour arrêter) : ");
    scanf("%d", &userVal);

    while (userVal > 0) {
        insererListe(&list, userVal);

        printf("Entrez une valeur (<= 0 pour arrêter) : ");
        scanf("%d", &userVal);
    }

    afficheListe(list);

    return EXIT_SUCCESS;
}
