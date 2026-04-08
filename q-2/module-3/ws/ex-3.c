#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum salle Salle;
enum salle {
    CHAMBRE = 0b0001,
    SALON = 0b0010,
    SDB = 0b0100,
    CUISINE = 0b1000
};

bool aSalleAllumee(int configuration, Salle salle) {
    return (configuration & salle) != 0;
}

void afficheConfiguration(int configuration) {
    if (aSalleAllumee(configuration, CHAMBRE)) printf("Chambre ");
    if (aSalleAllumee(configuration, SALON)) printf("Salon ");
    if (aSalleAllumee(configuration, SDB)) printf("Salle de bains ");
    if (aSalleAllumee(configuration, CUISINE)) printf("Cuisine ");
    printf("\n");
}

int main(void) {
    int configurationMatin = SALON | CHAMBRE;
    int configurationSoir = CUISINE | SDB;
    int toutAllume = CHAMBRE | SALON | SDB | CUISINE;

    printf("Configuration du matin : ");
    afficheConfiguration(configurationMatin);

    printf("Configuration du soir : ");
    afficheConfiguration(configurationSoir);

    printf("Tout allumé : ");
    afficheConfiguration(toutAllume);

    return EXIT_SUCCESS;
}
