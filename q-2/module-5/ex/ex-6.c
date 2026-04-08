#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct EtatVoiture {
    char *ville;
    double carburant;
};
typedef struct EtatVoiture EtatVoiture;

struct Consommation {
    char *ville_depart;
    char *ville_arrivee;
    double consommation;
};
typedef struct Consommation Consommation;

enum CodeErreur {
    ERREUR_AUCUNE,
    ERREUR_TRAJET_INCONNU,
    ERREUR_ESSENCE_INSUFFISANTE
};
typedef enum CodeErreur CodeErreur;

void afficheEtatVoiture(EtatVoiture ev) {
    printf("La voiture est à %s et a %.1f litres de carburant\n", ev.ville, ev.carburant);
}

double rechercheConsommation(char *ville_depart, char *ville_arrivee, Consommation consommations[], int nb_trajets) {
    int i = 0;

    while (
        i < nb_trajets &&
        strcmp(consommations[i].ville_depart, ville_depart) != 0 ||
        strcmp(consommations[i].ville_arrivee, ville_arrivee) != 0
    ) {
        i++;
    }

    return (i < nb_trajets) ? consommations[i].consommation : -1.0;
}

CodeErreur calculeTrajet(EtatVoiture *ev, char *ville_arrivee, Consommation consommations[], int nb_trajets) {
    double consommation = rechercheConsommation(ev->ville, ville_arrivee, consommations, nb_trajets);

    if (consommation < 0.0) {
        return ERREUR_TRAJET_INCONNU;
    } else if (consommation > ev->carburant) {
        return ERREUR_ESSENCE_INSUFFISANTE;
    } else {
        ev->carburant -= consommation;
        ev->ville = ville_arrivee;
        return ERREUR_AUCUNE;
    }
}

void voyageVers(EtatVoiture *ev, char *ville_arrivee, Consommation consommations[], int nb_trajets) {
    CodeErreur code_erreur = calculeTrajet(ev, ville_arrivee, consommations, nb_trajets);

    switch (code_erreur) {
        case ERREUR_AUCUNE:
            printf("Le trajet vers %s s'est bien passé.\n", ville_arrivee);
            break;
        case ERREUR_TRAJET_INCONNU:
            printf("Le trajet vers %s est inconnu.\n", ville_arrivee);
            break;
        case ERREUR_ESSENCE_INSUFFISANTE:
            printf("Le trajet vers %s ne peut pas se faire : essence insuffisante.\n", ville_arrivee);
            break;
    }
}

void simuleTrajet(EtatVoiture *ev, char *destinations[], int nb_destinations, Consommation consommations[], int nb_trajets) {
    for (int i = 0; i < nb_destinations; i++) {
        voyageVers(ev, destinations[i], consommations, nb_trajets);
        afficheEtatVoiture(*ev);
    }
}

int main(void) {
    EtatVoiture ev = { "Namur", 50.0 };

    Consommation consommations[] = {
		{ "Namur", "Bruxelles", 3.8 },
		{ "Bruxelles", "Namur", 3.4 },
		{ "Namur", "Charleroi", 2.2 },
		{ "Charleroi", "Namur", 2.2 },
		{ "Namur", "Arlon", 8.1 },
		{ "Arlon", "Namur", 7.8 },
		{ "Namur", "Liege", 4.1 },
		{ "Liege", "Namur", 4.2 },
		{ "Bruxelles", "Charleroi", 3.6 },
		{ "Charleroi", "Bruxelles", 3.7 },
		{ "Bruxelles", "Arlon", 11.6 },
		{ "Arlon", "Bruxelles", 11.4 },
		{ "Bruxelles", "Liege", 5.7 },
		{ "Liege", "Bruxelles", 5.7 },
		{ "Charleroi", "Arlon", 9.0 },
		{ "Arlon", "Charleroi", 9.1 },
		{ "Charleroi", "Liege", 5.4 },
		{ "Liege", "Charleroi", 5.4 },
		{ "Arlon", "Liege", 7.1 },
		{ "Liege", "Arlon", 7.0 },
	};

    char *destinations[] = { "Bruxelles", "Charleroi", "Arlon", "Liege" };
    simuleTrajet(&ev, destinations, 4, consommations, 20);

    return EXIT_SUCCESS;
}
