/**
 * @file view.h
 * @author grupo11
 * @brief Ficheiro que contém as funções para apresentar as diferentes partes da interface
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _VIEW_H_
#define _VIEW_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "colors.h"

#define buffer_size 1000000

/**
 * @brief Função que imprime o frame de cima
 * 
 */
void printFrameTop();

/**
 * @brief Função que imprime o frame de baixo
 * 
 */
void printFrameBottom();

/**
 * @brief Função que imprime o frame a dizer que os users estão a ser carregados
 * 
 */
void printLoadingUsers();

/**
 * @brief Função que imprime o frame a dizer que os commits estão a ser carregados
 * 
 */
void printLoadingCommits();

/**
 * @brief Função que imprime o frame a dizer que os repos estão a ser carregados
 * 
 */
void printLoadingRepos();

/**
 * @brief Função que imprime o frame a dizer que a app está a ser construida
 * 
 */
void printBuildingApp();

/**
 * @brief Função que imprime o frame a dizer com o tempo que demorou a tal ser efetuado
 * 
 * @param time O tempo que demorou a app ser construida
 */
void printBuildingAppTime(int time);

/**
 * @brief Função que imprime o default frame
 * 
 */
void printDefaultScreen();

/**
 * @brief Função que imprime o frame de cima das queries
 * 
 */
void printQueriesTop();

/**
 * @brief Função que imprime o menu das queries
 * 
 */
void printQueriesScreen();

/**
 * @brief Função que imprime o menu das queries com a query 1 selecionada
 * 
 */
void printQueriesScreen1();

/**
 * @brief Função que imprime o menu das queries com a query 2 selecionada
 * 
 */
void printQueriesScreen2();

/**
 * @brief Função que imprime o menu das queries com a query 3 selecionada
 * 
 */
void printQueriesScreen3();

/**
 * @brief Função que imprime o menu das queries com a query 4 selecionada
 * 
 */
void printQueriesScreen4();

/**
 * @brief Função que imprime o menu das queries com a query 5 selecionada
 * 
 */
void printQueriesScreen5();

/**
 * @brief Função que imprime o menu das queries com a query 6 selecionada
 * 
 */
void printQueriesScreen6();

/**
 * @brief Função que imprime o menu das queries com a query 7 selecionada
 * 
 */
void printQueriesScreen7();

/**
 * @brief Função que imprime o menu das queries com a query 8 selecionada
 * 
 */
void printQueriesScreen8();

/**
 * @brief Função que imprime o menu das queries com a query 9 selecionada
 * 
 */
void printQueriesScreen9();

/**
 * @brief Função que imprime o menu das queries com a query 10 selecionada
 * 
 */
void printQueriesScreen10();

/**
 * @brief Função que imprime o frame de baixo das queries
 * 
 */
int printQueriesBottom();

/**
 * @brief Função que imprime a query selecionada
 * 
 * @param q A query selecionada
 */
void printQueries(int q);

/**
 * @brief Função que imprime a interface de loading
 * 
 */
void printLoadingUI();

/**
 * @brief Função que imprime o frame de baixo da paginação
 * 
 */
void printPaginacaoBottom();

/**
 * @brief Função que imprime o frame de cima da paginação
 * 
 */
void paginacaoTop(); 

#endif //_VIEW_H_