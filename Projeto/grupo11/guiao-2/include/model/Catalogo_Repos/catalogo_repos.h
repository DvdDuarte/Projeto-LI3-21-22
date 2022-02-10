#ifndef GRUPO11_CATALOGO_REPOS_H
#define GRUPO11_CATALOGO_REPOS_H

#include "glib-2.0/glib.h"
#include "../../../include/model/Catalogo_Repos/repos.h"

/**
 * Estrutura de tipo de dados a ser chamado sempre que for necessário criar um catálogo de repositórios
 */
typedef struct catalogo_repos NCREPOS, *CREPOS;

/**
 * Função que inicia o catálogo de repositórios com os valores minimo, e cria a HashTable de repositórios (chave id do repositório, valor repositório)
 * @return O Catálogo de Repositórios, onde é armazenada a informação necessária sobre os repositórios para as queries
 */
CREPOS initCRepos();

/**
 * Função que coloca a informação de uma HashTable de repositórios (chave id do repositório, valor repositório)
 * @param crepos O Catálogo de Repositórios, onde é armazenada a informação necessária sobre os repositórios para as queries
 * @param repos O repositório a ser adicionada ao catálogo
 */
void set_CR_GRepos (CREPOS crepos, LRepos repos);

/**
 * Função que retorna o tamanho da GHashTable* contida no catálogo de Repositórios
 * @param crepos O catálogo de Repositórios
 * @return O tamanho da GHashTable*
 */
int get_CR_GHSize (CREPOS crepos);

/*DEBUG
void print_CR_GR_PTR(CREPOS c);
*/
#endif //GRUPO11_CATALOGO_REPOS_H
