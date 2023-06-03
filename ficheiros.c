#include "ficheiros.h"
#include "linha.h"
#include "paragem.h"
#include <stdio.h>
#include <stdlib.h>

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
       fprintf(stderr, "Erro ao abrir o ficheiro111\n");
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


