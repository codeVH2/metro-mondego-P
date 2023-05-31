#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linha.h"
#include "paragem.h"

void gerarCodigoAlfanumerico(char* codigo) {
    srand(time(NULL));

    for (int i = 0; i < 4; i++) {
        int randomNum = rand() % 36; // 36 caracteres alfanuméricos possíveis
        if (randomNum < 10) {
            codigo[i] = randomNum + '0'; // dígitos numéricos (0-9)
        } else {
            codigo[i] = randomNum - 10 + 'A'; // letras maiúsculas (A-Z)
        }
    }

    codigo[4] = '\0'; // adiciona o caractere nulo no final
}

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
            } else
                repeat = 0;
        }

    }while (repeat);


    char c[5];

    gerarCodigoAlfanumerico(c);

    strcpy(p.codigo, c);

    return p;
}


/* Nome: registarParagem
 * Regista a paragem na ultima posição do array dinamico de estruturas de paragens
 * ps- ponteiro para paragens
 * nP- ponteiro para numero de paragens
 * p - Paragem ja criada pela função criarParagem()
 *
 * return ps - devolve o array atualizado com a nova Paragem
 * */
Paragem* registarParagem(Paragem *ps, int *nP, Paragem p) {
    Paragem *aux;


    if(*nP < 0)
        *nP = 0;
    (*nP)++; 
    aux = (Paragem*) realloc(ps, (*nP) * sizeof(Paragem));
    if(aux == NULL){
        fprintf(stderr, "Não foi possivel registar uma nova paragem.\n"); //da print sem encher o stdio
        (*nP--);
        return ps;
    }

    strcpy(aux[(*nP)-1].nome, p.nome);
    strcpy(aux[(*nP)-1].codigo, p.codigo);


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
    if(ps == NULL){
        printf("Nao existe paragens registadas\n\n");
        return;
    }
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
    Paragem *aux;

    if(*nParagens == 1){
        *nParagens = 0;
        ps = NULL;
        return ps;
    }
    ps[posicao] = ps[*nParagens - 1];
    (*nParagens)--;
    aux = (Paragem*) realloc(ps, (*nParagens) * sizeof(Paragem));
    if(aux == NULL){
        fprintf(stderr, "Não foi possivel apagar a paragem.\n");
        return ps;
    }

    return aux;
}