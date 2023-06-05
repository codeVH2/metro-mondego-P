#include "ficheiros.h"
#include "linha.h"
#include "paragem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define W 500

/*Nome: storeInFile
 * recebe: nome para ficheiro
 * ps- ponteiro para o array geral de paragens
 * ls- ponteiro para a liked list
 * nParagens- Numero de paragens*/
void storeInFile(char* filename, Paragem *ps, Linha* ls, int nParagens){
    
    FILE *fich;
    fich = fopen(filename, "wb");
    if(fich == NULL){
        fprintf(stderr,"Erro ao abrir o ficheiro\n");
        return;
    }
    fwrite(&nParagens, sizeof(int), 1, fich);
    for (int i = 0; i < nParagens; i++){
        fwrite(&ps[i], sizeof(Paragem), 1, fich);
    }
    for (Linha* l = ls; l != NULL; l = l->prox){
        fwrite(l, sizeof(Linha), 1, fich);
        for(int j = 0; j < l->n_paragens; j++){
            fwrite(&l->paragens[j], sizeof(Paragem), 1, fich);
        }
    }
    fclose(fich);
}

Paragem *readParagens(Paragem* ps, int *nParagens, FILE *f){


    if(f == NULL){
       fprintf(stderr, "Erro ao abrir o ficheiro\n");
       return NULL;
    }
    //int temp;
    fread(&(*nParagens), sizeof(int), 1, f);

    printf("%d\n", *nParagens);

    ps = (Paragem*)malloc((*nParagens) * sizeof (Paragem)); //malloc do tipo Paragem para o array de paragens geral
    //*nParagens = temp;
    if(ps == NULL){
        fprintf(stderr, "Erro ao alocar memoria para array de paragens geral\n");
        fclose(f);
        return NULL;
    }

    fread(ps, sizeof(Paragem), *nParagens, f);


    return ps;

}

Linha *readLinhas(Linha* ls, FILE *f){
    Linha l; //variavel que guarda uma linha
    Linha* noDeLinha;
    Linha* linkedList = NULL;


    while(fread(&l, sizeof(Linha), 1, f) == 1){
        noDeLinha = malloc(sizeof (Linha));
        if(noDeLinha == NULL){
            fprintf(stderr, "Erro ao alocar memoria para as Linhas\n");
            fclose(f);
            return NULL;
        }
        *noDeLinha = l;
        noDeLinha->prox = NULL; //Dar valor ao campo prox da Linha
        noDeLinha->paragens = malloc((noDeLinha->n_paragens) * sizeof (Paragem));//reallocar memoria e criar o array de paragens da linha em si
        if(noDeLinha->paragens == NULL){
            fprintf(stderr, "Erro ao alocar memoria para o array de paragens da linha\n");
            fclose(f);
            free(noDeLinha);
            return NULL;
        }

        fread(noDeLinha->paragens, sizeof(Paragem), noDeLinha->n_paragens, f); // le o array de paragens da linha
        linkedList = registarLinha(linkedList, noDeLinha);//cria a linked list de linhas;
    }
    ls = linkedList;
    fclose(f);
    return ls;
}

void readFile(char *nomeF, Linha** ls, Paragem** ps, int *nParagens){
    FILE *f;
    f = fopen(nomeF, "rb");
    if(f == NULL){
        fprintf(stderr, "Erro ao abrir o ficheiro111\n");
        return ;
    }

    *ps = readParagens( *ps, nParagens, f);
    *ls = readLinhas( *ls, f);
    fclose(f);
}


/*Nome fileTXT
 * Le informacao sobre uma linha de um ficheiro de texto
 * recebe:
 * fileName = Nome do ficheiro de texto
 * **ps = ponteiro para o ponteiro do array de paragens geral
 * *nParagens = ponteiro para o numero de paragens no array geral
 * **ls = ponteiro para o ponteiro da linked list de linhas
 *
 * Devolve:
 * Nada, atualiza diretamente pois é duplo ponteiro*/
void fileTXT(char* fileName, Paragem **ps, int *nParagens , Linha **ls){
    FILE* file = fopen(fileName, "rt");
    if(file == NULL){
        fprintf(stderr, "Erro ao abrir o ficheiro de texto\n");
        return;
    }

    //codigo baseado nos exercicios 9 do guião 4
    char nomeLinha[N];
    char codParagem[W];
    char nomeParagem[W];

    Linha *l = NULL;

    if(fscanf(file, "%[^\n]\n", nomeLinha) != 1){
        fprintf(stderr, "Erro ao ler o nome da linha\n");
        fclose(file);
        return;
    }

    l = (Linha*) malloc(sizeof(Linha));
    if(l == NULL){
        fprintf(stderr, "Erro ao alocar memoria para a linha\n");
        fclose(file);
        return;
    }
    l->paragens = NULL;
    l->n_paragens = 0;
    strcpy(l->nome, nomeLinha);
    l->prox = NULL;

    int cont = 0; //serve para contar o numero de paragens lidos, para depois dar realloc no array de paragens da linha
    while(fscanf(file, "%[^#]# %s\n", nomeParagem, codParagem) == 2){
        if(getParagem(*ps, codParagem, nParagens) != -1 || getParagemWithName(*ps, nomeParagem, nParagens) != -1){ //verifica se a paragem ja existe no programa
            fprintf(stderr, "A paragem ja se encontra registrada no programa\n");
            fclose(file);
            return;
        } else{
            *ps = realloc(*ps, (*nParagens + 1) * sizeof(Paragem));
            if(*ps == NULL){
                fprintf(stderr, "Erro ao alocar memoria para o array de paragens\n");
                fclose(file);
                return;
            }
            (*nParagens)++;
            strcpy((*ps)[*nParagens - 1].nome, nomeParagem); //preenche a nova paragem que esta no final do array
            strcpy((*ps)[*nParagens - 1].codigo, codParagem); //preenche a nova paragem que esta no final do array
        }

        l->paragens = realloc(l->paragens, (cont + 1) * sizeof(Paragem));

        strcpy(l->paragens[cont].nome, nomeParagem);
        strcpy(l->paragens[cont].codigo, codParagem);
        l->n_paragens++;
        cont++;
    }
    *ls = registarLinha(*ls, l);

    fclose(file);

}


