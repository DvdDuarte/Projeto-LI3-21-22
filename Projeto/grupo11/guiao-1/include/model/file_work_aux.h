#ifndef GRUPO11_FILE_WORK_AUX_H
#define GRUPO11_FILE_WORK_AUX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glib-2.0/glib.h"

/**
 * Função auxiliar na leitura de ficheiros.
 * Esta função lê o ficheiro auxiliar gerado pelas funções de leitura principais e armazena numa HashTable as informações do ficheiro.
 * @param filename O caminho com o nome de onde se encontra o ficheiro a ser lido.
 * @return A HashTable com a informação obtida pra validação de dados nas funções principais
 */
GHashTable *ler_file_aux(char *filename);

/**
 * Função que dado um indice cria um ficheiro com o nome de acordo com o indice para apresentação dos resultados do guião 2
 * @param indice O indice do ficheiro
 * @return O apontador para escrever no ficheiro
 */
FILE *output(int indice);

#endif //GRUPO11_FILE_WORK_AUX_H
