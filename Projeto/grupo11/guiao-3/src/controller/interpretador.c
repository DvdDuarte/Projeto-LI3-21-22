/**
 * @file interpretador.c
 * @author grupo11
 * @brief Ficheiro que contém a função que faz o tratamento do input de comandos através de ficheiros
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../../include/controller/interpretador.h"
#include "../../include/model/queries/queries_parametrizaveis.h"

int interpretador(SGR sgr, char *argumento, int indice){

    if(indice==0) guiao1(argumento);

    char delim[] = " ";
    char *ptr = strtok(argumento, delim);
    char *arg[10];
    int i=0;

    while(ptr != NULL){
        arg[i++]=ptr;
        ptr = strtok(NULL, delim);
    }

    if(strcmp(arg[0],"5")==0) query5(indice,atoi(arg[1]),strdup(arg[2]), strdup(arg[3]),sgr);

    else guiao2(sgr, argumento, indice);

    return 0;
}
