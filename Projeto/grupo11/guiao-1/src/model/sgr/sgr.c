#include "../../../include/model/file_work.h"
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
    //print_CR_GR_PTR(sgr->catalogo_repos);
    return sgr;
}
/*DEBUG
void print_SGR_CR_GR_PTR(SGR sgr){
    print_CR_GR_PTR(sgr->catalogo_repos);
}
*/
SGR fill_sgr(SGR sgr, char *userpath, char *commitspath, char *repospath) {
    //print_CR_GR_PTR(sgr->catalogo_repos);
    sgr->catalogo_users = ler_file_user(sgr->catalogo_users, userpath);
    sgr->catalogo_commits = ler_file_commits(sgr->catalogo_users, sgr->catalogo_commits, commitspath);
    //sgr->catalogo_repos = NULL;
    sgr->catalogo_repos = ler_file_repos(sgr->catalogo_users, sgr->catalogo_commits, sgr->catalogo_repos, repospath);
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


