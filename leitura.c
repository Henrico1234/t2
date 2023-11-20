
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include "leitura.h"
#include "criptografia.h"

   typedef struct pessoa{
    char nome[51];
    char data[11];
    char login[21];
    char senha[65];
    char data2[11];
    }pessoa;

    typedef struct {
    char senha2[65];
    unsigned char hashCriptografado[SHA256_DIGEST_LENGTH];
    } SenhaFraca;

    

void leitura1(FILE *arqUsuarios){

    int capacidade = 2;
    int tamanho = 0;
    pessoa *pessoaAtual = malloc(capacidade * sizeof(pessoa));

    if(pessoaAtual == NULL){
        printf("erro");
        return;
    }
               
        while (fscanf(arqUsuarios, "%50[^\n]\n%10[^\n]\n%20[^\n]\n%64[^\n]\n%10[^\n]\n",
                  pessoaAtual[tamanho].nome, pessoaAtual[tamanho].data, pessoaAtual[tamanho].login,
                  pessoaAtual[tamanho].senha, pessoaAtual[tamanho].data2) == 5){

                if (fscanf(arqUsuarios, "%*[^\n]\n") == EOF) {
            break; // Sai do loop se não conseguir pular a linha
        }
        // Processa os dados da pessoa (você pode imprimir ou fazer o que quiser)
        printf("Nome: %s\nData de Nascimento: %s\nLogin: %s\nSenha: %s\nData2: %s\n\n",
               pessoaAtual[tamanho].nome, pessoaAtual[tamanho].data, pessoaAtual[tamanho].login,
               pessoaAtual[tamanho].senha, pessoaAtual[tamanho].data2);
               tamanho++;

        if (tamanho == capacidade){
            capacidade *= 2;
            pessoaAtual = realloc(pessoaAtual, capacidade * sizeof(pessoa));
            if (pessoaAtual == NULL){
                printf("erro");
                break;
            }
        }
    }
    free(pessoaAtual); 
}

    // Lendo senhas fracas e armazenando no vetor
void leitura2(FILE *arqSenhasFracas) {
    int capacidade = 10;  // Capacidade inicial do vetor
    int tamanho = 0;
    SenhaFraca *senhasFracas = malloc(capacidade * sizeof(SenhaFraca));

    // Lendo senhas fracas e armazenando no vetor
    while (fscanf(arqSenhasFracas,"%64[^\n]%*[\n\r]", senhasFracas[tamanho].senha2) == 1) {
        // Criar um buffer temporário para armazenar a senha criptografada
        unsigned char hashCriptografado[SHA256_DIGEST_LENGTH];

        // Criptografar a senha fraca diretamente
        criptografarSenhaFraca(senhasFracas[tamanho].senha2, hashCriptografado);

        // Copiar o hash criptografado para a estrutura
        memcpy(senhasFracas[tamanho].hashCriptografado, hashCriptografado, SHA256_DIGEST_LENGTH);

        tamanho++;

        if (tamanho == capacidade) {
            capacidade *= 2;
            senhasFracas = realloc(senhasFracas, capacidade * sizeof(SenhaFraca));
            if (senhasFracas == NULL) {
                printf("Erro");
            }
        }
    }

    // Imprimir senhas fracas e hashes criptografados
    for (int i = 0; i < tamanho; i++) {
        printf("Senha Fraca: %s\n", senhasFracas[i].senha2);
        printf("Hash Criptografado: ");
        for (int j = 0; j < SHA256_DIGEST_LENGTH; j++) {
            printf("%02x", senhasFracas[i].hashCriptografado[j]);
        }
        printf("\n\n");
    }
free(senhasFracas);    
}
