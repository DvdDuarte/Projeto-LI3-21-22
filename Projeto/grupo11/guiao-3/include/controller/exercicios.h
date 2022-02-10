/**
 * @file exercicios.h
 * @author grupo11
 * @brief Ficheiro que contém as funções necessárias para os guiões 1,2 e 3
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _EXERCICIOS_H_
#define _EXERCICIOS_H_

#include "../model/File_Work/file_work_validacoes.h"
#include "../model/queries/queries_estatisticas.h"
#include "../model/sgr/sgr.h"

/**
 * @brief Função mãe que chama as funções necessárias para o exercício 1 do guião 1
 * 
 * @param userpath O caminho do ficheiro de users a ser lido
 * @param commitspath O caminho do ficheiro de commits a ser lido
 * @param repospath O caminho do ficheiro de repos a ser lido
 * @return int  Retorna 1 caso o exercício 1 tenha sido executado com sucesso 0 caso contrário
 */
int exercicio1(char *userpath, char *commitspath, char *repospath);

/**
 * Função mãe que chama as funções necessárias para o exercício 2 do guião 1
 * @return Retorna 1 caso o exercício 2 tenha sido executado com sucesso 0 caso contrário
 */
int exercicio2();

/**
 * Função que executa o guião 1 do projeto
 * @param argumento Qual o exercício do guião 1 a ser executado
 * @return Retorna 1 caso o guião 1 tenha sido executado com sucesso 0 caso contrário
 */
int guiao1(char *argumento);

/**
 * Função que executa o guião 2 do projeto
 * @param queryID O id da query a ser executada
 * @param indice O indice utilizado para guardar os resultados das queries no ficheiro com aquele indice
 * @return Retorna 1 caso o guião 2 tenha sido executado com sucesso 0 caso contrário
 */
int guiao2(SGR sgr, char *queryID, int indice);

#endif //_EXERCICIOS_H_
