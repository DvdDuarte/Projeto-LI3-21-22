/**
 * @file catalogo_users.h
 * @author grupo11
 * @brief Ficheiro que contém as funções que para trabalhar com o catalogo de users
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef GRUPO11_CATALOGO_USERS_H
#define GRUPO11_CATALOGO_USERS_H

#include "glib-2.0/glib.h"
#include "../../../include/model/Catalogo_User/users.h"
#include "../../../include/model/ghash_func_gerais.h"

/**
 * Estrutura de tipo de dados a ser chamado sempre que for necessário criar um catálogo de users
 */
typedef struct catalogo_user NCUSER, *CUSER;

/**
 * Função que inicia o catálogo de users com os valores minimo, e cria a HashTable de users (chave id do user, valor users)
 * @return O Catálogo de Users, onde é armazenada a informação necessária sobre os users para as queries
 */
CUSER initCUsers();

/**
 * Função que adiciona um user à HashTable pertencente ao Catálogo de users
 * @param cuser O Catálogo de users a ser atualizdo
 * @param user O user a ser adicionado
 */
void add_CU_GUser(CUSER cuser, LUSER user);

/**
 * Função que retorna um user que está contido na HashTable do catálogo de users
 * @param cuser O Catálogo de users onde se vai buscar o user
 * @param key A chave do user
 * @return O user
 */
LUSER get_CU_GUser(CUSER cuser, int key);

/**
 * Função que obtém a HashTable de users contida no catálogo de users
 * @param cuser O Catálogo de Users
 * @param key A chave do user a verificar se existe
 * @return A HashTable de users
 */
int verifica_CU_User (CUSER cuser, int key);

/**
 * Função que obtém o número de users do tipo bor contidos no catálogo de users
 * @param cuser O Catálogo de Users
 * @return O número de users do tipo bot
 */
int get_CU_bots (CUSER cuser);

/**
 * Função que obtém o número de users do tipo org contidos no catálogo de users
 * @param cuser O Catálogo de Users
 * @return O número de users do tipo org
 */
int get_CU_org (CUSER cuser);

/**
 * Função que obtém o número de users do tipo user contidos no catálogo de users
 * @param cuser O Catálogo de Users
 * @return O número de users do tipo user
 */
int get_CU_user (CUSER cuser);

////
//int get_CU_id (CUSER cuser);
//char * get_CU_login (CUSER cuser);
////

/**
 * Função que define a HashTable de users do catálogo de users
 * @param cuser O Catálogo de Users
 * @param user O user a ser inserida na HashTable de cuser
 */
void set_CU_GUser (CUSER cuser, LUSER user);

/**
 * Função que define o número de users do tipo bot, no catálogo de users
 * @param cuser O Catálogo de Users
 * @param bots O número de users do tipo bot
 */
void set_CU_bots (CUSER cuser, int bots);

/**
 * Função que define o número de users do tipo org, no catálogo de users
 * @param cuser
 * @param org O número de users do tipo org
 */
void set_CU_org (CUSER cuser, int org);

/**
 * Função que define o número de users do tipo user, no catálogo de users
 * @param cuser
 * @param nuser O número de users do tipo user
 */
void set_CU_user (CUSER cuser, int nuser);

int get_size(CUSER u);
void verifica_user_table(CUSER u);

#endif //GRUPO11_CATALOGO_USERS_H
