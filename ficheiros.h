#ifndef PROJETO_C_FICHEIROS_H
#define PROJETO_C_FICHEIROS_H

#include "linha.h"
#include "paragem.h"

void storeInFile(char *filename, Paragem *ps, Linha *ls, int nParagens);
void readFile(char *nomeF, Linha** ls, Paragem** ps, int *nParagens);

#endif //PROJETO_C_FICHEIROS_H