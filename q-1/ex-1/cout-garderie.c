#include <stdio.h>
#include <stdlib.h>

#define TARIF_HORAIRE 3
#define DUREE_MINIMUM 15
#define HEURE_DEBUT 1630
#define MINUTES_PAR_HEURE 60
#define MINUTES_PAR_JOUR 1440
#define HEURES_PAR_JOUR 24
#define MINUTES_PAR_QUART_DHEURE 15
#define QUARTS_DHEURE_PAR_HEURE (MINUTES_PAR_HEURE / MINUTES_PAR_QUART_DHEURE)
#define QUARTS_DHEURE_PAR_JOUR (HEURES_PAR_JOUR * QUARTS_DHEURE_PAR_HEURE)
#define TARIF_PAR_QUART_DHEURE (TARIF_HORAIRE / QUARTS_DHEURE_PAR_HEURE)
#define TARIF_PAR_JOUR (TARIF_HORAIRE * HEURES_PAR_JOUR)
#define TARIF_MAXIMUM (TARIF_PAR_JOUR * 7)

int main(void) {
    int heureDepart, heures, minutes, totalMinutes, totalQuartsDHeure, cout;

    printf("Heure de depart (HHMM) : ");
    scanf("%d", &heureDepart);

    // Conversion de l'heure de départ en minutes depuis minuit
    heures = heureDepart / 100;
    minutes = heureDepart % 100;
    totalMinutes = heures * MINUTES_PAR_HEURE + minutes;

    // Calcul du temps passé en garderie en minutes
    int tempsGarderieMinutes = totalMinutes - (HEURE_DEBUT / 100 * MINUTES_PAR_HEURE + HEURE_DEBUT % 100);
    if (tempsGarderieMinutes < 0) {
        printf("Erreur : l'heure de depart doit etre apres 16h30.\n");
        return EXIT_FAILURE;
    }

    // Calcul du nombre de quarts d'heure (en arrondissant à l'unité supérieure)
    totalQuartsDHeure = (tempsGarderieMinutes + MINUTES_PAR_QUART_DHEURE - 1) / MINUTES_PAR_QUART_DHEURE;

    // Calcul du coût total
    cout = totalQuartsDHeure * TARIF_PAR_QUART_DHEURE;
    if (cout > TARIF_MAXIMUM) {
        cout = TARIF_MAXIMUM; // Limite le coût au tarif maximum
    }

    printf("Coût de la garderie : \033[0;32m%d\033[0m euros\n", cout);

    return EXIT_SUCCESS;
}