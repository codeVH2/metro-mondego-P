#ifndef PROJETO_C_PARAGEM_H
#define PROJETO_C_PARAGEM_H

#include "linha.h"
#define N 255



/* Estrutura de uma paragem */
typedef struct {
    char nome[N];        // Nome da paragem
    char codigo[5];      // Código alfanumérico único da paragem (4 caracteres)
} Paragem;


Paragem criarParagem();
Paragem* registarParagem(Paragem *ps, int *nParagens, Paragem p);
#endif //PROJETO_C_PARAGEM_H

