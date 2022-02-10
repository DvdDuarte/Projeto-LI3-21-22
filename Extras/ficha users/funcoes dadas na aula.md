File *f = fopen();
//open() para ler bytes de informação e não caracters ao contrario do uso mais tipico de fopen()4
fgets();  // ---> Leitura de uma string de caracters num ficheiro
fscanf(); // --->

no terminal echo $? // ---> retorna o valor retornado pelo programa executado anteriormente
head -1 file // ---> retorna a primeira linha do ficheiro
wc -c file // ---> Retorna o nmr de caracteres da maior linha
ulimit -s // ---> Mostra o tamanho da stack que a maquina tem

professor desaconcelha o uso do strtok