#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/controller/exercicios.h"
#include "../include/controller/interpretador.h"

int main(int argc, char *argv[]) {

    char *program_name;
    program_name = strstr(argv[0], "guiao-1");
    if(program_name == NULL) program_name = strstr(argv[0],"guiao-2");
    FILE *comandos;
    char buffer[buffer_size];
    int indice = 0;
    SGR sgr;
    sgr = init_sgr();
    //print_SGR_CR_GR_PTR(sgr);

    /* to know wich arg are being passed and wich index
    for(int i = 0; i < argc; i++)
        printf("%d %s\n", i, argv[i]);
    */
    if (argc < 2) {
        perror("Impossivel executar, não existem argumentos suficientes para correr o programa");
        exit(1);
    }


    if (strcmp(program_name, "guiao-1") == 0) {
        interpretador(sgr, argv[1], indice);
    }

    if (strcmp(program_name, "guiao-2") == 0) {
    	char filepath[] = "entrada/";
        char *teste = argv[1];
        char *filename = strcat(filepath, teste);
        comandos = fopen(filename, "r");

        if(comandos == NULL) {
            perror("File not found - commands.txt!");
            return 1;
        }

        fill_sgr(sgr, "entrada/users-g2.csv", "entrada/commits-g2.csv", "entrada/repos-g2.csv");

        for (indice = 1; fgets(buffer, buffer_size, comandos); indice++) {
            interpretador(sgr,buffer, indice);
        }
        return 0;
    }
}
