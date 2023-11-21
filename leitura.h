#ifndef LEITURA_H
#define LEITURA_H

#include <stdio.h>
#include <openssl/sha.h>

typedef struct {
    char nome[51];
    char data[11];
    char login[21];
    char senha[65];
    char data2[11];

} pessoa;

typedef struct {
    char senha2[65];
    char senhacrip[65];
    unsigned char hashCriptografado[SHA256_DIGEST_LENGTH];
} SenhaFraca;


void leitura1(FILE *arqUsuarios, pessoa *pessoas, int *tamanhoPessoas);
void leitura2(FILE *arqSenhasFracas, SenhaFraca *senhasFracas, int *tamanhoSenhasFracas);

#endif // LEITURA_H