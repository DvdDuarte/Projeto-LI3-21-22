#include "../../../include/model/Catalogo_User/catalogo_users.h"

struct catalogo_user{
    GHashTable *GUser;
    int bots;
    int org;
    int user;
   // int id;
  //  char* login;
};

CUSER initCUsers (){
    CUSER cusers  = malloc(sizeof(struct catalogo_user));
    //cusers->GUser = g_hash_table_new(g_direct_hash, g_direct_equal);
    cusers->GUser = g_hash_table_new(g_int_hash, g_int_equal);
    cusers->bots = 0;
    cusers->org = 0;
    cusers->user = 0;

    return cusers;
}

void add_CU_GUser(CUSER cuser, LUSER user) {

    int *key = malloc(sizeof (int));
    *key =  get_ID_User(user);
    g_hash_table_insert (cuser->GUser, key, user);
   // isto equivale ao que está abaixo

   //g_hash_table_insert (cuser->GUser, GINT_TO_POINTER(get_ID_User(user)), user);
}

LUSER get_CU_GUser(CUSER cuser, int key) {
    LUSER luser = GGetUser(key,cuser->GUser);
    return luser;
}

int verifica_CU_User (CUSER cuser, int key) {
    return GContainsKey(key, cuser->GUser);
}

int get_CU_bots (CUSER cuser) {
    return cuser->bots;
}

int get_CU_org (CUSER cuser) {
    return cuser->org;
}

int get_CU_user (CUSER cuser) {
    return cuser->user;
}

//int get_CU_id(CUSER cuser) {
//    return cuser->id;
//}

//char * get_CU_login(CUSER cuser) {
//    return cuser->login;
//}

void set_CU_GUser (CUSER cuser, LUSER user) {
    GAddUsers(user,cuser->GUser);
}

void set_CU_bots (CUSER cuser, int bots) {
    cuser->bots = bots;
}

void set_CU_org (CUSER cuser, int org) {
    cuser->org = org;
}

void set_CU_user (CUSER cuser, int nuser) {
    cuser->user = nuser;
}

int get_size(CUSER u){
    return g_hash_table_size(u->GUser);
}

void imprime_vals(gpointer key, gpointer val, gpointer user_data){
    printf("%d - %s\n",(int) key , get_Login((char*)val));
}

void verifica_user_table(CUSER u){
    printf("%d\n", get_size(u));
    printf("%d\n", g_hash_table_contains (u->GUser, GINT_TO_POINTER (26538122) ));
    printf("%d\n", g_hash_table_contains (u->GUser, GINT_TO_POINTER (1893) ));
    // imprimir valores
    g_hash_table_foreach(u->GUser, imprime_vals, NULL);
}