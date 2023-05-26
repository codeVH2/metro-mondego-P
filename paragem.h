#ifndef PROJETO_C_PARAGEM_H
#define PROJETO_C_PARAGEM_H


#define N 255



/* Estrutura de uma paragem */
typedef struct {
    char nome[N];        // Nome da paragem
    char codigo[5];      // Código alfanumérico único da paragem (4 caracteres)
} Paragem;


Paragem criarParagem(Paragem *ps, int *nParagens);
Paragem* registarParagem(Paragem *ps, int *nParagens, Paragem p);
int getParagem(Paragem *ps, char nome[], int *nParagens);
Paragem* apagaParagem(Paragem *ps, int posicao, int *nParagens);
void mostrarParagens(Paragem *ps, int nParagens);
#endif //PROJETO_C_PARAGEM_H

