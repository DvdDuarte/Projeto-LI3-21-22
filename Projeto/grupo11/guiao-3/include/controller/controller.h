/**
 * @file controller.h
 * @author grupo11
 * @brief Ficheiro que contém as funções que controlam o programa
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#include "../model/queries/queries_estatisticas.h"
#include "../model/queries/queries_parametrizaveis.h"
#include "../model/table.h"
#include "../view/view.h"
#include "../controller/exercicios.h"
#include "../controller/interpretador.h"

#define buffer_size 1000000

/**
 * @brief Função que controla o programa todo
 * 
 * @param argc Os argumentos utilizados na execução do programa
 * @param argv O número dos argumentos utilizados na execução do programa
 * @return int 
 */
int controller(int argc, char *argv[]);

/**
 * @brief Função que controla o menu principal
 * 
 * @param sgr O sistema de gestão de repositórios, que contém a informação toda para executar as queries
 * @return int Retorna como a função foi terminada
 */
int menuController(SGR sgr);

/**
 * @brief Função que server para mudar a interface apresentada no programa
 * 
 * @param l A linha que deve apresentar como selecionada
 * @param q A query a ser executada caso seja diferente de 0
 * @param sgr O sistema de gestão de repositórios, que contém a informação toda para executar as queries
 * @return int Retorna 0 se a função foi bem sucedida
 */
int switchWindowQueries(int l, int q, SGR sgr);

/**
 * @brief Função que executa a query selecionada
 * 
 * @param query O número da query a ser executada
 * @param sgr O sistema de gestão de repositórios, que contém a informação toda para executar as queries 
 * @return int Retorna 0 se a função foi bem sucedida
 */
int doQuery(int query, SGR sgr);

/**
 * @brief Função que controla a apresentação dos resultados das queries em páginas
 * 
 * @param query A query a apresentar
 * @param topN O número dos top (x) a apresentar
 * @param time O tempo que a query demorou a executar
 * @return int 
 */
int paginacao_controller(int query, int topN, int time);

/**
 * @brief Função que limpa os inputs introduzidos   
 * 
 */
void clean_stdin(void);

#endif //_CONTROLLER_H_