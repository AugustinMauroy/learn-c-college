#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int code;
    char description[30]; // \0 included
    double prix;
} Article;

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


    int taille = sizeof(catalogue) / sizeof(catalogue[0]);
    afficheCatalogue(catalogue, taille);

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