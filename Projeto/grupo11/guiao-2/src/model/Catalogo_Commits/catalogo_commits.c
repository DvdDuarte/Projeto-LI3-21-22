//
// Created by sleiman on 26/11/21.
//

#include "../../../include/model/Catalogo_Commits/catalogo_commits.h"
#include "../../../include/model/Catalogo_Repos/repos.h"

struct catalogo_commits {
    GArray *GCommits;
    GHashTable *GUsers; //chave author_id or commiter_id valor null ou a prõpria chave
    GHashTable *GRepos; //chave repo_id valor null ou a prõpria chave
    int nrepos;
    int nusers;
    int nbots;
    //GHashTable *hashOcor;
    int total_commits;
};

CCOMMITS initCCommits (){
    CCOMMITS ccommits = malloc(sizeof(NCCOMMITS));
    ccommits->GCommits = g_array_new(FALSE, FALSE, sizeof(LCommits));
    ccommits->GUsers = g_hash_table_new(g_int_hash, g_int_equal);
    ccommits->GRepos = g_hash_table_new(g_int_hash, g_int_equal);
    //ccommits->hashOcor= g_hash_table_new(g_int_hash,g_int_equal);
    ccommits->nrepos = 0;
    ccommits->nusers = 0;
    ccommits->nbots = 0;
}
/*
THash get_hashOcor(CCOMMITS ccommits){
    return ccomits->t;
}
*/

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
/*
void set_hashOcor(CCOMMITS catalogo_commits,THash t){
    catalogo_commits->t =t;
}
*/
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


/*
///////////OPERAÇÕES SOBRE HASHTABLES/////////////
void initHash_Ocor(THash t){
    for(int i=0;i<size;i++) t[i]=NULL;
}

int addHash_Ocor(int n,THash t){
    int x= n % size;
    Node *aux = t[x];
    while(aux && n != aux->key){
        aux=aux->prox;
    }
    if(aux!=NULL){
        aux->ocorrencias++;
    }else{
        Node * new = malloc(sizeof(Node));
        if(new==NULL) return 1;
        new->key = n;
        new->ocorrencias=1;
        new->prox=t[x];
        t[x]=new;
    }
    return 0;
}

int maxOcor_Hash(const THash *t) {
    Node *aux = *t;
    Node *max = malloc(sizeof(Node));
    max->key =0;
    max->ocorrencias=0;
    
    int i;
    for(i=0;i<size;i++){
        aux=t[i];
        while(aux!=NULL){
            if(aux->ocorrencias>max->ocorrencias){
                max=aux;
            }
            aux = aux->prox;
        }
    }
    if(max!=NULL) return max->key;
    else return 1;
}

THash removeKey_Hash(int n, THash t){
    int x = n % size;
    Node * aux = t[x];
    Node *ant= NULL;
    while(aux!=NULL && n!=aux->key){
        ant = aux;
        aux=aux->prox;
    }
    if(aux==NULL) return 1;
    if(aux->ocor>1)
        aux->ocor--;
    else{
        if(ant!=NULL)
            ant->prox = aux->prox;
        else t[x]=aux->prox;
    }free(aux);
    return t;
}

int lookupHash(int n, THash t){
    int c= n%size;
    Node *aux = t[c];
    while (aux && n!=aux->key){
        aux=aux->prox;
    }
    if(aux!=NULL) return aux->ocorrencias;
    else return 1;
}
*/
