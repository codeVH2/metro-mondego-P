#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "paragem.h"
#include "linha.h"

/*Nome : paragensParaLinha
 * recebe:
 * ps - ponteiro para o array de Paragens Geral
 * nParagens - Numero de paragens nesse array
 * nParagens2 - Numero de paragens no array de paragens numa linha
 *
 * Devolve:
 * ps2 - array the paragens na linha*/
Paragem* paragensParaLinha(Paragem* ps, int nParagens, int* nParagens2){
    Paragem* ps2 = NULL; //paragens no array nas linhas
    char Strindice[255];
    int option;
    mostrarParagens(ps, nParagens);
    printf("Escolha as paragens que quer adicionar a sua linha indicando o seu numero: \n");

    do{

        fgets(Strindice, 255, stdin);
        option = atoi(Strindice);
        if(option >= 0)
           ps2 = registarParagem(ps2, nParagens2, ps[option]);
    }while(option != -1);

    return ps2;
}

Linha* criarLinha(Paragem* ps, int nParagens){
    Linha* linha = (Linha*) malloc(sizeof(Linha));
    printf("Nome para a linha: ");
    scanf("%s", linha->nome);
    linha->n_paragens = 0;
    linha->paragens = paragensParaLinha( ps ,  nParagens , &linha->n_paragens );
    linha->prox = NULL;
    return linha;
}

Linha* registarLinha(Linha *ls, Linha *l){

    //printf("%s\n", l->nome); //testes
    //mostrarParagens(l->paragens, l->n_paragens); //testes

    if(ls == NULL)
        return l;

    Linha *aux = ls;
    while(aux->prox){
        aux = aux->prox;
    }
    aux->prox = l;

    return ls;

}

void mostrarLinhas(Linha* linha){


    while(linha){
        printf("Linha: %s\n", linha->nome);
        mostrarParagens(linha->paragens, linha->n_paragens);
        printf("\n");
        linha = linha->prox;
    }

}