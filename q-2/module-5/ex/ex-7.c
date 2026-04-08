#include <stdlib.h>
#include <stdio.h>

enum CodeInstruction { AFFECTE, AFFICHE, AJOUTE, MULTIPLIE, SI_PAS_ZERO, EXIT };
typedef enum CodeInstruction CodeInstruction;

struct Instruction {
    CodeInstruction code;
    int arg1;
    int arg2;
};
typedef struct Instruction Instruction;

struct Etat {
    int registres[10];
    Instruction* prochaine_instruction;
};
typedef struct Etat Etat;


void executeInstruction(Etat* pEtat){
    Instruction* instr = pEtat->prochaine_instruction;

    switch(instr->code){
        case AFFECTE:
            pEtat->registres[instr->arg1] = instr->arg2;
            break;
        case AFFICHE:
            printf("%d\n", pEtat->registres[instr->arg1]);
            break;
        case AJOUTE:
            pEtat->registres[instr->arg1] += instr->arg2;
            break;
        case MULTIPLIE:
            pEtat->registres[instr->arg1] *= instr->arg2;
            break;
        case SI_PAS_ZERO:
            if(pEtat->registres[instr->arg1] != 0){
                pEtat->prochaine_instruction += instr->arg2; // saut relatif
            }
            break;
        case EXIT:
            exit(EXIT_SUCCESS);
    }
}

void executeProgramme(Instruction* programme){
    Etat etat = { .registres = {0}, .prochaine_instruction = programme };

    while(etat.prochaine_instruction != NULL){
        executeInstruction(&etat);
        etat.prochaine_instruction++;
    }
}

int main(void){
    Instruction programme[] = {
		{AFFECTE, 0, 7},
		{AFFICHE, 0, -1},
		{MULTIPLIE, 0, 2},
		{AFFICHE, 0, -1},
		{AJOUTE, 0, -4},
		{AFFICHE, 0, -1},
		{AJOUTE, 0, -1},
		{SI_PAS_ZERO, 0, -2},
		{EXIT, -1, -1}
	};
    Instruction programme2[] = {
        {AFFECTE, 0, 5},
        {AFFECTE, 4, 0},
        {AFFECTE, 1, 0},
        {AFFECTE, 2, 0},
        {AJOUTE, 1, 1},
        {AJOUTE, 2, 1},
        {AJOUTE, 4, 1},
        {AJOUTE, 0, -1},
        {SI_PAS_ZERO, 0, -3},
        {AJOUTE, 0, 1},
        {AJOUTE, 2, -1},
        {SI_PAS_ZERO, 2, -2},
        {AJOUTE, 0, -1},
        {SI_PAS_ZERO, 0, -11},
        {AFFICHE, 4, -1},
        {EXIT, -1, -1}
    };
    Instruction programme3[] = {
        {AFFECTE, 3, 7},
        {AJOUTE, 0, 1},
        {AJOUTE, 2, 1},
        {AJOUTE, 3, -1},
        {SI_PAS_ZERO, 3, -3},
        {AJOUTE, 3, 1},
        {AJOUTE, 2, -1},
        {SI_PAS_ZERO, 2, -2},
        {AFFECTE, 4, 0},
        {AFFECTE, 1, 0},
        {AFFECTE, 2, 0},
        {AJOUTE, 1, 1},
        {AJOUTE, 2, 1},
        {AJOUTE, 4, 1},
        {AJOUTE, 0, -1},
        {SI_PAS_ZERO, 0, -3},
        {AJOUTE, 0, 1},
        {AJOUTE, 2, -1},
        {SI_PAS_ZERO, 2, -2},
        {AJOUTE, 0, -1},
        {SI_PAS_ZERO, 0, -11},
        {AFFICHE, 3, -1},
        {AFFICHE, 4, -1},
        {AJOUTE, 3, -1},
        {SI_PAS_ZERO, 3, -23},
        {EXIT, -1, -1}
    };
    Instruction programme4[] = {
        {AFFECTE, 0, 15},
        {SI_PAS_ZERO, 0, 2},
        {EXIT, -1, -1},
        {AFFECTE, 1, 1},
        {AFFICHE, 1, -1},
        {AJOUTE, 0, -1},
        {SI_PAS_ZERO, 0, 2},
        {EXIT, -1, -1},
        {AFFECTE, 2, 1},
        {AFFICHE, 2, -1},
        {AJOUTE, 0, -1},
        {SI_PAS_ZERO, 0, 2},
        {EXIT, -1, -1},
        {AFFECTE, 3, 0},
        {AJOUTE, 3, 1},
        {AJOUTE, 1, -1},
        {SI_PAS_ZERO, 1, -2},
        {AJOUTE, 1, 1},
        {AJOUTE, 3, 1},
        {AJOUTE, 2, -1},
        {SI_PAS_ZERO, 2, -3},
        {AJOUTE, 2, 1},
        {AJOUTE, 3, -1},
        {SI_PAS_ZERO, 3, -2},
        {AFFICHE, 2, -1},
        {AJOUTE, 0, -1},
        {SI_PAS_ZERO, 0, -13},
        {EXIT, -1, -1}
    };

    executeProgramme(programme);
    executeProgramme(programme2);
    executeProgramme(programme3);
    executeProgramme(programme4);

    return EXIT_SUCCESS;
}
