REC = main.c leitura.c criptografia.c quebra.c saida.c
EXE = $(REC:.c=.o)

main: $(EXE)
	gcc $(EXE) -o main -Wall -lssl -lcrypto

$(EXE): $(REC)
	gcc -c $(REC) -Wall -lssl -lcrypto  

clean:
	rm main $(EXE)	
