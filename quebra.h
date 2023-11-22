#ifndef QUEBRA_H
#define QUEBRA_H

#include "leitura.h"
#include <openssl/sha.h>

   void quebrarSenhas(pessoa *pessoas, int tamanhoPessoas, SenhaFraca *senhasFracas, int tamanhoSenhasFracas, int *indicesPessoas, int *indicesSenhasFracas, int *quantidadeCorrespondentes);
   
#endif // QUEBRA_H