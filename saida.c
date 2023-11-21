#include <stdio.h>
#include "saida.h"

void imprimirPessoasQuebradas(pessoa* pessoas, int* indicesQuebrados, int tamanhoPessoas, SenhaFraca* senhasFracas) {
    // Abre ou cria o arquivo de saída
    FILE* arquivoSaida = fopen("saida.txt", "w");
    if (arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo de saída\n");
        return;
    }

    // Loop para imprimir as informações das pessoas que tiveram as senhas quebradas
    for (int i = 0; i < tamanhoPessoas; i++) {
        if (indicesQuebrados[i] != -1) {
            fprintf(arquivoSaida, "Login: %s\n", pessoas[i].login);
            fprintf(arquivoSaida, "Data de Nascimento: %s\n", pessoas[i].data);
            fprintf(arquivoSaida, "Nome: %s\n", pessoas[i].nome);
            fprintf(arquivoSaida, "Senha: %s\n", senhasFracas[indicesQuebrados[i]].senha2);
            fprintf(arquivoSaida, "---\n");
        }
    }

    // Fecha o arquivo de saída
    fclose(arquivoSaida);
}