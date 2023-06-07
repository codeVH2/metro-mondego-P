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
    char nomeFicheiro[255]; //nome do ficheiro de texto que se quer ler


    readFile("bin.bin", &linha, &ps, &nParagens );


    char Stropcao[255];
    int opcao = -1  ;

    while (opcao != 9){
        printf("-------------------------------------------------------------------------------------\n");
        printf("1 - Registar paragem\n");
        printf("2 - Listar paragens\n");
        printf("3 - Apagar paragem\n");
        printf("4 - Registar linha\n");
        printf("5 - Listar linhas\n");
        printf("6 - Modificar Linha\n");
        printf("7 - Ler Ficheiro de Texto\n");
        printf("8 - Percurso numa Linha\n");
        printf("9 - Sair\n");
        printf("-------------------------------------------------------------------------------------\n");

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
                nomeFicheiro[255];
                printf("Digite o nome do ficheiro que deseja ler: \n");
                if(!fgets(nomeFicheiro, 255, stdin)){
                    fprintf(stderr, "Erro de Leitura");
                }

                nomeFicheiro[strlen(nomeFicheiro) - 1] = '\0'; //remover o \n no final da string
                fileTXT(nomeFicheiro, &ps, &nParagens, &linha);
                continue;

            case 8:
                encontraPercursoNumaLinha(linha, ps, nParagens);
                continue;

            case 9:
                break;
            default:
                printf("Opcao invalida\n");
                continue;
        }

    }

    storeInFile("bin.bin", ps, linha, nParagens);
    return 0;


}
