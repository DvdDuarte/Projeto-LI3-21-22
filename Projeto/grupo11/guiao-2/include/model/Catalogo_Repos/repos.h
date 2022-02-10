#ifndef _REPOS_H_
#define _REPOS_H_

#include <stdbool.h>
#include "../Funcoes_Aux.h"
#include "../Data.h"
#include "../ghash_func_gerais.h"
#include "../Catalogo_Commits/commits.h"
#include "glib-2.0/glib.h"

/**
 * Tipo de dados a ser utilizado sempre que se queira criar um repositório
 */
typedef struct repos NRepos, *LRepos;

//

/**
 *
 * @param repo
 * @param hash
 */
void GAddRepos(LRepos repo, GHashTable *hash);

/**
 *
 * @param key
 * @param hash
 * @return
 */
LRepos GGetRepo(int key, GHashTable *hash);

/**
 *
 * @param repo
 * @param users
 * @return
 */
int verifica_owner_id(LRepos repo, GHashTable *users);

/**
 *
 * @param repo
 * @param commits
 * @return
 */
int verica_commits_repo(LRepos repo, GHashTable *commits);

//

/**
 *
 * @param r
 * @return
 */
int get_ID_Repo(LRepos r);

/**
 *
 * @param r
 * @param id
 */
void set_ID_Repo(LRepos r, int id);

/**
 *
 * @param r
 * @return
 */
int get_Owner_ID(LRepos r);

/**
 *
 * @param r
 * @param owner_id
 */
void set_Owner_ID(LRepos r, int owner_id);

/**
 *
 * @param r
 * @return
 */
char* get_Full_Name(LRepos r);

/**
 *
 * @param r
 * @param full_name
 */
void set_Full_Name(LRepos r, char* full_name);

/**
 *
 * @param r
 * @return
 */
char* get_License(LRepos r);

/**
 *
 * @param r
 * @param license
 */
void set_License(LRepos r, char* license);

/**
 *
 * @param r
 * @return
 */
bool get_Has_Wiki(LRepos r);

/**
 *
 * @param r
 * @param has_wiki
 */
void set_Has_Wiki(LRepos r, bool has_wiki);

/**
 *
 * @param r
 * @return
 */
char* get_Description(LRepos r);

/**
 *
 * @param r
 * @param description
 */
void set_Description(LRepos r, char* description);

/**
 *
 * @param r
 * @return
 */
char* get_Language(LRepos r);

/**
 *
 * @param r
 * @param language
 */
void set_Language(LRepos r, char* language);

/**
 *
 * @param r
 * @return
 */
char* get_Default_Branch(LRepos r);

/**
 *
 * @param r
 * @param default_branch
 */
void set_Default_Branch(LRepos r, char* default_branch);

/**
 *
 * @param r
 * @return
 */
LTempo get_Created_At(LRepos r);

/**
 *
 * @param r
 * @param created_at
 */
void set_Created_At(LRepos r, LTempo created_at);

/**
 *
 * @param r
 * @return
 */
LTempo get_Update_At(LRepos r);

/**
 *
 * @param r
 * @param update_at
 */
void set_Update_At(LRepos r, LTempo update_at);

/**
 *
 * @param r
 * @return
 */
int get_Forks_Count(LRepos r);

/**
 *
 * @param r
 * @param forks_count
 */
void set_Forks_Count(LRepos r, int forks_count);

/**
 *
 * @param r
 * @return
 */
int get_Open_Issues(LRepos r);

/**
 *
 * @param r
 * @param open_issues
 */
void set_Open_Issues(LRepos r, int open_issues);

/**
 *
 * @param r
 * @return
 */
int get_Stargazers_Count(LRepos r);

/**
 *
 * @param r
 * @param stargazers_count
 */
void set_Stargazers_Count(LRepos r, int stargazers_count);

/**
 *
 * @param r
 * @return
 */
int get_Size(LRepos r);

/**
 *
 * @param r
 * @param size
 */
void set_Size(LRepos r, int size);

/**
 *
 * @param r
 */
void free_Repos(LRepos r);

/**
 *
 * @param line
 * @return
 */
LRepos build_Repos(char*line);

#endif //_REPOS_H_
