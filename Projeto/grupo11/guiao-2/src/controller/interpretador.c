#include "../../include/controller/interpretador.h"

int interpretador(SGR sgr, char *argumento, int indice){

    if (indice == 0) guiao1(argumento);
    else guiao2(sgr, argumento, indice);

    return 0;
}