#include "../../include/model/file_work.h"
#include "../../include/model/Catalogo_Commits/catalogo_commits.h"
#include "../../include/model/Data.h"


CUSER ler_file_user(CUSER catalogo_user, char *filepath) {

    FILE *leitura;

    leitura = fopen(filepath,"r");

    if(leitura == NULL) {
        perror("File not found - users-g2.csv!");
        return NULL;
    }

    char buffer[buffer_size];
    char *buffer2;

    int bots = 0;
    int org = 0;
    int nuser = 0;
    int invalids = 0;

    LUSER user;

    fgets(buffer, buffer_size, leitura);

    while(fgets(buffer,buffer_size, leitura)) {
        buffer2 = strdup(buffer);
        user = build_User(buffer2);
        add_CU_GUser(catalogo_user,user);

        switch(get_Type(user)) {
            case 0 :
                bots++;
                break;

            case 1 :
                org++;
                break;

            case 2 :
                nuser++;
                break;

            case INVALID:
                invalids++;
                break;

            default :
                printf("Reading...");
                break;
        }
    }

    set_CU_bots(catalogo_user,bots);
    set_CU_org(catalogo_user,org);
    set_CU_user(catalogo_user,nuser);

    fclose(leitura);

    return catalogo_user;

}

CCOMMITS ler_file_commits(CUSER catalogo_users, CCOMMITS catalogo_commits, char *filepath) {


    GArray *commit_list;
    commit_list = g_array_new(FALSE, FALSE, sizeof(LCommits));

    FILE *leitura, *escritaAux;

    leitura = fopen(filepath,"r");
    escritaAux = fopen("saida/commits-aux.csv", "w");

    if(leitura == NULL) {
        perror("File not found - commits-g2.csv!");
        return NULL;
    }

    /*GHashTable *reposID = ler_file_aux("saida/repos-aux.csv");

    if(reposID == NULL) {
        perror("File not found - repos-aux.csv!");
        return NULL;
    }*/

    char buffer[buffer_size];
    char *buffer2;

    LCommits commit;
    fgets(buffer, buffer_size, leitura);

    int existe_user = 0, existe_repo = 0, nusers = 0, nrepos = 0, nbots = 0, ncommits = 0, commiter_id = 0;
    TIPO tipo_user = INVALID;

    while(fgets(buffer, buffer_size, leitura)) {
        buffer2 = strdup(buffer);
        commit = build_Commit(buffer2);
        commiter_id = get_Committer_ID(commit);
        fprintf(escritaAux, "%d;\n", commiter_id);

        if(verifica_CU_User(catalogo_users, commiter_id)){ //&& verifica_repos_commit(commit, reposID)) {
            GAddCommit(commit, commit_list);

            tipo_user = get_Type(get_CU_GUser(catalogo_users, commiter_id));

            existe_user = set_CC_GHashTable(catalogo_commits, commit,0); //adiciona o commit a um garray que vai ser inserido na hashtable e indica se a chave ja existia ou não
            existe_repo = set_CC_GHashTable(catalogo_commits, commit,1); //adiciona o commit a um garray que vai ser inserido na hashtable e indica se a chave ja exist1a ou não

            if(!existe_user) {
                if (tipo_user == BOT)
                    nbots++;
                else if (tipo_user == USER)
                    nusers++;
            }
            if(!existe_repo) {
                nrepos++;
                existe_repo = 0;
            }
            ncommits++;
        } else free_Commit(commit);


    }

    set_CC_GCommits(catalogo_commits, commit_list);
    set_CC_Nrepos(catalogo_commits, nrepos);
    set_CC_Nusers(catalogo_commits, nusers);
    set_CC_Nbots(catalogo_commits, nbots);
    set_CC_total_commits(catalogo_commits,ncommits);

    fclose(leitura);
    fclose(escritaAux);
    //GHashTable_free(reposID);

    return catalogo_commits;
}


CREPOS  ler_file_repos(CUSER catalogo_users, CCOMMITS catalogo_commits, CREPOS catalogo_repos, char *filepath) {

    FILE *leitura;

    //catalogo_repos = NULL;

    leitura = fopen(filepath,"r");

    if(leitura == NULL) {
        perror("File not found - repos-g2.csv!");
        return NULL;
    }

    char buffer[buffer_size];
    char *buffer2;

    int i = 0;
    LRepos repo;
    //GHashTable *commitsReposID = ler_file_aux("../saida/commits-aux.csv");


    fgets(buffer, buffer_size, leitura);

    while(fgets(buffer,buffer_size, leitura)) {
        buffer2 = strdup(buffer);
        repo = build_Repos(buffer2);

        if(repo != NULL && verifica_CU_User(catalogo_users, get_Owner_ID(repo))){//&& verifica_CC_reposID(catalogo_commits,repo)) {
            set_CR_GRepos(catalogo_repos, repo);
        } else free_Repos(repo);
        i++;
    }

    fclose(leitura);

    return catalogo_repos;
}



/*
CCOMMITS HashOcor_commits(CUSER catalogo_users,CCOMMITS catalogo_commits, LCalendario data1 , LCalendario data2) {

    THash * hash_table= get_hashOcor(catalogo_commits);
    FILE *leitura;

    leitura = fopen("entrada/commits-g2.csv","r");

    if(leitura == NULL) {
        perror("File not found!");
        return NULL;
    }

    char buffer[buffer_size];
    char *buffer2;

    LCommits commit;

    fgets(buffer, buffer_size, leitura);

    while(fgets(buffer,buffer_size, leitura)) {
        buffer2 = strdup(buffer);
        commit = build_Commit(buffer2);
        if(verifica_CU_User(catalogo_users, get_Committer_ID(commit)) && verifica_repos_commit(commit, reposID)) {
            if(Calendario_Compere(data1,data2,build_calendario(toString_Tempo(get_Commit_AT(commit))))==1){
                addHash_Ocor(get_Committer_ID(commit),hash_table);
            }
        }
        else free_Commit(commit);
    }

    set_hashOcor(catalogo_commits,hash_table);
    fclose(leitura);

    return catalogo_commits;
}
*/
