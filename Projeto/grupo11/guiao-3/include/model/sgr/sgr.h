/**
 * @file sgr.h
 * @author grupo11
 * @brief Ficheiro que contém as funções que para trabalhar com o SGR
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef GRUPO11_SGR_H
#define GRUPO11_SGR_H

#include "glib-2.0/glib.h"
#include "../Catalogo_Commits/catalogo_commits.h"
#include "../Catalogo_Repos/catalogo_repos.h"
#include "../Catalogo_User/catalogo_users.h"
#include "../../view/view.h"

/**
 * Estrutura de tipo de dados que contem os catalogos a serem utilizados nas queries
 */
typedef struct sgr NSGR, *SGR;

/**
 *  Função que inicia o sgr com os valores minimo, e chama as funções que inicia a os catálogos onde vão ser armazenada a informação dos ficheiros para as queries
 * @param sgr A Estrutura que contém os catálogos a serem utilizados nas queries
 */
SGR init_sgr();

/**
 * Função que preenche o SGR
 * @param sgr A Estrutura que contém os catálogos a serem utilizados nas queries
 * @param userpath Caminho onde se encontra o ficheiro de users
 * @param commitspath Caminho onde se encontra o ficheiro de commits
 * @param repospath Caminho onde se encontra o ficheiro de repos
 */
SGR fill_sgr(SGR sgr, char *userpath, char *commitspath, char *repospath);


/*DEBUG
void print_SGR_CR_GR_PTR(SGR sgr);
*/

/**
 *
 * @param sgr A Estrutura que contém os catálogos a serem utilizados nas queries
 * @return O número de utilizadores que são bots do Catálodo de Users
 */
int sgr_get_CU_bots(SGR sgr);

/**
 *
 * @param sgr A Estrutura que contém os catálogos a serem utilizados nas queries
 * @return O número de utilizadores que são organizações do Catálodo de Users
 */
int sgr_get_CU_org(SGR sgr);

/**
 *
 * @param sgr A Estrutura que contém os catálogos a serem utilizados nas queries
 * @return O número de utilizadores do Catálogo de Users
 */
int sgr_get_CU_user(SGR sgr);

/**
 *
 * @param sgr A Estrutura que contém os catálogos a serem utilizados nas queries
 * @return O número de utilizadores do Catálogo de Commits
 */
int sgr_get_CC_user(SGR sgr);

/**
 *
 * @param sgr A Estrutura que contém os catálogos a serem utilizados nas queries
 * @return O número de repositórios existentes do Catálogo de Commits
 */
int sgr_get_CC_repos(SGR sgr);

/**
 *
 * @param sgr A Estrutura que contém os catálogos a serem utilizados nas queries
 * @return O número de utilizadores que são bots do Catálogo de Commits
 */
int sgr_get_CC_bots(SGR sgr);

/**
 *
 * @param sgr A Estrutura que contém os catálogos a serem utilizados nas queries
 * @return O número total de commits existentes no Catálogo de Commits
 */
int sgr_get_CC_total_commits(SGR sgr);

/**
 *
 * @param sgr A Estrutura que contém os catálogos a serem utilizados nas queries
 * @return GArray que contém os ids presentes na hashtable de ocorrências
 */
GArray * sgr_get_CC_usersID(SGR sgr);

/**
 *
 * @param sgr A Estrutura que contém os catálogos a serem utilizados nas queries
 * @return GHashtable que contém o número de commits feito por cada user
 */
GHashTable * sgr_get_cc_GOcorr(SGR sgr);

/**
 *
 * @param sgr A Estrutura que contém os catálogos a serem utilizados nas queries
 * @param key O número do id de um user
 * @return GArray que contém os ids presentes na hashtable de ocorrências
 */
LUSER sgr_get_CU_GUser(SGR sgr, int key);
#endif //GRUPO11_SGR_H
