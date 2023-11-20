/*#include <stdio.h>
#include <string.h>
#include "compararSenhas.h"
#include "criptografia.h"

void compararSenhas(pessoa *usuarios, int tamanhoUsuarios, SenhaFraca *senhasFracas, int tamanhoSenhasFracas) {
    for (int i = 0; i < tamanhoUsuarios; i++) {
        for (int j = 0; j < tamanhoSenhasFracas; j++) {
            if (memcmp(usuarios[i].senha, senhasFracas[j].hashCriptografado, SHA256_DIGEST_LENGTH) == 0) {
                printf("Senha do usuário %s encontrada na lista de senhas fracas.\n", usuarios[i].nome);
                // Você pode adicionar outras ações, se necessário
            }
        }
    }
}