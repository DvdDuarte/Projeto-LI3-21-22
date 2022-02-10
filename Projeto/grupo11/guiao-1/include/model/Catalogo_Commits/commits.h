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
 *
 * @param commit
 * @param users
 * @return
 */
int verifica_users_GCommit(LCommits commit, GHashTable *users);

/**
 *
 * @param commit
 * @param hashT
 * @return
 */
int verifica_repos_commit(LCommits commit, GHashTable *hashT);

//Get e set

/**
 *
 * @param c
 * @return
 */
int get_Repo_ID(LCommits c);

/**
 *
 * @param c
 * @param repo_id
 */
void set_Repo_ID(LCommits c, int repo_id);

/**
 *
 * @param c
 * @return
 */
int get_Author_ID(LCommits c);

/**
 *
 * @param c
 * @param author_id
 */
void set_Author_ID(LCommits c, int author_id);

/**
 *
 * @param c
 * @return
 */
int get_Committer_ID(LCommits c);

/**
 *
 * @param c
 * @param committer_id
 */
void set_Committer_ID(LCommits c, int committer_id);

/**
 *
 * @param c
 * @return
 */
LTempo get_Commit_AT(LCommits c);

/**
 *
 * @param c
 * @param commit_at
 */
void set_Commit_AT(LCommits c, LTempo commit_at);

/**
 *
 * @param c
 * @return
 */
char* get_Message(LCommits c);

/**
 *
 * @param c
 * @param message
 */
void set_Message(LCommits c, char* message);

/**
 *
 * @param c
 */
void free_Commit(LCommits c);

/**
 *
 * @param line
 * @return
 */
LCommits build_Commit(char* line);

#endif //_COMMITS_H_
