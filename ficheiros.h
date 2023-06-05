#ifndef PROJETO_C_FICHEIROS_H
#define PROJETO_C_FICHEIROS_H

#include "linha.h"
#include "paragem.h"

void storeInFile(char *filename, Paragem *ps, Linha *ls, int nParagens);
void readFile(char *nomeF, Linha** ls, Paragem** ps, int *nParagens);
void fileTXT(char* fileName, Paragem **ps, int *nParagens , Linha **ls);

#endif //PROJETO_C_FICHEIROS_H