#include <stdio.h>
#include <stdlib.h>
#include "paragem.h"
#include "linha.h"
#include <string.h>



int main(void) {
    int nParagens = 0;
    Paragem *ps = NULL; //array de paragens
    Paragem p;      //uma paragem
    Linha *linha = NULL; //linked list das linhas
    Linha *nova;
    char nome[10];



    char Stropcao[255];
    int opcao;

    while (opcao != 7){

        printf("1 - Registar paragem\n");
        printf("2 - Listar paragens\n");
        printf("3 - Apagar paragem\n");
        printf("4 - Registar linha\n");
        printf("5 - Listar linhas\n");
        printf("6 - Apagar linha\n");
        printf("7 - Sair\n");

      if  (!fgets(Stropcao, 255, stdin)){
          fprintf(stderr, "Erro de leitura");
          continue;
      }
      opcao = atoi(Stropcao);

        switch(opcao){
            case 1:
                p = criarParagem();
                ps = registarParagem(ps, &nParagens, p);                
                continue;
            case 2:
                mostrarParagens(ps, nParagens);
                continue;
            case 3:
                if(!fgets(nome, 255, stdin)){
                    fprintf(stderr, "Erro de Leitura");
                }
                nome[strlen(nome)] = '\0';
                int posicao = getParagem(ps, nome, &nParagens);
                printf("%d\n", posicao);
                ps = apagaParagem(ps, posicao, &nParagens);
                continue;
            case 4:
                nova = criarLinha(ps, nParagens);
                registarLinha(linha, nova);
                continue;
            case 5:
                mostrarLinhas(linha);
                continue;
            default:
                printf("Opcao invalida\n");
                continue;
        }
    }

    return 0;

    /*p = criarParagem();
    ps = registarParagem(ps, &nParagens, p);
    p = criarParagem();
    ps = registarParagem(ps, &nParagens, p);
    p = criarParagem();
    ps = registarParagem(ps, &nParagens, p);

    mostrarParagens(ps, nParagens);


    printf("%d\n", nParagens);

    char nome[10];
    fgets(nome, 10, stdin);
    nome[strlen(nome) - 1] = '\0';

    int posicao = getParagem(ps, nome, &nParagens);
    printf("%d\n", posicao);

    apagaParagem(ps, posicao, &nParagens);

    mostrarParagens(ps, nParagens);*/

   
}
