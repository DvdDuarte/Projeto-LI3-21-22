#include <stdio.h>
#include <stdlib.h>
#include "glib-2.0/glib.h" 


typedef struct commits
{
    int repo_id;
    int author_id;
    int committer_id;
    char *commit_at;
    char *message;
} *LCOMMIT;

void GAddCommit (LCOMMIT commit, GHashTable *hash) {
    g_hash_table_insert (hash, &commit->repo_id, commit);  
}

int GContainsKey (int key, GHashTable *hash) {
    if(g_hash_table_contains(hash,&key)) {
        //printf("Chave existe\n");
        return 1;
    }

    return 0;
}

LCOMMIT GGetCommit(int key, GHashTable *hash) {
    LCOMMIT aux = (LCOMMIT)g_hash_table_lookup(hash, &key);
    if (aux == NULL) return NULL;
    else return aux;//funcao que clona o commit
}

void GCommit_free(GHashTable *hash) {
    g_hash_table_destroy(hash);
}

int main() {

    LCOMMIT commit = malloc(sizeof(struct commits));
   

    GHashTable *hash =  NULL;
    hash = g_hash_table_new_full(g_int_hash, g_int_equal); //, (GDestroyNotify)free, (GDestroyNotify)free_content_commits); //->Funcoes de destruicao de uma chave e seu valor, a funcao pros valores foi criada por nos
    printf("passei daqui \n");
    commit->repo_id = 123;
    commit->author_id = 23;
    commit->committer_id = 1;
    commit->commit_at = strdup("data");
    commit->message = strdup("ola");

    GAddCommit(commit, hash);
    if(GContainsKey(commit->repo_id, hash)) 
        printf("Chave existe\n");
    commit = GGetCommit(commit->repo_id, hash);
    
    //gpointer* key = g_hash_table_get_keys_as_array(hash,(guint*)2);
    //printf("first %p",key);

    return 0;
}