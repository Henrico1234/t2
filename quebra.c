#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "quebra.h"
#include <openssl/sha.h>



void quebrarSenhas(pessoa *pessoas, int tamanhoPessoas, SenhaFraca *senhasFracas, int tamanhoSenhasFracas, int **indicesPessoas, int **indicesSenhasFracas, int *quantidadeCorrespondentes) {
    *quantidadeCorrespondentes = 0;  // Inicializa a quantidade de correspondentes

    // Determina os tamanhos necessários para os arrays
    int tamanhoNecessarioPessoas = 2;
    int tamanhoNecessarioSenhasFracas = 2;

    // Alocação dinâmica para os arrays
    *indicesPessoas = malloc(tamanhoNecessarioPessoas * sizeof(int));
    *indicesSenhasFracas = malloc(tamanhoNecessarioSenhasFracas * sizeof(int));

    for (int i = 0; i < tamanhoPessoas; i++) {
        for (int j = 0; j < tamanhoSenhasFracas; j++) {
            if (strcmp(pessoas[i].senha, senhasFracas[j].senhacrip) == 0) {
                // Senha correspondente encontrada, armazena o índice
                (*indicesPessoas)[*quantidadeCorrespondentes] = i;
                (*indicesSenhasFracas)[*quantidadeCorrespondentes] = j;
                (*quantidadeCorrespondentes)++;

                // Redimensiona os arrays se necessário
                if (*quantidadeCorrespondentes == tamanhoNecessarioPessoas) {
                    tamanhoNecessarioPessoas *= 2;
                    *indicesPessoas = realloc(*indicesPessoas, tamanhoNecessarioPessoas * sizeof(int));
                    // Verifique se a realocação foi bem-sucedida

                    tamanhoNecessarioSenhasFracas *= 2;
                    *indicesSenhasFracas = realloc(*indicesSenhasFracas, tamanhoNecessarioSenhasFracas * sizeof(int));
                    // Verifique se a realocação foi bem-sucedida
                }
            }
        }
    }
}

