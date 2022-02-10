
#include "../../include/model/File_Work.h"
#include "../../include/model/file_work_aux.h"

void gr_FicheiroC(FILE *fp, LCommits c){

    int repo_id = get_Repo_ID(c);
    int author_id = get_Author_ID(c);
    int committer_id = get_Committer_ID(c);
    char* commit_at = toString_Tempo(get_Commit_AT(c));
    char* message = get_Message(c);

    fprintf(fp, "%d;%d;%d;%s;%s\r\n", repo_id, author_id, committer_id, commit_at, message);

}

void gr_FicheiroR(FILE *fp, LRepos r){

    int id = get_ID_Repo(r);
    int owner_id = get_Owner_ID(r);
    char* full_name = get_Full_Name(r);
    char* lincense = get_License(r);
    int has_wiki = get_Has_Wiki(r);
    char* aux_has_wiki;
    if(has_wiki == 1)
        aux_has_wiki = strdup("True");
    else if(has_wiki == 0)
        aux_has_wiki = strdup("False");
    else
        aux_has_wiki = strdup("None");
    char* description = get_Description(r);
    char* language = get_Language(r);
    char* default_branch = get_Default_Branch(r);
    char* created_at = toString_Tempo(get_Created_At(r));
    char* updated_at = toString_Tempo(get_Update_At(r));
    int fork_count = get_Forks_Count(r);
    int open_issues = get_Open_Issues(r);
    int stargazers_count = get_Stargazers_Count(r);
    int size = get_Size(r);

    fprintf(fp, "%d;%d;%s;%s;%s;%s;%s;%s;%s;%s;%d;%d;%d;%d\r\n", id, owner_id, full_name, lincense, aux_has_wiki, description, language, default_branch, created_at, updated_at, fork_count, open_issues, stargazers_count, size);

}

void toString_list(FILE *fp, int* list, int size){

    fprintf(fp, "%d;[", size);
    int i;
    if(list != NULL) {
        for (i = 0; i < (size - 1); i++)
            fprintf(fp, "%d, ", list[i]);
        fprintf(fp, "%d];", list[i]);
    }else fprintf(fp, "];");

}

void gr_FicheiroU(FILE *fp, LUSER u){

    int id = get_ID_User(u);
    char* login = get_Login(u);
    char* type = toString_Type(get_Type(u));
    char* created_at = toString_Tempo(get_Created_At_User(u));
    int followers = get_Followers(u);
    int* followers_list = get_Followers_List(u);
    int following = get_Following(u);
    int* following_list = get_Following_List(u);
    int public_gits = get_Public_Gits(u);
    int public_repos = get_Public_Repos(u);

    fprintf(fp, "%d;%s;%s;%s;", id, login, type, created_at);
    toString_list(fp, followers_list,followers);
    toString_list(fp, following_list, following);
    fprintf(fp, "%d;%d\r\n", public_gits, public_repos);

}

void ler_Ficheiro(char* file_name){

    char path[50] = "entrada/";
    strcat(path, file_name);

    FILE *fp = fopen(path, "r");
    char* line = malloc(sizeof(char) * 1000000);

    if(strcmp("users-g3.csv", file_name) == 0){
        char* new_file_name = strdup("saida/users-ok.csv");
        FILE *new_fp = fopen(new_file_name, "w");
        fprintf(new_fp, "id;login;type;created_at;followers;follower_list;following;following_list;public_gists;public_repos\r\n");
        while(fgets(line, 1000000, fp)){
            LUSER u = build_User(line);
            if(u != NULL) {
                gr_FicheiroU(new_fp, u);
                free_User(u);
            }
        }
        fclose(new_fp);
    } else if(strcmp("commits-g3.csv", file_name) == 0){
        char* new_file_name = strdup("saida/commits-ok.csv");
        char* help_file = strdup("saida/repos-aux.csv");
        FILE *new_fp = fopen(new_file_name, "w");
        FILE *id_file = fopen(help_file, "w");
        fprintf(new_fp, "repo_id;author_id;committer_id,commit_at;message\r\n");
        while(fgets(line, 1000000, fp)){
            LCommits c = build_Commit(line);
            if(c != NULL){
                gr_FicheiroC(new_fp, c);
                fprintf(id_file,"%d;\r\n", get_Repo_ID(c));
                free_Commit(c);
            }
        }
        fclose(new_fp);
        fclose(id_file);
    }else if(strcmp("repos-g3.csv", file_name) == 0){
        char* new_file_name = strdup("saida/repos-ok.csv");
        FILE *new_fp = fopen(new_file_name, "w");
        fprintf(new_fp, "id;owner_id;full_name;license;has_wiki;description;language;default_branch;created_at;updated_at;forks_count;open_issues;stargazers_count;size\r\n");
        int i = 0;
        while(fgets(line, 1000000, fp)){
            LRepos r = build_Repos(line);
            if(r != NULL) {
                printf("repos %d\n",i);
                gr_FicheiroR(new_fp, r);
                free_Repos(r);
                i++;
            }
        }
        fclose(new_fp);
    }else{
        printf("Nome de Ficheiro inválido!!\n");
    }
    printf("Ficheiro %s lido com sucesso!!\n", file_name);
    fclose(fp);
    free(line);
}

