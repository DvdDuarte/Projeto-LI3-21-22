/**
 * @file queries_parametrizaveis.h
 * @author grupo11
 * @brief Ficheiro que contém as funções que executam as queries parametrizáveis
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef GRUPO11_QUERIES_PARAMETRIZAVEIS_H
#define GRUPO11_QUERIES_PARAMETRIZAVEIS_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../include/model/sgr/sgr.h"

int query5(int indice, int N, char* inicio, char* fim, SGR sgr);
void query6(int indice, int N,char * linguagem,SGR sgr);
void query7(int indice,int N,char * data,SGR sgr);
void query8(int indice,int N,char * data,SGR sgr);

#endif //GRUPO11_QUERIES_PARAMETRIZAVEIS_H
