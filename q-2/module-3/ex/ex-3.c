#include <stdio.h>
#include <stdlib.h>

typedef enum {
    CONTENU_RIEN,
    CONTENU_TRESOR,
    CONTENU_KOBOLD,
    CONTENU_GOBELIN
} Contenu;

typedef enum {
    CONNEXION_NORD = 1,
    CONNEXION_EST  = 2,
    CONNEXION_SUD  = 4,
    CONNEXION_OUEST= 8,
    CONNEXION_AUCUNE = 0
} Connexions;

typedef struct {
    Connexions connexions;
    Contenu contenu;
} Salle;

typedef struct {
    int taille;
    Salle salles[10][10];
} Donjon;

void changeCouleurEnJaune(void) { printf("\033[1;33m"); }
void changeCouleurEnRouge(void) { printf("\033[1;31m"); }
void changeCouleurEnBleu(void) { printf("\033[1;34m"); }
void changeCouleurEnNormal(void) { printf("\033[1;0m"); }

char symboleContenu(Contenu c) {
    switch (c) {
        case CONTENU_RIEN: return ' ';
        case CONTENU_TRESOR: return 'T';
        case CONTENU_KOBOLD: return 'K';
        case CONTENU_GOBELIN: return 'G';
    }
    return '?';
}

int estDanger(Contenu c) {
    return (c == CONTENU_KOBOLD || c == CONTENU_GOBELIN);
}

int estTresor(Contenu c) {
    return (c == CONTENU_TRESOR);
}

void afficheContenu(Contenu c) {
    if (estTresor(c)) changeCouleurEnJaune();
    else if (estDanger(c)) changeCouleurEnRouge();

    printf("%c", symboleContenu(c));

    changeCouleurEnNormal();
}

void afficheConnexions(Connexions c) {
    if (c == CONNEXION_AUCUNE) {
        printf("Aucune connexion");
        return;
    }

    if (c & CONNEXION_NORD) printf("Nord ");
    if (c & CONNEXION_EST) printf("Est ");
    if (c & CONNEXION_SUD) printf("Sud ");
    if (c & CONNEXION_OUEST) printf("Ouest ");
}


void decritSalle(Salle s) {
    printf("Contenu: %c | Connexions: ", symboleContenu(s.contenu));
    afficheConnexions(s.connexions);
    printf("\n");
}


void afficheLigne1(Salle s) {
    if ((s.connexions & CONNEXION_NORD) != 0) {
        printf("/   \\");
    } else {
        printf("/---\\");
    }
}

void afficheLigne2(Salle s) {
    if ((s.connexions & CONNEXION_OUEST) != 0) {
        printf("  ");
    } else {
        printf("| ");
    }

    afficheContenu(s.contenu);

    if (s.connexions & CONNEXION_EST)
        printf("  ");
    else
        printf(" |");
}

void afficheLigne3(Salle s) {
    if (s.connexions & CONNEXION_SUD) {
        printf("\\   /");
    } else {
        printf("\\---/");
    }
}

void afficheDonjon(Donjon d) {
    for (int i = 0; i < d.taille; i++) {
        for (int j = 0; j < d.taille; j++) {
            afficheLigne1(d.salles[i][j]);
        }
        printf("\n");

        for (int j = 0; j < d.taille; j++) {
            afficheLigne2(d.salles[i][j]);
        }
        printf("\n");

        for (int j = 0; j < d.taille; j++) {
            afficheLigne3(d.salles[i][j]);
        }
        printf("\n");
    }
}

Donjon donjonVideCarre(int taille) {
    Donjon d;
    d.taille = taille;

    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            d.salles[i][j].connexions = CONNEXION_AUCUNE;
            d.salles[i][j].contenu = CONTENU_RIEN;
        }
    }

    return d;
}

Donjon donjonAvecConnexions(Donjon d, Connexions c, int nums[], int n) {
    for (int k = 0; k < n; k++) {
        int num = nums[k];

        int i = num / d.taille;
        int j = num % d.taille;

        d.salles[i][j].connexions |= c;
    }
    return d;
}

Donjon donjonAvecContenu(Donjon d, Contenu c, int nums[], int n) {
    for (int k = 0; k < n; k++) {
        int num = nums[k];

        int i = num / d.taille;
        int j = num % d.taille;

        d.salles[i][j].contenu = c;
    }
    return d;
}

Donjon monDonjon(void) {

    int est[] = {0,1,2,5,8,11,13,15,16,17,20,22,23};
    int ouest[] = {1,2,3,6,9,12,14,16,17,18,21,23,24};
    int nord[] = {5,7,8,9,10,12,13,15,16,19,21,22,24};
    int sud[] = {0,2,3,4,5,7,8,10,11,14,16,17,19};

    int tresor[] = {4,6,18,20};
    int kobold[] = {5,9,17,21};
    int gobelin[] = {2,15,24};

    Donjon d = donjonVideCarre(5);

    d = donjonAvecConnexions(d, CONNEXION_EST, est, 13);
    d = donjonAvecConnexions(d, CONNEXION_OUEST, ouest, 13);
    d = donjonAvecConnexions(d, CONNEXION_NORD, nord, 13);
    d = donjonAvecConnexions(d, CONNEXION_SUD, sud, 13);

    d = donjonAvecContenu(d, CONTENU_TRESOR, tresor, 4);
    d = donjonAvecContenu(d, CONTENU_KOBOLD, kobold, 4);
    d = donjonAvecContenu(d, CONTENU_GOBELIN, gobelin, 3);

    return d;
}

int main(void) {
    Donjon d = monDonjon();

    afficheDonjon(d);

    return EXIT_SUCCESS;
}
