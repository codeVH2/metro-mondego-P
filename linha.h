
#ifndef PROJETO_C_LINHA_H
#define PROJETO_C_LINHA_H
#include "paragem.h"
#define N 255 // tamanha maximo do nome de uma linha


/* Estrutura de uma linha */
typedef struct Linha{
    char nome[N];           // Nome da linha
    int n_paragens;         // Número de paragens que a linha possui
    Paragem* paragens;     // Ponteiro array de paragens
    struct Linha *prox;  // Ponteiro para a próxima linha na lista ligada de linhas
} Linha;


Linha* criarLinha(Paragem* ps, int nParagens);
Linha* registarLinha(Linha *ls, Linha *l);
Paragem* paragensParaLinha(Paragem* ps, int nParagens, int* nParagens2);
void mostrarLinhas(Linha* linha);
Linha* getLinha(Linha *ls);
Linha* addParagemParaLinha(Linha* l, Paragem *p, int nParagens);
void mostraLinhasEmParagem(char cod[], Linha* ls);
Linha* apagaParagemEmLinha(Linha* ls);
int verificaParagemNaLinha(Linha* ls, char cod[]);
#endif //PROJETO_C_LINHA_H
