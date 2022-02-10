
#include "../../include/Catalogo_Commits/commits.h"
#include "../../include/ghash_func_gerais.h"

struct commit{
    int repo_id;
    int author_id;
    int committer_id;
    LTempo commit_at;
    char* message;
};

//GHashTable Functions

void GAddCommit (LCommits commit, GArray *array){
    g_array_append_vals(array, &commit,1/*sizeof(LCommits*/);
}

LCommits GGetCommit(GArray *array, int indice){
    LCommits aux = g_array_index(array, LCommits, indice);
    if (aux == NULL) return NULL;
    else return aux;
}

int verifica_users_GCommit(LCommits commit, GHashTable *users){

    if(GContainsKey(get_Committer_ID(commit), users) && GContainsKey(get_Author_ID(commit), users)) return 1;
    else return 0;

}

int verifica_repos_commit(LCommits commit, GHashTable *hashT){

    if(GContainsKey(get_Repo_ID(commit), hashT)) return 1;
    else return 0;

}
//Get e set

int get_Repo_ID(LCommits c){
    return c->repo_id;
}

void set_Repo_ID(LCommits c, int repo_id){
    c->repo_id = repo_id;
}

int get_Author_ID(LCommits c){
    return c->author_id;
}

void set_Author_ID(LCommits c, int author_id){
    c->author_id = author_id;
}

int get_Committer_ID(LCommits c){
    return c->committer_id;
}

void set_Committer_ID(LCommits c, int committer_id){
    c->committer_id = committer_id;
}

LTempo get_Commit_AT(LCommits c){
    return clone_Tempo(c->commit_at);
}

void set_Commit_AT(LCommits c, LTempo commit_at){
    free(c->commit_at);
    c->commit_at = clone_Tempo(commit_at);
}

char* get_Message(LCommits c){
    return strdup(c->message);
}

void set_Message(LCommits c, char* message){
    free(c->message);
    c->message = strdup(message);
}

void free_Commit(LCommits c){

    free(c->commit_at);
    free(c->message);

    free(c);

}

int valid_Commit(LCommits c){

    int valid = 1;

    if(c->repo_id < 0 || c->author_id < 0 || c->committer_id < 0)
        valid = 0;
    if(valid && get_Commit_AT(c) == NULL)
        valid = 0;

    return valid;
}

LCommits build_Commit(char* line){

    LCommits c = malloc(sizeof (NCommits));

    c->repo_id = digitorChar(strsep(&line, ";\n"));
    c->author_id = digitorChar(strsep(&line, ";\n"));
    c->committer_id = digitorChar(strsep(&line, ";\n"));
    c->commit_at = build_time(strsep(&line, ";\n"));
    c->message = strdup(strsep(&line, ";\r\n"));

    if(!valid_Commit(c)){
        free_Commit(c);
        c = NULL;
    }

    return c;

}
