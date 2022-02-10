/**
 * @file file_work_validacoes.h
 * @author grupo11
 * @brief Ficheiro que contém as funções que para validar os ficheiros obtidos no exercício 1
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _FILE_WORK_H_
#define _FILE_WORK_H_

#include "../Catalogo_Commits/commits.h"
#include "../Catalogo_User/users.h"
#include "../Catalogo_Repos/repos.h"
#define buffer_size 1000000

/**
 * @brief Função que valida um ficheiro
 * Função que valida o ficheiro users.csv
 * @param file_name O nome do fichiero a ler
 */
void ler_Ficheiro_users(char* filename);

/**
 * @brief Função que valida um ficheiro
 * Função que valida o ficheiro commits.csv
 * @param filename O nome do fichiero a ler
 */
void ler_Ficheiro_commits(char *filename);

/**
 * @brief Função que valida um ficheiro
 * Função que gera o ficheiro auxiliar com os ids dos repos
 * @param filename O nome do fichiero a ler
 */
void imprime_file_repos_aux(char *filename);

/**
 * @brief Função que valida um ficheiro
 * Função que valida o ficheiro repos.csv
 * @param filename O nome do fichiero a ler
 */
void ler_Ficheiro_repos(char *filename);

/**
 * @brief Função que valida um ficheiro
 * Função que valida o ficheiro user-ok.csv
 * @return Uma *GHashTable com os users (key = id, Value = user)
 */
GHashTable *ler_file_user_ok();

/**
 * @brief Função que valida um ficheiro
 * Funçáo que gera uma *GHashtable com o conteudo do ficheiro auxiliar
 * @param filename O nome do ficheiro a ler
 * @return Uma *GHashTable
 */
GHashTable * ler_file_aux_ok(char *filename);

/**
 * @brief Função que valida um ficheiro
 * 
 * @param table Função que valida o ficheiro commits-ok.csv
 * @return Um *GArray com os commits
 */
GArray *ler_file_commits_ok(GHashTable *table);

/**
 * @brief Função que valida um ficheiro
 *  Função que valida o ficheiro repos-ok.csv
 * @param users *GHashTable com os users (key = id, Value = repos)
 * @return Uma *GHashTable com os repos (key = id, Value = repos)
 */
GHashTable  *ler_file_repos_ok(GHashTable *users);

#endif //_FILE_WORK_H_
