#ifndef _REPOS_H_
#define _REPOS_H_

#include <stdbool.h>
#include "../Funcoes_Aux.h"
#include "../Data.h"
#include "../../include/ghash_func_gerais.h"
#include "../../include/Catalogo_Commits/commits.h"
#include "glib-2.0/glib.h"

typedef struct repos NRepos, *LRepos;

//
void GAddRepos(LRepos repo, GHashTable *hash);
LRepos GGetRepo(int key, GHashTable *hash);
int verifica_owner_id(LRepos repo, GHashTable *users);
int verica_commits_repo(int repoID, GArray *commits);

//
int get_ID_Repo(LRepos r);
void set_ID_Repo(LRepos r, int id);
int get_Owner_ID(LRepos r);
void set_Owner_ID(LRepos r, int owner_id);
char* get_Full_Name(LRepos r);
void set_Full_Name(LRepos r, char* full_name);
char* get_License(LRepos r);
void set_License(LRepos r, char* license);
bool get_Has_Wiki(LRepos r);
void set_Has_Wiki(LRepos r, bool has_wiki);
char* get_Description(LRepos r);
void set_Description(LRepos r, char* description);
char* get_Language(LRepos r);
void set_Language(LRepos r, char* language);
char* get_Default_Branch(LRepos r);
void set_Default_Branch(LRepos r, char* default_branch);
LTempo get_Created_At(LRepos r);
void set_Created_At(LRepos r, LTempo created_at);
LTempo get_Update_At(LRepos r);
void set_Update_At(LRepos r, LTempo update_at);
int get_Forks_Count(LRepos r);
void set_Forks_Count(LRepos r, int forks_count);
int get_Open_Issues(LRepos r);
void set_Open_Issues(LRepos r, int open_issues);
int get_Stargazers_Count(LRepos r);
void set_Stargazers_Count(LRepos r, int stargazers_count);
int get_Size(LRepos r);
void set_Size(LRepos r, int size);

void free_Repos(LRepos r);

LRepos build_Repos(char*line);

#endif //_REPOS_H_
