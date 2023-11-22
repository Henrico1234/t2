#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "quebra.h"
#include <openssl/sha.h>



void quebrarSenhas(pessoa *pessoas, int tamanhoPessoas, SenhaFraca *senhasFracas, int tamanhoSenhasFracas, int *indicesPessoas, int *indicesSenhasFracas, int *quantidadeCorrespondentes) {
    *quantidadeCorrespondentes = 0;  // Inicializa a quantidade de correspondentes

    printf("%d\n", tamanhoPessoas);
    for (int i = 0; i < tamanhoPessoas ; i++) {
        for (int j = 0; j < tamanhoSenhasFracas; j++) { 
            printf("%d\n", j);  
                      printf("Comparando: %s com %s\n", pessoas[i].senha, senhasFracas[j].senhacrip);
            if (strcmp(pessoas[i].senha, senhasFracas[j].senhacrip) == 0) {
                // Senha correspondente encontrada, armazena o índice
                indicesPessoas[*quantidadeCorrespondentes] = i;
                indicesSenhasFracas[*quantidadeCorrespondentes] = j;
                (*quantidadeCorrespondentes)++;
                
                printf("Senha correspondente Índice Pessoa: %d, Índice SenhaFracas: %d\n", i, j);
            }
        }
        printf("ssss%d\n", i);
    }
}