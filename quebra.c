#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "quebra.h"
#include "criptografia.h"
#include <openssl/sha.h>


int* quebrarSenhas(pessoa *pessoas, int tamanhoPessoas, SenhaFraca *senhasFracas, int tamanhoSenhasFracas) {


    for (int i = 0; i < tamanhoPessoas; i++) {
        for (int j = 0; j < tamanhoSenhasFracas; j++) {
            // Comparar senhas criptografadas
            if (strcmp(pessoas[i].senha, senhasFracas[j].senhacrip) == 0) {
                // Senha encontrada, faça algo aqui
                printf("Senha quebrada para a pessoa %s\n", pessoas[i].nome);
            }
        }
    }
}