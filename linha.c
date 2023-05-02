#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "paragem.h"
#include "linha.h"

Linha* criarLinha(){
    Linha* linha = (Linha*) malloc(sizeof(Linha));
    printf("Nome para a linha: ");
    scanf("%s", linha->nome);
    linha->paragens = NULL;
    linha->prox = NULL;
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