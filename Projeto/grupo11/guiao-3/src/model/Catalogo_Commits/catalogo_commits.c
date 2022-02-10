/**
 * @file catalogo_commits.c
 * @author grupo11
 * @brief Ficheiro que contém as funções que para trabalhar com o catalogo de commits
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../../include/model/Catalogo_Commits/catalogo_commits.h"
#include "../../../include/model/Catalogo_Repos/repos.h"

struct catalogo_commits {
    GArray *GCommits;
    GHashTable *GUsers; //chave author_id or commiter_id valor null ou a prõpria chave
    GHashTable *GRepos; //chave repo_id valor null ou a prõpria chave
    int nrepos;
    int nusers;
    int nbots;
    GHashTable *hashT;
    GArray *usersID;
    int total_commits;
};

CCOMMITS initCCommits (){
    CCOMMITS ccommits = malloc(sizeof(NCCOMMITS));
    ccommits->GCommits = g_array_new(FALSE, FALSE, sizeof(LCommits));
    ccommits->GUsers = g_hash_table_new(g_int_hash, g_int_equal);
    ccommits->GRepos = g_hash_table_new(g_int_hash, g_int_equal);
    ccommits->hashT= g_hash_table_new(g_int_hash, g_int_equal);
    ccommits->usersID = g_array_new(FALSE, FALSE, sizeof(int));
    ccommits->nrepos = 0;
    ccommits->nusers = 0;
    ccommits->nbots = 0;
    ccommits->total_commits = 0;

    return ccommits;
}

GHashTable * get_hashOcor(CCOMMITS ccommits){
    return ccommits->hashT;
}

GArray * get_CC_usersID(CCOMMITS ccommits){
    return ccommits->usersID;
}

int verifica_CC_reposID(CCOMMITS ccommits, LRepos repo){
    return GContainsKey(get_ID_Repo(repo),ccommits->GRepos);
}

int get_CC_Nrepos(CCOMMITS ccommits){
    return ccommits->nrepos;
}

int get_CC_Nusers(CCOMMITS ccommits){
    return ccommits->nusers;
}

int get_CC_Nbots(CCOMMITS ccommits){
    return ccommits->nbots;
}

int get_CC_total_commits(CCOMMITS ccommits) {
    return ccommits->total_commits;
}

void set_CC_GCommits(CCOMMITS catalogo_commits, GArray *commit_list){
    catalogo_commits->GCommits = commit_list;
}

int set_CC_GHashTable(CCOMMITS catalogo_commits, LCommits commit, int flag){
    int key = 0;
    int existe = -1;
    if(flag == 0) {
        key = get_Committer_ID(commit);
        existe = GHAddCommit(commit, key, catalogo_commits->GUsers);
    }
    else {
        key = get_Repo_ID(commit);
        existe = GHAddCommit(commit, key, catalogo_commits->GRepos);
    }

    return existe;

}

void set_CC_Nrepos (CCOMMITS catalogo_commits, int nrepos) {
    catalogo_commits->nrepos = nrepos;
}

void set_CC_Nusers (CCOMMITS catalogo_commits, int nusers) {
    catalogo_commits->nusers = nusers;
}

void set_CC_Nbots (CCOMMITS catalogo_commits, int nbots) {
    catalogo_commits->nbots = nbots;
}

void set_CC_total_commits (CCOMMITS catalogo_commits, int total_commits) {
    catalogo_commits->total_commits = total_commits;
}



///////////****OPERAÇÕES SOBRE HASHTABLES****/////////////
void GAdduserid(int x, CCOMMITS ccommits){
    g_array_append_vals(ccommits->usersID,&x,1);
}

void GRemoveid(int x, CCOMMITS ccommits){
    int *aux = malloc(sizeof(int));
    *aux = x;
    g_array_remove_index(ccommits->usersID,aux);

}


int maxOcor_Hash(GHashTable *hashT,GArray * usersID, int N) {
    int i=0;
    int max=0;
    int maxId;
    while(i<N){
        int x = g_array_index(usersID,int,i);
        int *chave = malloc(sizeof(int));
        *chave = x;
        if(max<g_hash_table_lookup(hashT, chave)){
            max=g_hash_table_lookup(hashT, chave);
            maxId=x;
        }
        i++;
    }
    return maxId;
}

int nOcor_Hash(GHashTable *hashT,GArray * usersID, int N) {
    int i=0;
    int max=0;
    while(i<N){
        int x = g_array_index(usersID,int,i);
        int *chave = malloc(sizeof(int));
        *chave = x;
        if(max<g_hash_table_lookup(hashT, chave)){
            max=g_hash_table_lookup(hashT, chave);
        }
        i++;
    }
    return max;
}


void add_CC_GOcorr(int key, CCOMMITS ccommits) {
    int *chave = malloc(sizeof(int));
    *chave = key;
    int *ocorr;
    if(g_hash_table_contains(ccommits->hashT,chave)==TRUE) {
        * ocorr = g_hash_table_lookup(ccommits->hashT, chave) ;
        (*ocorr)++;
    }
    else *ocorr=1;
    g_hash_table_insert(ccommits->hashT, chave, *ocorr);
}

