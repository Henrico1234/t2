#include <string.h>
#include <openssl/sha.h>
#include "criptografia.h"

void criptografarSenhaFraca(const char *senhaFraca, unsigned char hashCriptografado[SHA256_DIGEST_LENGTH]) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    
    size_t len = strlen(senhaFraca);
    for (size_t i = 0; i < len; i++) {
        // Ignorar caracteres de nova linha
        if (senhaFraca[i] != '\n' && senhaFraca[i] != '\r') {
            SHA256_Update(&sha256, &senhaFraca[i], 1);
        }
    }

    SHA256_Final(hashCriptografado, &sha256);
}