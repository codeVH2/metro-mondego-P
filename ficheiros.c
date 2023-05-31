#include "ficheiros.h"
#include "linha.h"
#include "paragem.h"
#include <stdio.h>

/*Nome: storeInFile
 * recebe: nome para ficheiro
 * ps- ponteiro para o array geral de paragens
 * ls- ponteiro para a liked list
 * nParagens- Numero de paragens*/
void storeInFile(char* filename, Paragem *ps, Linha* ls, int nParagens){
    
    FILE *fich;
    fich = fopen(filename, "wb");
    if(fich == NULL){
        printf("Erro ao abrir o ficheiro");
        return;
    }
    for (int i = 0; i < nParagens; i++){
        fwrite(&ps[i], sizeof(Paragem), 1, fich);
    }
    for (Linha* l = ls; l != NULL; l = l->prox){
        fwrite(l, sizeof(Linha), 1, fich);
    }
    fclose(fich);
}