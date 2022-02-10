#ifndef GRUPO11_CATALOGO_COMMITS_H
#define GRUPO11_CATALOGO_COMMITS_H

#include "glib-2.0/glib.h"
#include "../../../include/model/Catalogo_Commits/commits.h"
#include "../Catalogo_Repos/repos.h"


/**
 * Estrutura de tipo de dados a ser chamado sempre que for necessário criar um catálogo de repositórios
 */
typedef struct catalogo_commits NCCOMMITS, *CCOMMITS;

/**
 * Função que inicia o catálogo de commits com os valores minimo, e cria as HashTables
 * @return O Catálogo de Commits, onde é armazenada a informação necessária sobre os commits para as queries
 */
CCOMMITS initCCommits();

/**
 * Função que verifica se existe um ou mias commits num determinado repositório
 * @param ccommits O Catálogo de Commits
 * @param repo O repositório a verificar se tem commits
 * @return Se existe algum commito ou não no determinado repositório
 */
int verifica_CC_reposID(CCOMMITS ccommits, LRepos repo);

/**
 * Função que obtém o número de repos contidos no catálogo de commits
 * @param ccommits O Catálogo de Commits
 * @return O número de repos
 */
int get_CC_Nrepos(CCOMMITS ccommits);

/**
 * Função que obtém o número de users contidos no catálogo de commits
 * @param ccommits O Catálogo de Commits
 * @return O número de users
 */
int get_CC_Nusers(CCOMMITS ccommits);

/**
 * Função que obtém o número de users do tipo bot contidos no catálogo de commits
 * @param ccommits O Catálogo de Commits
 * @return O número de bots
 */
int get_CC_Nbots(CCOMMITS ccommits);

/**
 * Função que obtém o número de total de commits no catálogo de commits
 * @param ccommits O Catálogo de Commits
 * @return O número total de commits
 */
int get_CC_total_commits(CCOMMITS ccommits);

/**
 * Função que atualiza o GArray* do Catálogo de Commits
 * @param catalogo_commits O Catálogo de Commits a ser atualizado
 * @param commit_list O GArray* a ser atualizado
 */
void set_CC_GCommits(CCOMMITS catalogo_commits, GArray *commit_list);

/**
 * Função que dependendo da flag adiciona um commit a HashTable do catalogo de commits
 * @param catalogo_commits O Catálogo de Commits a ser atualizado
 * @param commit O Commit a ser adicionado
 * @param flag Indica em que HashTable do Catálodo de Commits vai ser inserido o Commit (se for 0 então GUsers se for 1 então GRepos)
 * @return
 */
int set_CC_GHashTable(CCOMMITS catalogo_commits, LCommits commit, int flag);

/**
 * Função que altera o valor do CCOMMITS->nrepos
 * @param catalogo_commits O Catálogo de Commits a ser atualizado
 * @param nrepos O valor de nrepos a ser atualizado no CCOMMITS
 */
void set_CC_Nrepos (CCOMMITS catalogo_commits, int nrepos);

/**
 * Função que altera o valor do CCOMMITS->nusers
 * @param catalogo_commits O Catálogo de Commits a ser atualizado
 * @param nusers O valor de nusers a ser atualizado no CCOMMITS
 */
void set_CC_Nusers (CCOMMITS catalogo_commits, int nusers);

/**
 * Função que altera o valor do CCOMMITS->nbots
 * @param catalogo_commits O Catálogo de Commits a ser atualizado
 * @param nbots O valor de nbots a ser atualizado no CCOMMITS
 */
void set_CC_Nbots (CCOMMITS catalogo_commits, int nbots);

/**
 * Função que altera o valor do CCOMMITS->total_commits
 * @param catalogo_commits O Catálogo de Commits a ser atualizado
 * @param total_commits O valor de total_commits a ser atualizado no CCOMMITS
 */
void set_CC_total_commits (CCOMMITS catalogo_commits, int total_commits);


#endif //GRUPO11_CATALOGO_COMMITS_H
