#include <stdio.h>
#include <stdlib.h>

#define TAILLE_MAX 100

/**
 * Précondition : tabStat[0..taille-1] est un tableau statistique 
 * Postcondition : le contenu de tabStat[0..taille-1] a été affiché au format suivant : `option i : valeur[i]`
 */
void afficherTableau(int tabStat[], int taille);

/**
 * Précondition : tabStat[0..taille-1] est un tableau statistique
 * Postcondition : tabFrequences[0..taille-1] est le tableau des fréquences qui correspond à tabStat[0..taille-1]
 */
void frequences(int tabStat[], int taille, double tabFrequences[]);

/**
 * Précondition : tabStat[0..taille-1] est un tableau statistique 
 * Postcondition : tabFrequences[0..taille-1] est le tableau des fréquences qui correspond à tabStat[0..taille-1]
 */
void afficheTableauFrequences(int tabStat[], int taille);

/**
 * Précondition : tabStat[0..taille-1] est un tableau statistique 
 * Postcondition : effectifTot est la somme des valeurs de tabStat[0..taille-1]
 */
int effectifTotal(int tabStat[], int taille);


/**
 * Précondition : tabStat[0..taille-1] est un tableau statistique 
 * Postcondition : le contenu de tabStat[0..taille-1] a été affiché au format suivant
 * 
 * @note la plus grande barre fera 50 étoiles de long.
 */
void afficheBatons(int tabStat[], int taille);

/**
 * Précondition : tabStat[0..taille-1] est un tableau statistique 
 * Postcondition : max est la valeur maximale de tabStat[0..taille-1]
 */
int valeurMaximale(int tabStat[], int taille);

/**
 * Précondition : /
 * Postcondition : nbGroupes est le nombre de groupes entré par l'administrateur, vérifiant  2 ≤ nbGroupes ≤ TAILLE_MAX
 */
int nbGroupesValide(void);

/**
 * Précondition : nbGroupes ≥ 2
 * Postcondition : tabStat est un tableau statistique initialisé avec 0 vote pour chacun des nbGroupes groupes
 */
void initTabStat(int nbGroupes, int tabStat[]);

/**
 * Précondition : nbGroupes ≥ 2
 * Postcondition : vote est le numéro du groupe entré par le spectateur, vérifiant 1 ≤ vote ≤ nbGroupes ou vote = -1 (le code pour mettre un terme aux votes)
 */
int voteValide(int nbGroupes, int vote);

/**
 * Précondition : tabStat[0..nbGroupes-1] est un tableau statistique et nbGroupes ≥ 2
 * Postcondition : tabStat est mis à jour en fonction des votes entrés par les différents spectateurs
 */
void saisie(int tabStat[], int nbGroupes);

/**
     * La seconde phase (étape 7 à 11) permet d’utiliser ces fonctions dans un cas concret. En effet, à l'occasion de la prochaine saison de The Voice Belgique, la production désire utiliser un petit programme permettant aux spectateurs de voter pour la prestation qu’ils ont préférée (numérotées de 1 à N) lors de l’enregistrement du jour (hors « live »).
     * À la sortie de la salle d’enregistrement, un ordinateur est disponible. Dans un premier temps, le responsable du plateau rentrera le nombre d’artistes qui ont participé à cet enregistrement.
     * Ensuite, chaque spectateur pourra entrer le numéro de sa prestation préférée (sur base de la liste des noms d’artistes ou groupes et du titre interprété).
     * Une fois tous les votes entrés, l'administrateur pourra obtenir l'affichage des résultats (a) sous forme numérique, (b) sous forme de fréquences et (c) sous forme d’un diagramme en bâtons.
     */
int main(void) {
    int nbGroupes = nbGroupesValide();
    int tabStat[nbGroupes];

    initTabStat(nbGroupes, tabStat);
    saisie(tabStat, nbGroupes);
    printf("\nAffichage des résultats sous forme numérique :\n");
    afficherTableau(tabStat, nbGroupes);
    printf("\nAffichage des résultats sous forme de fréquences :\n");
    afficheTableauFrequences(tabStat, nbGroupes);
    printf("\nAffichage des résultats sous forme de diagramme en bâtons :\n");
    afficheBatons(tabStat, nbGroupes);

    return EXIT_SUCCESS;
}

void afficherTableau(int tabStat[], int taille) {
    for (int i = 0; i < taille; i++) {
        printf("option %d : %d\n", i + 1, tabStat[i]);
    }
}

void frequences(int tabStat[], int taille, double tabFrequences[]) {
    int total = effectifTotal(tabStat, taille);

    for (int i = 0; i < taille; i++) {
        tabFrequences[i] = ((double)tabStat[i] / total) * 100;
    }
}

void afficheTableauFrequences(int tabStat[], int taille) {
    double tabFrequences[taille];

    frequences(tabStat, taille, tabFrequences);

    for (int i = 0; i < taille; i++) {
        printf("option %d : %.2f%%\n", i + 1, tabFrequences[i]);
    }
}

int effectifTotal(int tabStat[], int taille) {
    int total = 0;

    for (int i = 0; i < taille; i++) {
        total += tabStat[i];
    }

    return total;
}

void afficheBatons(int tabStat[], int taille) {
    int maxVal = valeurMaximale(tabStat, taille);
    int echelle = 1;

    // Échelle adaptative : si maxVal < 50, on ajuste pour que la plus grande barre ait au moins 10 étoiles
    if (maxVal > 0 && maxVal < 10) {
        echelle = 5;
    } else if (maxVal > 0 && maxVal < 50) {
        echelle = 50 / maxVal;
    }

    for (int i = 0; i < taille; i++) {
        printf("option %d : ", i + 1);
        for (int j = 0; j < tabStat[i] * echelle; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int valeurMaximale(int tabStat[], int taille) {
    int max = tabStat[0];

    for (int i = 1; i < taille; i++) {
        if (tabStat[i] > max) {
            max = tabStat[i];
        }
    }

    return max;
}

int nbGroupesValide() {
    int nbGroupes;

    do {
        printf("Entrez le nombre de groupes (2-%d): ", TAILLE_MAX);
        scanf("%d", &nbGroupes);
    } while (nbGroupes < 2 || nbGroupes > TAILLE_MAX);

    return nbGroupes;
}

void initTabStat(int nbGroupes, int tabStat[]) {
    for (int i = 0; i < nbGroupes; i++) {
        tabStat[i] = 0;
    }
}

int voteValide(int nbGroupes, int vote) {
    do {
        printf("Entrez le numéro du groupe (1-%d) ou -1 pour terminer: ", nbGroupes);
        scanf("%d", &vote);
    } while (vote != -1 && (vote < 1 || vote > nbGroupes));

    return vote;
}

void saisie(int tabStat[], int nbGroupes) {
    int vote;

    vote = voteValide(nbGroupes, vote);

    while (vote != -1) {
        tabStat[vote - 1]++;
        vote = voteValide(nbGroupes, vote);
    }
}
