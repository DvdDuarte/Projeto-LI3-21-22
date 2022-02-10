/**
 * @file users.h
 * @author grupo11
 * @brief Ficheiro que contém as funções que para trabalhar com os users
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _USERS_H_
#define _USERS_H_

#include "../Funcoes_Aux.h"
#include "../Data.h"
#include "glib-2.0/glib.h"

#define Bot 0
#define Organization 1
#define User 2
#define Invalid -1

/**
 * Tipo de dados referente ao tipo de utilizador
 */
typedef enum type{
    BOT = 0,
    ORGANIZATION = 1,
    USER = 2,
    INVALID = -1
}TIPO;

/**
 * Tipo de dados a ser utilizado sempre que se queira criar um utilizador
 */
typedef struct user NUSER, *LUSER;

//GHashTable Functions

/**
 *
 * @param user
 * @param hash
 */
void GAddUsers (LUSER user, GHashTable *hash);

/**
 *
 * @param key
 * @param hash
 * @return
 */
LUSER GGetUser(int key, GHashTable *hash);

/**
 *
 * @param hash
 */
void GUsers_free(GHashTable *hash);

//Gets e Sets

/**
 *
 * @param u
 * @return
 */
int get_ID_User(LUSER u);

/**
 *
 * @param u
 * @param id
 */
void set_ID_User(LUSER u, int id);

/**
 *
 * @param u
 * @return
 */
char* get_Login(LUSER u);

/**
 *
 * @param u
 * @param login
 */
void set_Login(LUSER u, char* login);

/**
 *
 * @param u
 * @return
 */
TIPO get_Type(LUSER u);

/**
 *
 * @param u
 * @param type
 */
void set_Type(LUSER u, TIPO type);

/**
 *
 * @param u
 * @return
 */
LTempo get_Created_At_User(LUSER u);

/**
 *
 * @param u
 * @param created_at
 */
void set_Created_At_User(LUSER u, LTempo created_at);

/**
 *
 * @param u
 * @return
 */
int get_Followers(LUSER u);

/**
 *
 * @param u
 * @param followers
 */
void set_Followers(LUSER u, int followers);

/**
 *
 * @param u
 * @return
 */
int* get_Followers_List(LUSER u);

/**
 *
 * @param u
 * @param followers_list
 * @param followers
 */
void set_Followers_List(LUSER u, const int* followers_list, int followers);

/**
 *
 * @param u
 * @return
 */
int get_Following(LUSER u);

/**
 *
 * @param u
 * @param following
 */
void set_Following(LUSER u, int following);

/**
 *
 * @param u
 * @return
 */
int* get_Following_List(LUSER u);

/**
 *
 * @param u
 * @param following_list
 * @param following
 */
void set_Following_List(LUSER u, const int* following_list, int following);

/**
 *
 * @param u
 * @return
 */
int get_Public_Gits(LUSER u);

/**
 *
 * @param u
 * @param public_gits
 */
void set_Public_Gits(LUSER u, int public_gits);

/**
 *
 * @param u
 * @return
 */
int get_Public_Repos(LUSER u);

/**
 *
 * @param u
 * @param public_repos
 */
void set_Public_Repos(LUSER u, int public_repos);

/**
 *
 * @param u
 */
void free_User(LUSER u);

/**
 *
 * @param u
 * @return
 */
int valid_User(LUSER u);

/**
 *
 * @param line
 * @return
 */
LUSER build_User(char* line);

/**
 *
 * @param type
 * @return
 */
char* toString_Type(TIPO type);

#endif //_USERS_H_
