#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include "leitura.h"

void leitura1(FILE *arqUsuarios, pessoa **pessoas, int *tamanhoPessoas) {
    int capacidade = 2;
    *tamanhoPessoas = 0;

    while (fscanf(arqUsuarios, "%50[^\n]\n%10[^\n]\n%20[^\n]\n%64[^\n]\n%10[^\n]\n",
                  (*pessoas)[*tamanhoPessoas].nome, (*pessoas)[*tamanhoPessoas].data,
                  (*pessoas)[*tamanhoPessoas].login, (*pessoas)[*tamanhoPessoas].senha,
                  (*pessoas)[*tamanhoPessoas].data2) == 5) {


        if (fscanf(arqUsuarios, "%*[^\n]\n") == EOF) {
            break; // Sai do loop se não conseguir pular a linha
        }

        (*tamanhoPessoas)++;

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

    *senhasFracas = malloc(capacidade * sizeof(SenhaFraca));

    if (*senhasFracas == NULL) {
        printf("Erro na alocação de memória");
        return;
    }

    while (fscanf(arqSenhasFracas, "%64s", (*senhasFracas)[*tamanhoSenhasFracas].senha2) == 1) {
        // Criar um buffer temporário para armazenar a senha criptografada
        (*tamanhoSenhasFracas)++;

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