/**
 * @file interpretador.h
 * @author grupo11
 * @brief Ficheiro que contém a função que faz o tratamento do input de comandos através de ficheiros
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef GUIAO_1_V3_INTERPRETADOR_H
#define GUIAO_1_V3_INTERPRETADOR_H

#include <string.h>
#include <stdio.h>
#include "exercicios.h"

/**
 * Função que serve de interpretador para os comandos a serem executados
 * @param argumento O comando a ser executado
 * @param indice utilizada pra definir se se executa o guiao um com o argumento, ou se executa o guião 2 utilizando a ele mesmo como valor para saber em que ficheiro armazenar o resultado das queries
 * @return Retorna 1 se o comando foi executado com sucesso 0 se o comando não foi executado com sucesso
 */
int interpretador(SGR sgr, char *argumento, int indice);


#endif //GUIAO_1_V3_INTERPRETADOR_H
