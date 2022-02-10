#ifndef _USERS_H_
#define _USERS_H_

#include "../Funcoes_Aux.h"
#include "../Data.h"
#include "glib-2.0/glib.h" 

typedef enum type{
    BOT = 'Bot',
    ORGANIZATION = 'Organization',
    USER = 'User',
    INVALID = 'Invalid'
}TIPO;

typedef struct user NUSER, *LUSER;

//GHashTable Functions
void GAddUsers (LUSER user, GHashTable *hash);
LUSER GGetUser(int key, GHashTable *hash);
void GUsers_free(GHashTable *hash);

//Gets e Sets
int get_ID_User(LUSER u);
void set_ID_User(LUSER u, int id);
char* get_Login(LUSER u);
void set_Login(LUSER u, char* login);
TIPO get_Type(LUSER u);
void set_Type(LUSER u, TIPO type);
LTempo get_Created_At_User(LUSER u);
void set_Created_At_User(LUSER u, LTempo created_at);
int get_Followers(LUSER u);
void set_Followers(LUSER u, int followers);
int* get_Followers_List(LUSER u);
void set_Followers_List(LUSER u, const int* followers_list, int followers);
int get_Following(LUSER u);
void set_Following(LUSER u, int following);
int* get_Following_List(LUSER u);
void set_Following_List(LUSER u, const int* following_list, int following);
int get_Public_Gits(LUSER u);
void set_Public_Gits(LUSER u, int public_gits);
int get_Public_Repos(LUSER u);
void set_Public_Repos(LUSER u, int public_repos);

void free_User(LUSER u);
int valid_User(LUSER u);
LUSER build_User(char* line);

char* toString_Type(TIPO type);

#endif //_USERS_H_
