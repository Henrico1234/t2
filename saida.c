#include <stdio.h>
#include <string.h>
#include "saida.h"

void imprimir(int *indices, int *indices2, int quantidade, pessoa *pessoas, SenhaFraca *senhasFracas) {
    printf("Índices Correspondentes:\n");

    for (int i = 0; i < quantidade; i++) {
        int indice = indices[i];

        // Imprime informações da pessoa com base no índice
        printf("Índice: %d\n", indice);
        printf("Login: %s\n", pessoas[indice].login);
        printf("Nome: %s\n", pessoas[indice].nome);
        printf("Data: %s\n", pessoas[indice].data);

        // Se desejar, também pode imprimir informações da struct SenhaFraca
        // Lembre-se de ajustar conforme a estrutura real da struct SenhaFraca
        printf("Senha Criptografada: %s\n", senhasFracas[indice].senha2);

        printf("\n");
    }
}