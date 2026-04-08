#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define TAILLE_NOMBRE 5

// Fonction pour obtenir un chiffre à une position donnée
int chiffreEnPosition(int nombre, int position) {
    for (int i = 1; i < position; i++) {
        nombre /= 10;
    }
    return nombre % 10;
}

// Fonction pour compter le nombre de chiffres dans un nombre
int nbChiffres(int nombre) {
    int taille = 0;
    while (nombre > 0) {
        taille++;
        nombre /= 10;
    }
    return taille;
}

// Fonction pour vérifier si une proposition est valide
bool estPropositionValide(int proposition) {
    if (nbChiffres(proposition) != TAILLE_NOMBRE) {
        return false;
    }
    /*for (int i = 1; i <= TAILLE_NOMBRE; i++) {
        if (chiffreEnPosition(proposition, i) == 0) {
            return false;
        }
    }*/
    int i = 1;

    while (i <= TAILLE_NOMBRE && chiffreEnPosition(proposition, i) == 0) {
        i++;
    }
    
    return i == TAILLE_NOMBRE;
}

// Fonction pour lire une proposition valide
int propositionLue(void) {
    int proposition;
    /*do {
        printf("Entrez une proposition de %d chiffres sans zéro : ", TAILLE_NOMBRE);
        scanf("%d", &proposition);
        if (!estPropositionValide(proposition)) {
            printf("Proposition invalide. Veuillez réessayer.\n");
        }
    } while (!estPropositionValide(proposition));*/

    printf("Entrez une proposition de %d chiffres sans zéro : ", TAILLE_NOMBRE);
    scanf("%d", &proposition);

    while (!estPropositionValide(proposition)) {
        printf("Proposition invalide. Veuillez réessayer.\n");
        scanf("%d", &proposition);
    }
    
    return proposition;
}

// Fonction pour calculer la réponse
int reponse(int proposition, int cible) {
    int nbChiffresEgaux = 0, nbChiffresInférieurs = 0;
    int chiffreProposition, chiffreCible;

    for (int i = 1; i <= TAILLE_NOMBRE; i++) {
        chiffreProposition = chiffreEnPosition(proposition, i);
        chiffreCible = chiffreEnPosition(cible, i);

        if (chiffreProposition == chiffreCible) {
            nbChiffresEgaux++;
        } else if (chiffreProposition < chiffreCible) {
            nbChiffresInférieurs++;
        }
    }
    return nbChiffresEgaux * 10 + nbChiffresInférieurs;
}

// Fonction pour afficher la réponse
void afficherReponse(int proposition, int reponse) {
    int nbChiffresEgaux = reponse / 10;
    int nbChiffresInférieurs = reponse % 10;
    int nbChiffresSupérieurs = TAILLE_NOMBRE - nbChiffresEgaux - nbChiffresInférieurs;
    printf("Proposition : %d\n", proposition);
    printf("%d chiffre(s) correct(s), %d trop petit(s), %d trop grand(s).\n",
           nbChiffresEgaux, nbChiffresInférieurs, nbChiffresSupérieurs);
}

// Fonction pour générer un nombre aléatoire
int nombreAleatoire(void) {
    int nombre = 0;
    time_t t;
    srand((unsigned) time(&t));

    for (int i = 0; i < TAILLE_NOMBRE; i++) {
        int chiffre = rand() % 8 + 1;
        nombre = nombre * 10 + chiffre;
    }

    return nombre;
}

int main(void) {
    int cible = nombreAleatoire();
    int essais = 0;
    int proposition;
    int rep;

    printf("Bienvenue dans le jeu Number \"MasterMind\" !\n");
    printf("Essayez de deviner le nombre secret de %d chiffres (sans zéro).\n", TAILLE_NOMBRE);
    printf("DEBUG: Le nombre cible est %d\n", cible); // Ligne de debug, à retirer en production

    /*do {
        proposition = propositionLue();
        essais++;
        if (proposition != cible) {
            rep = reponse(proposition, cible);
            afficherReponse(proposition, rep);
        }
    } while (proposition != cible);*/

    proposition = propositionLue();
    essais++;

    while (proposition != cible) {
        rep = reponse(proposition, cible);
        afficherReponse(proposition, rep);
        proposition = propositionLue();
        essais++;
    }

    printf("Félicitations ! Vous avez trouvé le nombre %d en %d essais.\n", cible, essais);

    return EXIT_SUCCESS;
}