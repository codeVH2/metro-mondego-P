#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linha.h"
#include "paragem.h"

/* Nome: criarParagem
 * Cria uma paragem do tipo struct Paragem com nome e codigo alfanumerico*/
Paragem criarParagem(){
    Paragem p;

    puts("Escolha um nome para a paragem: ");
    scanf("%s", p.nome);            // ler o nome da paragem
    p.nome[strlen(p.nome)] = '\0';            // tirar o espaço
    scanf("%s", p.codigo);
    p.codigo[strlen(p.codigo)] = '\0';            // tirar o espaço
    return p;
}

/* Nome: registarParagem
 * Regista a paragem na ultima posição do array dinamico de estruturas de paragens
 *
 * ps - O array dinamico de estruturas de paragens
 * nParagens - numero de paragens que constam no array
 * p - Paragem ja criada pela função criarParagem()
 *
 * return ps - devolve o array atualizado com a nova Paragem
 * */
Paragem* registarParagem(Paragem *ps, int *nParagens, Paragem p) {
    Paragem *aux;

    if(*nParagens < 0)
        *nParagens = 0;
    (*nParagens)++;

    aux = realloc(ps, (*nParagens) * sizeof(Paragem));
    if(aux == NULL){
        fprintf(stderr, "Não foi possivel registar uma nova paragem.\n"); //da print sem encher o stdio
        (*nParagens)--;
        return ps;
    }

    aux[*nParagens - 1] = p; // copia a paragem para a ultima posição do array
    
    return aux;
    
}

/*Nome: getParagem
 * obtem o indice de uma paragem no array de paragens.
 * recebe o nome
 * return do indice (posição) ou -1 se não houver a paragem*/
int getParagem(Paragem *ps, char nome[], int *nParagens){
    int indice = -1;
    for(int i = 0; i < *nParagens; i++){
        if(!strcmp(nome, ps[i].nome)){
            indice = i;
            break;
        }
        
    }
        return indice;
}

void mostrarParagens(Paragem *ps, int nParagens){
    for(int i = 0; i < nParagens; i++){
        printf("Paragem(\"%s\", \"%s\")\n", ps[i].nome, ps[i].codigo);
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