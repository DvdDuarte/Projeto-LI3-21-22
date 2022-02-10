#ifndef _COMMITS_H_
#define _COMMITS_H_

#include "../Funcoes_Aux.h"
#include "../Data.h"
#include "glib-2.0/glib.h" 

typedef struct commit NCommits, *LCommits;

//GHashTable Functions

void GAddCommit (LCommits commit, GArray *array);
LCommits GGetCommit(GArray *array, int indice);
int verifica_users_GCommit(LCommits commit, GHashTable *users);
int verifica_repos_commit(LCommits commit, GHashTable *hashT);

//Get e set
int get_Repo_ID(LCommits c);
void set_Repo_ID(LCommits c, int repo_id);
int get_Author_ID(LCommits c);
void set_Author_ID(LCommits c, int author_id);
int get_Committer_ID(LCommits c);
void set_Committer_ID(LCommits c, int committer_id);
LTempo get_Commit_AT(LCommits c);
void set_Commit_AT(LCommits c, LTempo commit_at);
char* get_Message(LCommits c);
void set_Message(LCommits c, char* message);

void free_Commit(LCommits c);

LCommits build_Commit(char* line);

#endif //_COMMITS_H_
