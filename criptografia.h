#ifndef CRIPTOGRAFIA_H
#define CRIPTOGRAFIA_H

#include <openssl/sha.h>

void criptografarSenhaFraca(const char *senhaFraca, unsigned char hashCriptografado[SHA256_DIGEST_LENGTH]);

#endif
