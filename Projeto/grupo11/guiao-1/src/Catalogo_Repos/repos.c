#include "../../include/Catalogo_Repos/repos.h"

struct repos{
    int id;
    int owner_id;
    char* full_name;
    char* license;
    bool has_wiki;
    char* description;
    char* language;
    char* default_branch;
    LTempo created_at;
    LTempo updated_at;
    int forks_count;
    int open_issues;
    int stargazers_count;
    int size;
};

//GHashTable Functions

void GAddRepos(LRepos repo, GHashTable *hash) {
    g_hash_table_insert (hash, &repo->owner_id, repo);
}


LRepos GGetRepo(int key, GHashTable *hash) {
    LRepos aux = (LRepos)g_hash_table_lookup(hash, &key); // talvez seja outra funcao pra pegar no valor que esta na table
    if (aux == NULL) return NULL;
    else return aux;//funcao que clona o repo
}


int verifica_owner_id(LRepos repo, GHashTable *users) {
    if(GContainsKey(repo->owner_id, users)) return 1;
    else return 0;

}

int verica_commits_repo(int repoID, GArray *commits) {

    for(int i = 0; i < commits->len; i++) {
        if(get_Repo_ID(GGetCommit(commits, i)) == repoID) return 1;
    }

    return 0;

}

//Gets e Sets

int get_ID_Repo(LRepos r){
    return r->id;
}

void set_ID_Repo(LRepos r, int id){
    r->id = id;
}

int get_Owner_ID(LRepos r){
    return r->owner_id;
}

void set_Owner_ID(LRepos r, int owner_id){
    r->owner_id = owner_id;
}

char* get_Full_Name(LRepos r){
    return strdup(r->full_name);
}

void set_Full_Name(LRepos r, char* full_name){
    free(r->full_name);
    r->full_name = strdup(full_name);
}

char* get_License(LRepos r){
    return strdup(r->license);
}

void set_License(LRepos r, char* license){
    free(r->license);
    r->license = strdup(license);
}

bool get_Has_Wiki(LRepos r){
    return r->has_wiki;
}

void set_Has_Wiki(LRepos r, bool has_wiki){
    r->has_wiki = has_wiki;
}

char* get_Description(LRepos r){
    return strdup(r->description);
}

void set_Description(LRepos r, char* description){
    free(r->description);
    r->description = strdup(description);
}

char* get_Language(LRepos r){
    return strdup(r->language);
}

void set_Language(LRepos r, char* language){
    free(r->language);
    r->language = strdup(language);
}

char* get_Default_Branch(LRepos r){
    return strdup(r->default_branch);
}

void set_Default_Branch(LRepos r, char* default_branch){
    free(r->default_branch);
    r->default_branch = strdup(default_branch);
}

LTempo get_Created_At(LRepos r){
    return clone_Tempo(r->created_at);
}

void set_Created_At(LRepos r, LTempo created_at){
    free(r->created_at);
    r->created_at = clone_Tempo(created_at);
}

LTempo get_Update_At(LRepos r){
    return clone_Tempo(r->updated_at);
}

void set_Update_At(LRepos r, LTempo update_at){
    free(r->updated_at);
    r->updated_at = clone_Tempo(update_at);
}

int get_Forks_Count(LRepos r){
    return r->forks_count;
}

void set_Forks_Count(LRepos r, int forks_count){
    r->forks_count = forks_count;
}

int get_Open_Issues(LRepos r){
    return r->open_issues;
}

void set_Open_Issues(LRepos r, int open_issues){
    r->open_issues = open_issues;
}

int get_Stargazers_Count(LRepos r){
    return r->stargazers_count;
}

void set_Stargazers_Count(LRepos r, int stargazers_count){
    r->stargazers_count = stargazers_count;
}

int get_Size(LRepos r){
    return r->size;
}

void set_Size(LRepos r, int size){
    r->size = size;
}

void free_Repos(LRepos r){

    free(r->full_name);
    free(r->license);
    free(r->description);
    free(r->language);
    free(r->default_branch);
    free(r->created_at);
    free(r->updated_at);

    free(r);

}

int valid_Repos(LRepos r){

    int valid = 1;

    if(r->id < 0 || r->owner_id < 0 || r->forks_count < 0 || r->open_issues < 0 || r->stargazers_count < 0 || r->size < 0)
        valid = 0;
    if(valid && (strcmp(r->full_name, "") == 0 || strcmp(r->license, "") == 0 || 
                 strcmp(r->language, "") == 0 || strcmp(r->default_branch, "") == 0))
        valid = 0;
    if(valid && (get_Created_At(r) == NULL || get_Update_At(r) == NULL))
        valid = 0;
    
    return valid;
}


LRepos build_Repos(char*line){

    LRepos r = malloc(sizeof(NRepos));

    r->id = digitorChar(strsep(&line, ";\n"));
    r->owner_id = digitorChar(strsep(&line, ";\n"));
    r->full_name = strdup(strsep(&line, ";\n"));
    r->license = strdup(strsep(&line, ";\n"));
    char* valid = strdup(strsep(&line, ";\n"));
    int has_wiki_valid = 1;
    if(strcmp(valid, "True") == 0)
        r->has_wiki = 1;
    else if(strcmp(valid, "False") == 0)
        r->has_wiki = 0;
    else {
        has_wiki_valid = 0;
        r->has_wiki = -1;
    }
    r->description = strdup(strsep(&line, ";\n"));
    r->language = strdup(strsep(&line, ";\n"));
    r->default_branch = strdup(strsep(&line, ";\n"));
    r->created_at = build_time(strsep(&line, ";\n"));
    r->updated_at = build_time(strsep(&line, ";\n"));
    r->forks_count = digitorChar(strsep(&line, ";\n"));
    r->open_issues = digitorChar(strsep(&line, ";\n"));
    r->stargazers_count = digitorChar(strsep(&line, ";\n"));
    r->size = digitorChar(strsep(&line, ";\r\n"));

    if(!valid_Repos(r) || !has_wiki_valid){
        free_Repos(r);
        r = NULL;
    }

    return r;
}
