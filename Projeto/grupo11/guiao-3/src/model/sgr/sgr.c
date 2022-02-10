/**
 * @file sgr.c
 * @author grupo11
 * @brief Ficheiro que contém as funções que para trabalhar com o SGR
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../../../include/model/File_Work/catalogs_file_work.h" 
#include "../../../include/model/sgr/sgr.h"

struct sgr{
    CCOMMITS catalogo_commits;
    CREPOS  catalogo_repos;
    CUSER catalogo_users;
};

SGR init_sgr() {
    SGR sgr = malloc(sizeof(struct sgr));
    sgr->catalogo_users = initCUsers();;
    sgr->catalogo_commits = initCCommits();
    sgr->catalogo_repos = initCRepos();
    return sgr;
}
/*DEBUG
void print_SGR_CR_GR_PTR(SGR sgr){
    print_CR_GR_PTR(sgr->catalogo_repos);
}
*/

SGR fill_sgr(SGR sgr, char *userpath, char *commitspath, char *repospath) {
    printLoadingUI();
    clock_t start = clock();
    exercicio1(userpath,commitspath,repospath);
    sgr->catalogo_users = ler_file_user(sgr->catalogo_users, "saida/users-ok.csv");
    sgr->catalogo_commits = ler_file_commits(sgr->catalogo_users, sgr->catalogo_commits, "saida/commits-ok.csv");
    sgr->catalogo_repos = ler_file_repos(sgr->catalogo_users, sgr->catalogo_commits, sgr->catalogo_repos, "saida/repos-ok.csv");
    clock_t fim = clock() - start;
    int msec = fim * 1000 / CLOCKS_PER_SEC;
    printBuildingAppTime(msec);
    return sgr;
}

int sgr_get_CU_bots(SGR sgr){
    return get_CU_bots(sgr->catalogo_users);
}

int sgr_get_CU_org(SGR sgr){
    return get_CU_org(sgr->catalogo_users);
}

int sgr_get_CU_user(SGR sgr){
    return get_CU_user(sgr->catalogo_users);
}

int sgr_get_CC_user(SGR sgr){
    return get_CC_Nusers(sgr->catalogo_commits);
}

int sgr_get_CC_repos(SGR sgr){
    return get_CC_Nrepos(sgr->catalogo_commits);
}

int sgr_get_CC_bots(SGR sgr){
    return get_CC_Nbots(sgr->catalogo_commits);
}

int sgr_get_CC_total_commits(SGR sgr) {
    return get_CC_total_commits(sgr->catalogo_commits);
}

GArray * sgr_get_CC_usersID(SGR sgr) {
    return get_CC_usersID(sgr->catalogo_commits);
}

GHashTable * sgr_get_cc_GOcorr(SGR sgr){
    return get_hashOcor(sgr->catalogo_commits);
}


LUSER sgr_get_CU_GUser(SGR sgr, int key){
    return get_CU_GUser(sgr->catalogo_users,key);
}



