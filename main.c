#include <stdio.h>
#include <stdlib.h>
#include "paragem.h"
#include "linha.h"
#include "ficheiros.h"
#include <string.h>

#define M 5

int main(void) {
    int nParagens = 0;
    Paragem *ps = NULL; //array de paragens
    Paragem p;      //uma paragem
    Linha *linha = NULL; //linked list das linhas
    Linha *nova;
    Linha* teste; //para testes SÓ
    char codigo[M];

    readFile("bin.bin", &linha, &ps, &nParagens );

    char Stropcao[255];
    int opcao = -1  ;

    while (opcao != 7){

        printf("1 - Registar paragem\n");
        printf("2 - Listar paragens\n");
        printf("3 - Apagar paragem\n");
        printf("4 - Registar linha\n");
        printf("5 - Listar linhas\n");
        printf("6 - Modificar Linha\n");
        printf("7 - Sair\n");


      if  (!fgets(Stropcao, 255, stdin)){
          fprintf(stderr, "Erro de leitura");
          continue;
      }
      opcao = atoi(Stropcao);


        switch(opcao){
            case 1:
                p = criarParagem(ps, &nParagens);
                ps = registarParagem(ps, &nParagens, p);                
                continue;

            case 2:
                printf("Selecione uma opcao:\n");
                printf("1 - Mostrar todas as paragens\n");
                printf("2 - Listar todas as linhas a que uma paragem pertence\n");

                if(!fgets(Stropcao, 255, stdin))
                {
                    fprintf(stderr, "Erro ao ler a string do stdin.\n");
                }
                int opcao2 = atoi(Stropcao);


                int pos;
                switch(opcao2) {
                    case 1:
                        mostrarParagens(ps, nParagens);
                        continue;
                    case 2:
                        printf("Digite o codigo da paragem\n");
                        if(!fgets(codigo, M, stdin)){
                            fprintf(stderr, "Erro de Leitura");
                        }
                        codigo[strlen(codigo)] = '\0';
                        mostraLinhasEmParagem(codigo, linha);

                        while (getchar() != '\n'); // Limpa o buffer de entrada

                        continue;
                }

                //teste = getLinha(linha);
                // printf("%s", teste->nome);
                continue;

            case 3:
                printf("Digite o codigo da paragem que deseja apagar: \n");

                if(!fgets(codigo, M, stdin)){
                    fprintf(stderr, "Erro de Leitura");
                }
                codigo[strlen(codigo)] = '\0';

                int posicao = getParagem(ps, codigo, &nParagens);

                if (posicao == -1) {
                    printf("Paragem nao encontrada\n");
                    while (getchar() != '\n'); // Limpa o buffer de entrada apenas se a paragem não for encontrada
                    continue;
                }

                int ver = verificaParagemNaLinha(linha,  codigo);

                if(!ver){
                    printf("Paragem numero:%d foi apagada\n", posicao);
                    ps = apagaParagem(ps, posicao, &nParagens);
                }else if(ver){
                    printf("A paragem que tentou apagar encontra-se numa linha. Apague primeiro nas linhas para usar esta opcao\n");
                }





                while (getchar() != '\n'); // Limpa o buffer de entrada

                continue;

            case 4:
                nova = criarLinha(ps, nParagens);
                linha = registarLinha(linha, nova);
                continue;

            case 5:
                mostrarLinhas(linha);
                continue;

            case 6:
                printf("Selecione uma opcao:\n");
                printf("1 - Adicionar paragens a uma linha ja existente\n");
                printf("2 - Remover paragens de uma linha\n");

                if(!fgets(Stropcao, 255, stdin))
                {
                    fprintf(stderr, "Erro ao ler a string do stdin.\n");
                }
                int opcao6 = atoi(Stropcao);

                switch(opcao6) {
                    case 1:
                        addParagemParaLinha(linha, ps, nParagens);
                        continue;
                    case 2:
                        apagaParagemEmLinha(linha);
                        while (getchar() != '\n'); // Limpa o buffer de entrada
                        continue;
                }

                continue;

            case 7:
                break;
            default:
                printf("Opcao invalida\n");
                continue;
        }

    }

    storeInFile("bin.bin", ps, linha, nParagens);
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
