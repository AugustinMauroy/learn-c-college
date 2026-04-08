#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int tempsSec, heures, minutes, secondes;

    printf("Temps en secondes : ");
    scanf("%d", &tempsSec);

    heures = tempsSec / 3600; // 1 heure = 3600 secondes
    minutes = (tempsSec % 3600) / 60; // 1 minute = 60 secondes
    secondes = tempsSec % 60;

    printf(
        "%d secondes = %d heure(s), %d minute(s) et %d seconde(s)\n",
        tempsSec,
        heures,
        minutes,
        secondes
    );

    return EXIT_SUCCESS;
}