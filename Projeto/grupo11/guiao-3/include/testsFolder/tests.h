/**
 * @file tests.h
 * @author grupo11
 * @brief Ficheiro que contém as funções para no executável de testes
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _TESTES_H_
#define _TESTES_H_

#include <stdio.h>

/**
 * Função que compara dois ficheiros
 * @param filename1 é o nome do primeiro ficheiro
 * @param filename2 é o nome do segundo ficheiro
 */
void compere(char *filename1, char *filename2);

/**
 * Função que compara dois ficheiros para a query1
 * @param filename1 é o nome do primeiro ficheiro
 * @param filename2 é o nome do segundo ficheiro
 */
void compereQum(char *filename1,char *filename2);

/**
 * Função que apresenta o menu de testes
 * @return 0 
 */
int escreve();

#endif //_TESTES_H_
