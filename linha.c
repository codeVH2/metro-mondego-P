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
    char strindice[255];
    int option;
    mostrarParagens(ps, nParagens);

    printf("Escolha as paragens que quer adicionar a sua linha indicando o seu numero: \n");

    do{
        fgets(strindice, 255, stdin);
        option = atoi(strindice);

        if(option >= 0 && option < nParagens){
            ps2 = registarParagem(ps2, nParagens2, ps[option]);
        }


    }while(option != -1);

    return ps2;
}

/*Nome criarLinha
 * cria uma linha com os campos preenchidos
 * recebe o array das paragens e o numero de paragens para depois criar o array de paragens da linha usadndo a duncao paragensParaLinha*/
Linha* criarLinha(Paragem* ps, int nParagens){
    Linha* linha = (Linha*) malloc(sizeof(Linha));
    printf("Nome para a linha: ");
    fgets(linha->nome, N, stdin);
    linha->n_paragens = 0;
    linha->paragens = paragensParaLinha( ps ,  nParagens , &linha->n_paragens );
    linha->prox = NULL;
    return linha;
}

/*Nome: registaLinha
 * adiciona uma linha a linked list
 * recebe um ponteiro para a lista e um ponteiro para a linha
 * devolve a lista*/
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

/*Nome: mostrarLinhas
 * mostra o conteudo de cada linha da linked list*/
void mostrarLinhas(Linha* linha){

    while(linha){
        printf("Nome da linha: %s\n", linha->nome);
        printf("Numero de Paragens: %d\n", linha->n_paragens);
        printf("Paragens: \n\n");
        mostrarParagens(linha->paragens, linha->n_paragens);
        printf("\n");
        linha = linha->prox;
    }
}

/*Nome: getLinha
 * recebe o inicio da linked list das linhas e procura um nó apartir do nome.
 * devolve um ponteiro para esse nó*/
Linha* getLinha(Linha *ls){
    char nome[255];
    fgets(nome, 255, stdin);

    Linha* aux;
    aux = ls;

    while(aux != NULL){
        if(strcmp(aux->nome, nome) == 0){
            return aux;
        }else
            aux = aux->prox;
    }

    fprintf(stderr, "Nome nao da match com nenhuma paragem atual\n");
    return 0;

}

/*Nome: addParagemParaLinha
 * Recebe:
 * l- ponteiro para as linhas
 * p - ponteiro para as paragens
 * nParagens - Numero de Paragens no array de paragens
 *
 * devolve:
 * l - ponteiro para linhas*/
Linha* addParagemParaLinha(Linha* l, Paragem *p, int nParagens){
    Linha *linhaParaMudar;
    char strindice[255];
    int option;

    mostrarLinhas(l);
    linhaParaMudar = getLinha(l);
    mostrarParagens(p, nParagens);

    printf("Escolha as paragens que quer adicionar a sua Linha introduzindo o seu numero.\n");
    printf("Introduza '-1' quando acabar\n");

    do{
        fgets(strindice, 255, stdin);
        option = atoi(strindice);

        if(option >= 0 && option < nParagens){
            linhaParaMudar->paragens = registarParagem(linhaParaMudar->paragens, &linhaParaMudar->n_paragens , p[option]);
        }


    }while(option != -1);

    return l;

}