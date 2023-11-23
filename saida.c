#include <stdio.h>
#include <string.h>
#include "saida.h"



void imprimirCorrespondencias( pessoa *pessoas, int tamanhoPessoas, SenhaFraca *senhasFracas, int tamanhoSenhasFracas, int *indicesPessoas, int *indicesSenhasFracas, int quantidadeCorrespondentes,FILE *arqSaida) {


    for (int i = 0; i < quantidadeCorrespondentes; i++) {
        int indicePessoa = indicesPessoas[i];
        int indiceSenhaFraca = indicesSenhasFracas[i];

        // Imprime informações da pessoa
          fprintf(arqSaida, "Login: %s\nSenha: %s\nNome: %s\nData: %s\n---\n",
               pessoas[indicePessoa].login, senhasFracas[indiceSenhaFraca].senha2,
               pessoas[indicePessoa].nome, pessoas[indicePessoa].data);
    }
}