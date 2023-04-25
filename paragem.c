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

    fgets(p.nome, N, stdin);
    p.nome[strlen(p.nome) - 1] = '\0';            // tirar o espaço
    fgets(p.codigo, 5, stdin);

    return p;
}

/* Nome:
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

    aux[(*nParagens) - 1] = p; // copia a paragem para a ultima posição do array

    return aux;
}