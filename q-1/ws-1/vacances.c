#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    int dureeVacances = 20; // en jours
    int joursEnsoleilles = 5;
    float budget = 250.0; // en euros
    float prixParJour = 10.0; // en euros
    float depensesEnsoleillees = 15.0; // en euros par jour ensoleille
    float coutTotal;
    float coutMoyen;
    int dureeVoyage = 1; // en heures
    int heureDepartInput;

    printf("Entrez l'heure de depart au format HHMM (par exemple, 1030 pour 10h30) : ");
    scanf("%d", &heureDepartInput);

    int heureDepart = heureDepartInput / 100; // Extraire les heures
    int minuteDepart = heureDepartInput % 100; // Extraire les minutes

    if (minuteDepart >= 60) {
        printf("Format invalide pour les minutes. Veuillez entrer un nombre valide.\n");
        return EXIT_FAILURE;
    }

    bool jamaisEnsoleille = joursEnsoleilles == 0;
    bool vacancesMoins15Jours = dureeVacances < 15;
    bool tousJoursEnsoleilles = joursEnsoleilles == dureeVacances;
    bool budgetInsuffisant = budget < (prixParJour * dureeVacances + depensesEnsoleillees * joursEnsoleilles);
    bool voyageMoins2Heures = dureeVoyage < 2;
    bool departApresMidi = heureDepart >= 12;
    
    coutTotal = prixParJour * dureeVacances + depensesEnsoleillees * joursEnsoleilles;
    coutMoyen = coutTotal / dureeVacances;

    bool coutTotalDepasseBudget = coutTotal > budget;
    bool coutMoyenMoins12Euros = coutMoyen < 12.0;

    printf("Il n'a jamais fait ensoleille durant les vacances : %s\n", jamaisEnsoleille ? "vrai" : "faux");
    printf("Les vacances ont dure moins de 15 jours : %s\n", vacancesMoins15Jours ? "vrai" : "faux");
    printf("Il a fait ensoleille tous les jours des vacances : %s\n", tousJoursEnsoleilles ? "vrai" : "faux");
    printf("Le budget n'est pas suffisant pour couvrir le prix des jours de vacances : %s\n", budgetInsuffisant ? "vrai" : "faux");
    printf("Le voyage dure moins de 2 heures : %s\n", voyageMoins2Heures ? "vrai" : "faux");
    printf("Le depart est prevu apres midi : %s\n", departApresMidi ? "vrai" : "faux");
    printf("Le cout total des vacances (prix par jour + depenses des jours ensoleilles) depasse le budget : %s\n", coutTotalDepasseBudget ? "vrai" : "faux");
    printf("Le cout moyen d'un jour de vacances n'atteint pas les 12 euros : %s\n", coutMoyenMoins12Euros ? "vrai" : "faux");

    return EXIT_SUCCESS;
}