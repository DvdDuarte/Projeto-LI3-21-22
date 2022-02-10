#include "../../../include/model/Catalogo_Repos/catalogo_repos.h"

struct catalogo_repos{
    GHashTable *GRepos;
};

CREPOS initCRepos (){
    CREPOS crepos = malloc(sizeof(struct catalogo_repos));
    crepos->GRepos = g_hash_table_new(g_int_hash, g_int_equal);//g_hash_table_new(g_direct_hash, g_direct_equal);
    return crepos;
}

void set_CR_GRepos (CREPOS crepos, LRepos repos) {
    int *key = malloc(sizeof(int));
    *key = get_ID_Repo(repos);
    //printf("crepos->GRepos %p :: key %p :: repos %p\n", crepos->GRepos, key, repos);
    g_hash_table_insert(crepos->GRepos,key,repos);

}

int get_CR_GHSize (CREPOS crepos) {
    return g_hash_table_size(crepos->GRepos);
}

/*DEBUG
void print_CR_GR_PTR(CREPOS c) {
  printf("%p\n", c->GRepos);
}*/