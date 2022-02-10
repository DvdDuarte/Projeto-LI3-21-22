#include "../../../include/model/Catalogo_User/users.h"

struct user{
    int id;
    char* login;
    TIPO type;
    LTempo created_at;
    int followers;
    int* followers_list;
    int following;
    int* following_list;
    int public_gits;
    int public_repos;
};

//GLIB Funcs
void GAddUsers (LUSER user, GHashTable *hash) {
    if(user == NULL) return;
    g_hash_table_insert (hash, &user->id, user);
}

LUSER GGetUser(int key, GHashTable *hash) {
    LUSER aux = (LUSER)g_hash_table_lookup(hash, &key);
    if (aux == NULL) return NULL;
    else return aux;//funcao que clona o user
}

//Gets e Sets
int get_ID_User(LUSER u){
    return u->id;
}

void set_ID_User(LUSER u, int id){
    u->id = id;
}

char* get_Login(LUSER u){
    return strdup(u->login);
}

void set_Login(LUSER u, char* login){
    free(u->login);
    u->login = strdup(login);
}

TIPO get_Type(LUSER u){
    return u->type;
}

void set_Type(LUSER u, TIPO type){
    u->type = type;
}

LTempo get_Created_At_User(LUSER u){
    return clone_Tempo(u->created_at);
}

void set_Created_At_User(LUSER u, LTempo created_at){
    free(u->created_at);
    u->created_at = clone_Tempo(created_at);
}

int get_Followers(LUSER u){
    return u->followers;
}

void set_Followers(LUSER u, int followers){
    u->followers = followers;
}

int* get_Followers_List(LUSER u){

    if(u->followers_list == NULL)
        return NULL;

    int* fl = malloc(sizeof(int) * u->followers);
    for(int i = 0; i < u->followers; i++)
        fl[i] = u->followers_list[i];

    return fl;
}

void set_Followers_List(LUSER u, const int* followers_list, int followers){

    free(u->followers_list);
    set_Followers(u, followers);
    u->followers_list = malloc(sizeof(int) * followers);
    for(int i = 0; i < followers; i++)
        u->followers_list[i] = followers_list[i];

}

int get_Following(LUSER u){
    return u->following;
}

void set_Following(LUSER u, int following){
    u->following = following;
}

int* get_Following_List(LUSER u){

    if(u->following_list == NULL)
        return NULL;

    int* fl = malloc(sizeof(int) * u->following);
    for(int i = 0; i < u->following; i++)
        fl[i] = u->following_list[i];

    return fl;
}

void set_Following_List(LUSER u, const int* following_list, int following){

    free(u->following_list);
    set_Following(u, following);
    u->following_list = malloc(sizeof(int) * following);
    for(int i = 0; i < following; i++)
        u->following_list[i] = following_list[i];

}

int get_Public_Gits(LUSER u){
    return u->public_gits;
}

void set_Public_Gits(LUSER u, int public_gits){
    u->public_gits = public_gits;
}

int get_Public_Repos(LUSER u){
    return u->public_repos;
}

void set_Public_Repos(LUSER u, int public_repos){
    u->public_repos = public_repos;
}

void free_User(LUSER u){

    free(u->login);
    free(u->created_at);
    free(u->followers_list);
    free(u->following_list);

    free(u);

}

int valid_lists(const int* list, int size){

    int valid = 1;

    if(list == NULL && size > 0)
        valid = 0;

    return valid;

}

int valid_User(LUSER u){

    int valid = 1;

    if(u->id < 0 || u->followers < 0 || u->following < 0 || u->public_gits < 0 || u->public_repos < 0)
        valid = 0;
    else if(strcmp(u->login, "") == 0)
        valid = 0;
    else if(u->type == INVALID)
        valid = 0;
    else if(!valid_lists(u->followers_list, u->followers) || !valid_lists(u->following_list, u->following))
        valid = 0;
    else if(get_Created_At_User(u) == NULL )
        valid = 0;

    return valid;

}

TIPO build_Type(char* line){

    if(strcmp(line, "Bot") == 0)
        return BOT;
    else if(strcmp(line, "Organization") == 0)
        return ORGANIZATION;
    else if(strcmp(line, "User") == 0)
        return USER;
    else
        return INVALID;
}

int* build_list(char* line, int size, int* valid){

    int* list = malloc(sizeof(int) * size);
    if(strcmp(line, "") == 0 || line[0] != '['){
        *valid = 0;
        return NULL;
    }else if(strcmp(line, "[]") == 0)
        list = NULL;
    else if (size > 0){
        strsep(&line, "[");
        int i;
        char *nums = strsep(&line, "]");
        for (i = 0; nums != NULL;) {
            list[i++] = digitorChar(strsep(&nums, ","));
            while(nums && nums[0] == ' ')
                strsep(&nums, " ");
        }

        if(i != size)
            *valid = 0;

        int j = 0;
        while(*valid && j < size)
            if(list[j++] < 0)
                *valid = 0;
    }

    return list;

}

LUSER build_User(char* line){

    LUSER u = malloc(sizeof(NUSER));

    u->id = digitorChar(strsep(&line, ";\n"));
    u->login = strdup(strsep(&line, ";\n"));
    u->type = build_Type(strsep(&line, ";\n"));
    u->created_at = build_time(strsep(&line, ";\n"));
    u->followers = digitorChar(strsep(&line, ";\n"));
    int valid = 1;
    u->followers_list = build_list(strsep(&line, ";\n"), u->followers, &valid);
    u->following = digitorChar(strsep(&line, ";\n"));
    u->following_list = build_list(strsep(&line, ";\n"), u->following, &valid);
    u->public_gits = digitorChar(strsep(&line, ";\n"));
    u->public_repos = digitorChar(strsep(&line, ";\r\n"));

    if(!valid_User(u) || !valid){
        free_User(u);
        u = NULL;
    }

    return u;
}

char* toString_Type(TIPO type){

    if(type == BOT)
        return strdup("Bot");
    else if(type == ORGANIZATION)
        return strdup("Organization");
    else if(type == USER)
        return strdup("User");
    else
        return NULL;

}
