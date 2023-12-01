#include <openssl/sha.h>
#include <string.h>
#include "criptografia.h"

void criptografar(const char *senha, unsigned char *hashCriptografado) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);

    // Ignorar caracteres de nova linha
    for (size_t i = 0; i < strlen(senha); i++) {
        if (senha[i] != '\n' && senha[i] != '\r') {
             // Atualiza o hash com cada caractere da senha
            SHA256_Update(&sha256, &senha[i], 1);
        }
    }

     // Finaliza o hash e armazena o resultado em hashCriptografado

    SHA256_Final(hashCriptografado, &sha256);
    
}

void criptografarSenha2(SenhaFraca *senhasFracas, int tamanhoSenhasFracas) {
    for (int i = 0; i < tamanhoSenhasFracas; i++) {
        // Chama a função criptografar para obter o hash SHA-256 da senha
        criptografar(senhasFracas[i].senha2, senhasFracas[i].hashCriptografado);

        // Converte o hash para uma representação hexadecimal e armazena em senhacrip
        for (int j = 0; j < SHA256_DIGEST_LENGTH; j++) {
            sprintf(&(senhasFracas[i].senhacrip[j * 2]), "%02x", senhasFracas[i].hashCriptografado[j]);
           
        }
    }
}