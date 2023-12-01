#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include "leitura.h"
#include "criptografia.h"
#include "quebra.h"
#include "saida.h"

int main(int argc, char *argv[]) {
    // Abertura dos arquivos de saida e entrada
    FILE *arqUsuarios = fopen(argv[1], "r");
    FILE *arqSenhasFracas = fopen(argv[2], "r");
    FILE *arqSaida = fopen(argv[3], "w");

    int tamanhoPessoas = 0;
    int tamanhoSenhasFracas = 0;
    
    // Aloca memória para os arrays de pessoas e senhas fracas
    pessoa *pessoas = malloc( 2 * sizeof(pessoa));
    SenhaFraca *senhasFracas = malloc(10 * sizeof(SenhaFraca));
 
    // Verifica se a alocação de memória foi bem-sucedida
    if (pessoas == NULL || senhasFracas == NULL) {
        printf("Erro");
        return 1;
    }
    // Lê dados do arquivo de usuários e senhas fracas

    leitura1(arqUsuarios, &pessoas, &tamanhoPessoas);

    leitura2(arqSenhasFracas, &senhasFracas, &tamanhoSenhasFracas);

     // Criptografa as senhas fracas

    criptografarSenha2(senhasFracas, tamanhoSenhasFracas);

       // Aloca memória para os arrays de índices e inicializa variáveis
   
    int *indicesPessoas;
    int *indicesSenhasFracas;
    int quantidadeCorrespondentes = 0;

    indicesPessoas = malloc(2 * sizeof(int));
    indicesSenhasFracas = malloc(2 * sizeof(int));

    // Encontra correspondências entre pessoas e senhas fracas
    quebrarSenhas(pessoas, tamanhoPessoas, senhasFracas, tamanhoSenhasFracas, &indicesPessoas, &indicesSenhasFracas, &quantidadeCorrespondentes);

     // Imprime correspondências no arquivo de saída
    imprimirCorrespondencias(pessoas, tamanhoPessoas, senhasFracas, tamanhoSenhasFracas, indicesPessoas, indicesSenhasFracas, quantidadeCorrespondentes, arqSaida);

    // Libera memória
    free(indicesPessoas);
    free(indicesSenhasFracas);
    free(pessoas);
    free(senhasFracas);

    // Fecha os arquivos
    fclose(arqUsuarios);
    fclose(arqSenhasFracas);
    

    return 0;
}