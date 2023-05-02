
#ifndef PROJETO_C_LINHA_H
#define PROJETO_C_LINHA_H
#include "paragem.h"
#define N 255 // tamanha maximo do nome de uma linha


/* Estrutura de uma linha */
typedef struct Linha{
    char nome[N];           // Nome da linha
    int n_paragens;         // Número de paragens que a linha possui
    struct Paragem* paragens;     // Ponteiro array de paragens
    struct Linha *prox;  // Ponteiro para a próxima linha na lista ligada de linhas
} Linha;



#endif //PROJETO_C_LINHA_H
