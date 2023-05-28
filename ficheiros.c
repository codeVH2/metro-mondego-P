#include "ficheiros.h"
#include "linha.h"
#include "paragem.h"
#include <stdio.h>

void storeInFile(char* filename, Paragem *ps, Linha* ls, int nParagens){
    
    FILE *fptr;
    fptr = fopen(filename, "wb");
    if(fptr == NULL){
        printf("Erro ao abrir o ficheiro");
        return;
    }
    for (int i = 0; i < nParagens; i++){
        fwrite(&ps[i], sizeof(Paragem), 1, fptr);
    }
    for (Linha* l = ls; l != NULL; l = l->prox){
        fwrite(l, sizeof(Linha), 1, fptr);
    }
    fclose(fptr);
}