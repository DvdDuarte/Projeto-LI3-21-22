/**
 * @file table.h
 * @author grupo11
 * @brief Ficheiro que contém as funções para trabalhar com FTABLE
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _TABLE_H_
#define _TABLE_H_

#define buffer_size 1000000

/**
 * @brief Lista duplamente ligada que guarda a informação do nome do ficheiro para realizar a paginação
 * Será designada neste projeto como uma tabela
 */
typedef struct file_node NFTABLE, *FTABLE;

/**
 * @brief Função que inicia uma FTABLE com um nó e informação contido no mesmo
 * @param new_data Informação a ser adicionada ao nó
 * @return FTABLE A ftable atualizada
 */
FTABLE init_ftable(FILE *new_data);

/**
 * @brief Função que dado um apontador de um Ficheiro e uma FTABLE preenche a FTABLE com os parametros necessários para fazer a paginação.
 * (Com as restrições impostas pelo nosso programa, por ex a distancia entre cada apontador tem de ser de 19 linhas)
 * @param ftable A tabela que contem os nomes dos ficheiros pra fazer a paginação
 * @param leitura O descritor a ser usado para preencher a FTABLE
 * @return FTABLE A ftable atualizada
 */
FTABLE fill_ftable(FTABLE ftable, int topN);

/**
 * @brief Função que retorna a informação do nó da ftable
 * 
 * @param ftable A tabela que contem os nomes dos ficheiros pra fazer a paginação
 * @return char* O nome do ficheiro que está contido na ftable
 */
char * get_ftable_data(FTABLE ftable);

/**
 * @brief Função que retorna o próximo nó da ftable
 * 
 * @param ftable A tabela que contem os nomes dos ficheiros pra fazer a paginação 
 * @return FTABLE O próximo nó da ftable
 */
FTABLE get_ftable_next(FTABLE ftable);

/**
 * @brief Função que retorna o nó anterior da ftable
 * 
 * @param ftable  tabela que contem os nomes dos ficheiros pra fazer a paginação 
 * @return FTABLE O nó anterior da ftable
 */
FTABLE get_ftable_prev(FTABLE ftable);

/**
 * @brief Função que adiniona um nodo a uma FTABLE
 * @param ftable A tabela que contem os nomes dos ficheiros pra fazer a paginação
 * @param new_data O novo apontador do ficheiro a ser inserido
 * @return FTABLE A ftable atualizada
 */
FTABLE ftable_add_node(FTABLE ftable, char *new_data);

#endif