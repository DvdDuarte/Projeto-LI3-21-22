/**
 * @file file_work_aux.h
 * @author grupo11
 * @brief Ficheiro que contém as funções auxiliares para trabalhar os ficheiros
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef GRUPO11_FILE_WORK_AUX_H
#define GRUPO11_FILE_WORK_AUX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glib-2.0/glib.h"


#define buffer_size 1000000

/**
 * @brief Função auxiliar na leitura de ficheiros.
 * Esta função lê o ficheiro auxiliar gerado pelas funções de leitura principais e armazena numa HashTable as informações do ficheiro.
 * @param filename O caminho com o nome de onde se encontra o ficheiro a ser lido.
 * @return A HashTable com a informação obtida pra validação de dados nas funções principais
 */
GHashTable *ler_file_aux(char *filename);

/**
 * @brief Função auxiliar na leitura de ficheiros.
 * Função que dado um indice cria um ficheiro com o nome de acordo com o indice para apresentação dos resultados do guião 2
 * @param indice O indice do ficheiro
 * @return O apontador para escrever no ficheiro
 */
FILE *output(int indice);

/**
 * @brief Função auxiliar na leitura de ficheiros.
 * Função que gera o nome dos ficheiros para a paginação
 * @param nmr_pagina 
 * @return char* 
 */
char *paginas_name(int nmr_pagina);

/**
 * @brief Função auxiliar na leitura de ficheiros.
 * Função que devolve o apontador para um ficheiro especifico usado na paginação
 * @param indice O número da página a abrir
 * @return FILE* O apontador para o ficheiro da página
 */
FILE *paginas(int indice);

/**
 * @brief Função auxiliar na leitura de ficheiros. 
 * Função que cria os ficheiros para serem usados na paginação
 * @param file_to_split O ficheiro a ser dividido em páginas
 * @param topN O número total de linhas do ficheiro a ser dividido
 */
void create_files_paginacao(char *file_to_split, int topN);

/**
 * @brief 
 * 
 * @param nmr_paginas 
 */
void remove_files_paginacao(int nmr_paginas);

#endif //GRUPO11_FILE_WORK_AUX_H
