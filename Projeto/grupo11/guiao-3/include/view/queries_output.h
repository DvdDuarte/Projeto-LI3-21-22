/**
 * @file queries_output.h
 * @author grupo11
 * @brief Ficheiro que contém as funções para apresentar os resultados das queries
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _QUERIES_OUTPUT_H_
#define _QUERIES_OUTPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../model/Catalogo_User/users.h"
#include "../model/table.h"

#include "view.h"

/**
 * @brief O tamanho do buffer a ser usado
 * 
 */
#define buffer_size 1000000

/**
 * @brief Função que imprime os resultados da query 1
 * 
 * @param outstream O apontador do ficheiro a escrever
 * @param bots O número de bots
 * @param org O número de org
 * @param user O número de users
 * @param time O tempo que a query demorou a ser executada
 */
void query1_output(FILE *outstream, int bots, int org, int user, int time);

/**
 * @brief Função que imprime os resultados da query 2 e 4
 * 
 * @param outstream O apontador do ficheiro a escrever
 * @param flag O número da flag a executar
 * @param avg A média obtida na query
 * @param time O tempo que a query demorou a ser executada
 */
void queries_pares_output(FILE *outstream, int flag, float avg, int time);

/**
 * @brief Função que imprime os resultados da query 3
 * 
 * @param outstream O apontador do ficheiro a escrever
 * @param bots O número de bots
 * @param time O tempo que a query demorou a ser executada
 */
void query3_output(FILE *outstream, int bots, int time);

//int paginacao_output(FILE * leitura, int page_number);

/**
 * @brief Função que imprime a página dada
 * 
 * @param ftable A tabela que contem os nomes dos ficheiros pra fazer a paginação
 * @param page_number O número da página a ser impressa
 * @param pg_total O número total de páginas
 * @param time O tempo que a query demorou a ser executada
 * @return int Retorna 0 se bem sucedida
 */
int paginacao_output(FTABLE ftable, int page_number, int topN, int time);

/**
 * @brief Função que imprime que ainda não está implementado
 * 
 */
void building();

#endif //_QUERIES_OUTPUT_H_