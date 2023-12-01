#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include "leitura.h"

void leitura1(FILE *arqUsuarios, pessoa **pessoas, int *tamanhoPessoas) {
    int capacidade = 2;
    *tamanhoPessoas = 0;

    // Loop para ler os dados do arquivo de usuários

    while (fscanf(arqUsuarios, "%51[^\n]\n%11[^\n]\n%21[^\n]\n%64[^\n]\n%10[^\n]\n",
                  (*pessoas)[*tamanhoPessoas].nome, (*pessoas)[*tamanhoPessoas].data,
                  (*pessoas)[*tamanhoPessoas].login, (*pessoas)[*tamanhoPessoas].senha,
                  (*pessoas)[*tamanhoPessoas].data2) == 5) {

        // Verifica se consegue pular a linha
        if (fscanf(arqUsuarios, "%*[^\n]\n") == EOF) {
            break; // Sai do loop se não conseguir pular a linha
        }

        (*tamanhoPessoas)++;

            // Realoca memória se necessário

        if (*tamanhoPessoas == capacidade) {
            capacidade *= 2;
            *pessoas = realloc(*pessoas, capacidade * sizeof(pessoa));
            if (*pessoas == NULL) {
                printf("Erro");
                break;
            }
        }
    }
}
void leitura2(FILE *arqSenhasFracas, SenhaFraca **senhasFracas, int *tamanhoSenhasFracas) {
    int capacidade = 2;

    *tamanhoSenhasFracas = 0;

    // Aloca memória inicial para o array de senhas fracas

    *senhasFracas = malloc(capacidade * sizeof(SenhaFraca));

    if (*senhasFracas == NULL) {
        printf("Erro na alocação de memória");
        return;
    }

     // Loop para ler as senhas fracas do arquivo

    while (fscanf(arqSenhasFracas, "%33s", (*senhasFracas)[*tamanhoSenhasFracas].senha2) == 1) {
        (*tamanhoSenhasFracas)++;

          // Realoca memória se necessário

        if (*tamanhoSenhasFracas == capacidade) {
            capacidade *= 2;
            *senhasFracas = realloc(*senhasFracas, capacidade * sizeof(SenhaFraca));
            if (*senhasFracas == NULL) {
                printf("Erro na realocação de memória");
                break;
            }
        }
    }
}