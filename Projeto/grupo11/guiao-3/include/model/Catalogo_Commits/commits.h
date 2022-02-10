/**
 * @file commits.h
 * @author grupo11
 * @brief Ficheiro que contém as funções que para trabalhar com os commits
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _COMMITS_H_
#define _COMMITS_H_

#include "../Funcoes_Aux.h"
#include "../Data.h"
#include "glib-2.0/glib.h"

/**
 * Tipo de dados a ser utilizado sempre que se queira criar um commit
 */
typedef struct commit NCommits, *LCommits;

//GHashTable Functions

/**
 * Função que adiciona um commit num *GArray
 * @param commit
 * @param array
 */
void GAddCommit (LCommits commit, GArray *array);

/**
 * Funçã́o que obtém um commit do *GArray que se encontra num determinado indice
 * @param array
 * @param indice
 * @return
 */
LCommits GGetCommit(GArray *array, int indice);

/**
 * Função que adiciona um GArray* de commits a uma hashtable
 * @param commit O commit a adicionar
 * @param key A chave onde se vai inserir na HashTable
 * @param hashTable A HashTable onde será inserido o GArray+ de commits
 * @return Se já existia a chave onde será inserido/atualizado o GArray*
 */
int GHAddCommit (LCommits commit, int key, GHashTable *hashTable);

/**
 *  Função que verifica se um utilizador que realizou o commit se encontra na hashtable de users
 * @param commit O commit realizado
 * @param users A hashtable de users
 * @return
 */
int verifica_users_GCommit(LCommits commit, GHashTable *users);

/**
 * Função que verifica se um utilizador que realizou o commit se encontra na hashtable de repos
 * @param commit O commit realizado
 * @param hashT A hashtable de repos
 * @return
 */
int verifica_repos_commit(LCommits commit, GHashTable *hashT);

//Get e set

/**
 *  Função que retorna o id dos repos
 * @param c O commit a ser atualizado
 * @return O id do repositorio do commit
 */
int get_Repo_ID(LCommits c);

/**
 * Função que atualiza o id dos repos do commit 
 * @param c O commit a ser atualizado
 * @param repo_id O id do repositorio do commit
 */
void set_Repo_ID(LCommits c, int repo_id);

/**
 * Função que retorna o id do autor do commit
 * @param c O commit a ser atualizado
 * @return O autor do commit
 */
int get_Author_ID(LCommits c);

/**
 * Função que atualiza o id do autor do commit
 * @param c O commit a ser atualizado
 * @param author_id O autor do commit a adicionar no commit
 */
void set_Author_ID(LCommits c, int author_id);

/**
 * Função que retorna o id do commiter
 * @param c O commit a ser atualizado
 * @return O id de quem realizou o commit
 */
int get_Committer_ID(LCommits c);

/**
 * Função que atualiza o commiter_id do commit
 * @param c O commit a ser atualizado
 * @param committer_id O id de quem realizou o commit a adicionar no commit
 */
void set_Committer_ID(LCommits c, int committer_id);

/**
 * Função que retorna o commiter_id
 * @param c O commit a ser atualizado
 * @returnA data que o commit foi realizado
 */
LTempo get_Commit_AT(LCommits c);

/**
 * Função que atualiza a data que o commit foi realizado
 * @param c O commit a ser atualizado
 * @param commit_at A data que o commit foi realizado a adicionar no commit
 */
void set_Commit_AT(LCommits c, LTempo commit_at);

/**
 * Função que retorna a mensagem do commit
 * @param c O commit a ser atualizado
 * @returnA mensagem do commit
 */
char* get_Message(LCommits c);

/**
 * Função que atualiza a mensagem do commit
 * @param c O commit a ser atualizado 
 * @param message A mensagem a adicionar no commit
 */
void set_Message(LCommits c, char* message);

/**
 * Função que realiza o free de um commit
 * @param c O commit a ser libertado
 */
void free_Commit(LCommits c);

/**
 * Função que constrói um commit
 * @param line A informação do commit
 * @return O commit moldado no formato da struct
 */
LCommits build_Commit(char* line);

#endif //_COMMITS_H_
