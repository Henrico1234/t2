#ifndef CRIPTOGRAFIA_H
#define CRIPTOGRAFIA_H

#include "leitura.h"
#include <openssl/sha.h>

void criptografarSenha2(SenhaFraca *senhasFracas, int tamanhoSenhasFracas);

#endif // CRIPTOGRAFIA_H