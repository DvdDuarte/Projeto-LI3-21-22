#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "../include/controller/exercicios.h"
#include "../include/controller/interpretador.h"
#include "../include/model/sgr/sgr.h"

#define buffer_size 1000000

int main(int argc, char *argv[]) {

    char *program_name;
    program_name = strstr(argv[0], "guiao-1");
    int indice = 0;

    if (argc < 2) {
        errno = 1;
        perror("Impossivel executar, não existem argumentos suficientes para correr o programa");
        exit(1);
    }


    if (strcmp(program_name, "guiao-1") == 0) {
        interpretador(argv[1], indice);
    } else {
        errno = 1;
        perror("Error");
        exit(1);
    }

}
