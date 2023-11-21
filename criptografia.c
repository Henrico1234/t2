#include <openssl/sha.h>
#include <string.h>
#include "criptografia.h"

void criptografar(const char *senha, unsigned char *hashCriptografado) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);

    // Ignorar caracteres de nova linha
    for (size_t i = 0; i < strlen(senha); i++) {
        if (senha[i] != '\n' && senha[i] != '\r') {
            SHA256_Update(&sha256, &senha[i], 1);
        }
    }

    SHA256_Final(hashCriptografado, &sha256);
    
}

void criptografarSenha2(SenhaFraca *senhasFracas, int tamanhoSenhasFracas) {
    for (int i = 0; i < tamanhoSenhasFracas; i++) {
        criptografar(senhasFracas[i].senha2, senhasFracas[i].hashCriptografado);

        // Copiar a senha criptografada para o campo senhacrip
        for (int j = 0; j < SHA256_DIGEST_LENGTH; j++) {
            sprintf(&(senhasFracas[i].senhacrip[j * 2]), "%02x", senhasFracas[i].hashCriptografado[j]);
           
        }
    }
}