#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include "leitura.h"
#include "criptografia.h"
//#include "quebra.h"

int main(int argc, char *argv[]) {
    FILE *arqUsuarios = fopen(argv[1], "r+");
    FILE *arqSenhasFracas = fopen(argv[2], "r+");

    int tamanhoPessoas = 0;
    int tamanhoSenhasFracas = 0;

    pessoa *pessoas = malloc( 2 * sizeof(pessoa));
    SenhaFraca *senhasFracas = malloc(10 * sizeof(SenhaFraca));
 
    if (pessoas == NULL || senhasFracas == NULL) {
        printf("Erro");
        return 1;
    }
    leitura1(arqUsuarios, pessoas, &tamanhoPessoas);
    leitura2(arqSenhasFracas, senhasFracas, &tamanhoSenhasFracas);
        for (int i = 0; i < tamanhoSenhasFracas; i++) {
                 criptografarSenha2(senhasFracas, tamanhoSenhasFracas);
        printf("Senha Original: %s\nSenha Criptografada: %s\n\n", senhasFracas[i].senha2, senhasFracas[i].senhacrip);
    } 
   
    //quebrarSenhas(pessoas, tamanhoPessoas, senhasFracas, tamanhoSenhasFracas);

    fclose(arqUsuarios);
    fclose(arqSenhasFracas);

    return 0;
}