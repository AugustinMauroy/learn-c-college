#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int nbPekets;

    printf("Combien de peket(s) voulez-vous ? ");
    scanf("%d", &nbPekets);
    printf("Je voudrais %d peket(s), s'il-vous-plait", nbPekets);

    return EXIT_SUCCESS;
}
