# projeto 2 programação de computadores 1
## autor
Nome:Henrico Costa Correia <br>
Instituição: Instituto Fedaral De Brasília <br>
Disciplina: PC1 (Daniel Saad) <br>

### Descrição do codigo(implementação)
O codigo tem como intuito quebrar senhas fracas de usuarios, ele faz a leitura de dois arquivos por linha de comando, um com as informações do usuario e sua senha cripitograda, e o outro varias senhas fracas, após isso ele cripitografa as senhas fracas e compara com cada senha dos usuarios se for igaul ele em um arquivo de saida ira imprimir os arquivos dos usuarios junto com sua senha descripitografada

### Modo de Uso
para compilar o codigo, na pasta que ele estiver, execute o seguinte comando no terminal:
make (fara com que todos os files compilem de uma vez)
logo após escreva "./main ( nome do arquivo de usarios) (nome do de senhas fracas) (nome do de saida)"

**Saida**
Será totalmente no arquivo saida, nada no terminal.

### Cosiderações finais
Esse projeto teve como pontos principais a alocação dinamica, ja que nao temos acesso a qauntas pessoas são no total, nem senhas,o uso de arquvios e struct(registros); juntamente com a biblioteca openssl