#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "paragem.h"
#include "linha.h"

Paragem* paragensParaLinha(Paragem* ps, int nParagens, int* nParagens2){
    Paragem* ps2 = NULL; //paragens no array nas linhas
    char Strindice[255];
    int indice;
    mostrarParagens(ps, nParagens);
    printf("Escolha a paragem quer adicionar a sua linha indicando o seu nome: ");
    fgets(Strindice, 255, stdin);
    indice = atoi(Strindice);   

}

Linha* criarLinha(Paragem* ps, int nParagens){
    Linha* linha = (Linha*) malloc(sizeof(Linha));
    printf("Nome para a linha: ");
    scanf("%s", linha->nome);
    linha->n_paragens = 0;
    linha->paragens = paragensParaLinha(ps, nParagens, &linha->n_paragens );
    linha->prox = NULL;
    return linha;
}

Linha* registarLinha(Linha *ls, Linha *l){
    if(ls == NULL)
        return l;

    Linha *aux = ls;
    while(aux->prox){
        aux = aux->prox;
    }
    aux->prox = l;
}