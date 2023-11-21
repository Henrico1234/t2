#ifndef QUEBRA_H
#define QUEBRA_H

#include "leitura.h"
#include <openssl/sha.h>

int* quebrarSenhas(pessoa *pessoas, int tamanhoPessoas, SenhaFraca *senhasFracas, int tamanhoSenhasFracas);

#endif // QUEBRA_H