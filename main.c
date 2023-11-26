#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include "leitura.h"
#include "criptografia.h"
#include "quebra.h"
#include "saida.h"

int main(int argc, char *argv[]) {
    FILE *arqUsuarios = fopen(argv[1], "r");
    FILE *arqSenhasFracas = fopen(argv[2], "r");
    FILE *arqSaida = fopen(argv[3], "w");

    int tamanhoPessoas = 0;
    int tamanhoSenhasFracas = 0;
    

    pessoa *pessoas = malloc( 2 * sizeof(pessoa));
    SenhaFraca *senhasFracas = malloc(10 * sizeof(SenhaFraca));
 
    if (pessoas == NULL || senhasFracas == NULL) {
        printf("Erro");
        return 1;
    }
    leitura1(arqUsuarios, &pessoas, &tamanhoPessoas);
    leitura2(arqSenhasFracas, &senhasFracas, &tamanhoSenhasFracas);

    fflush(stdin);
    criptografarSenha2(senhasFracas, tamanhoSenhasFracas);
   
    int *indicesPessoas;
    int *indicesSenhasFracas;
    int quantidadeCorrespondentes = 0;

    indicesPessoas = malloc(2 * sizeof(int));
    indicesSenhasFracas = malloc(2 * sizeof(int));

    quebrarSenhas(pessoas, tamanhoPessoas, senhasFracas, tamanhoSenhasFracas, &indicesPessoas, &indicesSenhasFracas, &quantidadeCorrespondentes);


 
  
    imprimirCorrespondencias(pessoas, tamanhoPessoas, senhasFracas, tamanhoSenhasFracas, indicesPessoas, indicesSenhasFracas, quantidadeCorrespondentes, arqSaida);

    // Libera memória
    free(indicesPessoas);
    free(indicesSenhasFracas);
    free(pessoas);
    free(senhasFracas);

    fclose(arqUsuarios);
    fclose(arqSenhasFracas);
    

    return 0;
}