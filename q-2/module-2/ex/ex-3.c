#include <stdio.h>
#include <stdlib.h>

#define MAX_ACHATS 10

typedef struct {
    int code;
    char description[30]; // \0 included
    double prix;
} Article;

typedef struct {
    int code;
    int quantite;
} Achat;

typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct {
    Date date;
    char client[50];
    Achat achats[MAX_ACHATS];
    int nbAchats;
} Commande;

void afficheArticle(Article article) {
    printf(
        "Description: %s, Prix: %.2f\n",
        article.description, article.prix
    );
}   

void afficheCatalogue(Article catalogue[], int nbArticle) {
    for (int i = 0; i < nbArticle; i++) {
        afficheArticle(catalogue[i]);
    }
}

int indiceArticle(Article catalogue[], int nbArticle, int code) {
    int i = 0;

    while (i < nbArticle && catalogue[i].code != code) {
        i++;
    }

    return (i < nbArticle) ? (int)i : -1;
}

void afficheFacture(Commande commande, Article catalogue[], int nbArticle) {
    char nomMois[][10] = {
        "janvier",
        "fevrier",
        "mars",
        "avril",
        "mai",
        "juin",
        "juillet",
        "aout",
        "septembre",
        "octobre",
        "novembre",
        "decembre"
    };
    double total = 0.0;

    printf(
        "Facture du %d %s %d pour %s\n\n",
        commande.date.jour, nomMois[commande.date.mois - 1], commande.date.annee, commande.client
    );
    

    for (int i = 0; i < commande.nbAchats; i++) {
        int code = commande.achats[i].code;
        int quantite = commande.achats[i].quantite;
        int indice = indiceArticle(catalogue, nbArticle, code);
        
        if (indice != -1) {
            double prixUnit = catalogue[indice].prix;
            double prixTotal = prixUnit * quantite;
            total += prixTotal;
            printf(
                "%d x %s (%.2f) : %.2f\n",
                quantite, catalogue[indice].description, prixUnit, prixTotal
            );
        } else {
            printf("- Article avec code %d non trouvé\n", code);
        }
    }
    printf("\nTotal : %.2f\n", total);
}

int main(void) {
    int code, indice;
    Article catalogue[] = {
        { 10, "crayon", 0.7 },
        { 29, "surligneur", 0.9 },
        { 15, "boite de 50 bics", 16.51 },
        { 42, "pack de 10 correcteurs TippEx", 27.97 },
        { 17, "agrafeuse", 17.46 },
        { 55, "perforatrice en metal", 12.39 },
        { 71, "paire de ciseaux", 4.02 },
        { 34, "bloc notes", 4.33 }
    };
    Commande commande1 = {
        {15, 3, 2025},
        "Cunegonde Delarocheliere",
        { {17, 3}, {15,5}, {10,1} },
        3
    };
    Commande commande2 = {
        {21, 11, 2024},
        "Rico Marintense",
        { {42, 1}, {71,1}, {15,1}, {29,3}, {55,1} },
        5
    };



    int taille = sizeof(catalogue) / sizeof(catalogue[0]);
    afficheCatalogue(catalogue, taille);
    afficheFacture(commande1, catalogue, taille);
    afficheFacture(commande2, catalogue, taille);

    printf("Entrez le code de l'article à rechercher: ");
    scanf("%d", &code);
    indice = indiceArticle(catalogue, taille, code);
    if (indice != -1) {
        afficheArticle(catalogue[indice]);
    } else {
        printf("Article non trouvé\n");
    }

    return EXIT_SUCCESS;
}