//Exercicio 2

GHashTable *ler_file_user_ok() {

    GHashTable *UTable = g_hash_table_new/*_full*/(g_int_hash, g_int_equal); //, (GDestroyNotify)free, (GDestroyNotify)free_content_commits);)

    FILE *leitura, *escrita;

    leitura = fopen("saida/users-ok.csv","r");
    escrita = fopen("saida/users-final.csv","w+");

    if(leitura == NULL) {
        perror("File not found - users-ok!");
        return NULL;
    }

    if(escrita == NULL) {
        perror("File not found - users-final!");
        return NULL;
    }

    char buffer[buffer_size];
    char *buffer2;

    int i = 0;
    LUSER user;

    fgets(buffer, buffer_size, leitura);
    fprintf(escrita,"%s",buffer);

    while(fgets(buffer,buffer_size, leitura)) {
        buffer2 = strdup(buffer);
        user = build_User(buffer2);
        GAddUsers(user, UTable);
        fprintf(escrita,"%s",buffer);

    }

    fclose(leitura);
    fclose(escrita);

    return UTable;

}

GArray *ler_file_commits_ok(GHashTable *table) {
    GArray *commit_list;
    commit_list = g_array_new(FALSE, FALSE, sizeof(LCommits));

    FILE *leitura, *escrita, *escritaux;

    leitura = fopen("saida/commits-ok.csv","r");
    escrita = fopen("saida/commits-final.csv","w");
    escritaux = fopen("saida/commits-aux.csv", "w");

    if(leitura == NULL) {
        perror("File not found - commits-ok!");
        return NULL;
    }

    if(escrita == NULL) {
        perror("File not found - commits-final!");
        return NULL;
    }
    fprintf(escrita, "repo_id;author_id;committer_id;commit_at;message\r\n");

    GHashTable *reposID = ler_file_aux("saida/repos-aux.csv");

    char buffer[buffer_size];
    char *buffer2;

    LCommits commit;

    fgets(buffer, buffer_size, leitura);

    int indx = 0;
    while(fgets(buffer,buffer_size, leitura)) {
        buffer2 = strdup(buffer);
        commit = build_Commit(buffer2);
        if(verifica_users_GCommit(commit, table) && verifica_repos_commit(commit, reposID)) {
            GAddCommit(commit, commit_list);
            fprintf(escrita, "%s", buffer);
            fprintf(escritaux, "%d;\n", get_Repo_ID(commit));
        }
        else free_Commit(commit);
        indx++;
    }

    fclose(leitura);
    fclose(escrita);

    return commit_list;
}

GHashTable  *ler_file_repos_ok(GHashTable *users) {

    GHashTable *Trepos = g_hash_table_new(g_int_hash, g_int_equal);

    FILE *leitura, *escrita;

    leitura = fopen("saida/repos-ok.csv","r");
    escrita = fopen("saida/repos-final.csv","w+");

    if(leitura == NULL) {
        perror("File not found - repos-ok");
        return NULL;
    }

    if(escrita == NULL) {
        perror("File not found - repos-final!");
        return NULL;
    }

    fprintf(escrita, "id;owner_id;full_name;license;has_wiki;description;language;default_branch;created_at;updated_at;forks_count;open_issues;stargazers_count;size\r\n");


    char buffer[buffer_size];
    char *buffer2; //= malloc(sizeof (char) * buffer_size);

    int i = 0;
    LRepos repo;
    GHashTable *commitsReposID = ler_file_aux("saida/commits-aux.csv");


    fgets(buffer, buffer_size, leitura);

    while(fgets(buffer,buffer_size, leitura)) {
        buffer2 = strdup(buffer);
        repo = build_Repos(buffer2);
        //printf("%d - %s", i, buffer);
        if(repo != NULL && verifica_owner_id(repo, users) && verica_commits_repo(repo, commitsReposID)) {
            GAddRepos(repo, Trepos);
            fprintf(escrita, "%s", buffer);
        }
        else free_Repos(repo);
        i++;
    }

    fclose(leitura);

    return Trepos;
}
