#include <stdio.h>
#include <stdlib.h>
#include "paragem.h"
#include "linha.h"



int main(void) {
    int nParagens = 0;
    Paragem *ps = NULL;
    Paragem p;

    p= criarParagem();

    ps = registarParagem(ps, &nParagens, p);
    p= criarParagem();
    ps = registarParagem(ps, &nParagens, p);
    p= criarParagem();
    ps = registarParagem(ps, &nParagens, p);

    for(int i = 0; i < nParagens; i++){
        printf("Paragem(\"%s\", \"%s\")\n", ps[i].nome, ps[i].codigo);
    }

    printf("%d", nParagens);
    return 0;
}
