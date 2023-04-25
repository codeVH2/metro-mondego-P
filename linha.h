
#ifndef PROJETO_C_LINHA_H
#define PROJETO_C_LINHA_H
#include "paragem.h"
#define N 255 // tamanha maximo do nome de uma linha


/* Estrutura de uma linha */
typedef struct {
    char nome[N];           // Nome da linha
    int n_paragens;         // Número de paragens que a linha possui
    //Paragem** paragens;     // Ponteiro para um array de ponteiros das paragens
    struct linha *prox;  // Ponteiro para a próxima linha na lista ligada de linhas
} Linha;

#endif //PROJETO_C_LINHA_H
