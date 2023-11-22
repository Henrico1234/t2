#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include "leitura.h"
#include "criptografia.h"
#include "quebra.h"
#include "saida.h"

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
    fflush(stdin);
    criptografarSenha2(senhasFracas, tamanhoSenhasFracas);
        for (int i = 0; i < tamanhoSenhasFracas; i++) {
        printf("Senha Original: %s\nSenha Criptografada: %s\n\n", senhasFracas[i].senha2, senhasFracas[i].senhacrip);
    } 
    printf("Nome: %s\nData de Nascimento: %s\nLogin: %s\nSenha: %s\nData2: %s\n\n",
               pessoas[2].nome, pessoas[2].data,
               pessoas[2].login, pessoas[2].senha,
               pessoas[2].data2);

    int indicesPessoas[tamanhoPessoas];
    int indicesSenhasFracas[tamanhoSenhasFracas];
    int quantidadeCorrespondentes = 0;

    quebrarSenhas(pessoas, tamanhoPessoas, senhasFracas, tamanhoSenhasFracas, indicesPessoas, indicesSenhasFracas, &quantidadeCorrespondentes);
   
       // Imprime os índices correspondentes
    printf("Índices Pessoas:\n");
    for (int i = 0; i < quantidadeCorrespondentes; i++) {
        printf("%d ", indicesPessoas[i]);
    }
    printf("\n");

    printf("Índices SenhasFracas:\n");
    for (int i = 0; i < quantidadeCorrespondentes; i++) {
        printf("%d ", indicesSenhasFracas[i]);
    }
    printf("\n");

  
    //imprimir(indicesCorrespondentes, quantidadeCorrespondentes, pessoas, senhasFracas);

    fclose(arqUsuarios);
    fclose(arqSenhasFracas);

    return 0;
}