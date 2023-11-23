// saida.h
#ifndef SAIDA_H
#define SAIDA_H

#include "leitura.h"

void imprimirCorrespondencias(pessoa *pessoas, int tamanhoPessoas, SenhaFraca *senhasFracas, int tamanhoSenhasFracas, int *indicesPessoas, int *indicesSenhasFracas, int quantidadeCorrespondentes, FILE *arqSaida);

#endif