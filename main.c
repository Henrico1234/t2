#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include "leitura.h"
int main(int argc, char *argv[]){


FILE *arqUsuarios = fopen(argv[1], "r+"); 
FILE *arqSenhasFracas = fopen(argv[2], "r+");


leitura1(arqUsuarios);
leitura2(arqSenhasFracas);

fclose(arqUsuarios);
fclose(arqSenhasFracas);


return 0;

}