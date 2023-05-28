#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linha.h"
#include "paragem.h"

/* Nome: criarParagem
 * Cria uma paragem do tipo struct Paragem com nome e codigo alfanumerico*/
Paragem criarParagem(Paragem *ps, int *nParagens) {
    Paragem p;
    int repeat = 0;

    do {
        puts("Escolha um nome para a paragem: ");
        if (!fgets(p.nome, 255, stdin)) // ler o nome da paragem
        {
            fprintf(stderr, "Erro de leitura");
            strcpy(p.nome, "default");
        };

        for (int i = 0; i < *nParagens; i++) {
            if (!strcmp(p.nome, ps[i].nome)) {
                repeat = 1;
                break;
            }else
                repeat = 0;
        }
    }while (repeat);


        p.nome[strlen(p.nome)] = '\0';            // tirar o espaço
        if (!fgets(p.codigo, 5, stdin)) {
            fprintf(stderr, "Erro de leitura");
            strcpy(p.codigo, "0000");

        };
        p.codigo[strlen(p.codigo)] = '\0';            // tirar o espaço
        return p;
}


/* Nome: registarParagem
 * Regista a paragem na ultima posição do array dinamico de estruturas de paragens
 *
 * ps - O array dinamico de estruturas de paragens
 * nP - numero de paragens que constam no array
 * p - Paragem ja criada pela função criarParagem()
 *
 * return ps - devolve o array atualizado com a nova Paragem
 * */
Paragem* registarParagem(Paragem *ps, int *nP, Paragem p) {
    Paragem *aux;


    if(*nP < 0)
        *nP = 0;
    (*nP)++;


    aux = realloc(ps, (*nP) * sizeof(Paragem));
    if(aux == NULL){
        fprintf(stderr, "Não foi possivel registar uma nova paragem.\n"); //da print sem encher o stdio
        (*nP--);
        return ps;
    }

    strcpy(aux[(*nP)-1].nome, p.nome);
    strcpy(aux[(*nP)-1].codigo, p.codigo);
    //aux[*nP - 1] = p; // copia a paragem para a ultima posição do array

    return aux;
    
}

/*Nome: getParagem
 * obtem o indice de uma paragem no array de paragens.
 * recebe o codigo
 * return do indice (posição) ou -1 se não houver a paragem*/
int getParagem(Paragem *ps, char cod[], int *nParagens){
    int indice = -1;
    for(int i = 0; i < *nParagens; i++){
        if(!strcmp(cod, ps[i].codigo)){
            indice = i;
            break;
        }
    }
        return indice;
}

void mostrarParagens(Paragem *ps, int nParagens){
    for(int i = 0; i < nParagens; i++){
        printf("Paragem - %d: %s, %s\n", i, ps[i].nome, ps[i].codigo);
    }
}

/*Nome: apagaParagem
 * apaga uma paragem
 * recebe:
 * ps - ponteiro para o array
 * posicao - posicao onde esta a paragem que é para ser eliminada
 * nParagens - numero de paragens no array*/
Paragem* apagaParagem(Paragem *ps, int posicao, int *nParagens){
    if(*nParagens == 1){
        ps = NULL;
    }
    Paragem aux = ps[*nParagens - 1];
    Paragem *aux2;
    --(*nParagens);
    aux2 = realloc(ps, (*nParagens) * sizeof(Paragem));
    if(aux2 == NULL){
        fprintf(stderr, "Não foi possivel apagar a paragem.\n");
        ++(*nParagens);
        return ps;
    };
    aux2[posicao] = aux;
        return aux2;
}