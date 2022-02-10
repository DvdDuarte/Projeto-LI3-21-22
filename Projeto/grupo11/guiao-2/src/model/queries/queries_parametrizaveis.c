#include "../../../include/model/queries/queries_parametrizaveis.h"
#include "../../../include/model/queries/queries_estatisticas.h"
#include "../../../include/model/file_work.h"
#include "../../../include/model/Data.h"

/*-----------------Query 5-------------------------*//*
void query5(int indice, int N, char* inicio, char* fim, SGR sgr){
    int i=0;
    LCalendario c_inicio = build_calendario(inicio);
    LCalendario c_fim = build_calendario(fim);
    FILE *outstream = output(indice);

    LUSER* users = malloc(sizeof(LUSER) * N); //Guardar os N utilizadores que fizeram commits
    LCommits * n_commits = malloc(sizeof(LCommits) * 1000000); //Guardado os commits dos utilizadores mais ativos por ordem decrescente

    while(n_commits!=NULL && i<N){
        if(Calendario_Compere(c_inicio,c_fim,build_calendario(toString_Tempo(get_Commit_AT(n_commits[i]))))==1){
            users= strdup(sgr_get_CU_GUser(sgr, get_Author_ID(*n_commits))));
            users++;
            i++;
        }
        n_commits++;

    }
    int r;
    for(r=0;r<N;r++){
        fprintf(outstream,"%d;%s;%d\n", get_ID_User(users[r]), get_Login(users[r]), sgr_get_hashOcor(sgr,get_ID_User(users[r]))));
    }
}*/
/*-----------------Query 6-------------------------*//*
void query6(int indice, int N,char * linguagem,SGR sgr){
    int i=0;
    FILE *outstream = output(indice);

    LUSER* users = malloc(sizeof(LUSER) * N);
    LRepos * max_repos = malloc(sizeof (LRepos) * 1000000);
    char * language = get_Language(*max_repos);

    while(max_repos!=NULL && i<N){
        if(strcmp(language,linguagem)==0) {
            users = strdup(sgr_get_CU_GUser(sgr,get_Owner_ID(*max_repos)));
            users++;
            i++;
        }
        max_repos++;
    }
    int r;
    for(r=0;r<N;r++){
        fprintf(outstream,"%d;%s;%d\n", get_ID_User(users[r]), get_Login(users[r]), sgr_get_hashOcor(sgr,get_ID_User(users[r]))));
    }
}
*/
/*-----------------Query 7-------------------------*//*
void query7(int indice,int N,char * data,SGR sgr){
    int i=0;
    FILE *outstream = output(indice);
    LCalendario data_inicio = build_calendario(data);

    LRepos * repos = malloc(sizeof (LRepos) * 1000000);
    repos = sgr_get_da lista de repos sem commits

    while(repos!=NULL && i<N){
        if(Calendario_Compere(build_calendario(toString_Tempo(get_Update_At(repos[i]))))==1) {
            fprintf(outstream, "%d;%s\n",get_ID_Repo(*repos),get_Description(*repos));
            i++;
        }
        repos++;
    }
}*/
/*-----------------Query 8-------------------------*//*
void query8(int indice,int N,char * data,SGR sgr){

    FILE *outstream = output(indice);

    LCalendario data_inicial = build_calendario(data);
    char ** linguagens = malloc(sizeof(char*) * N);// array de strings que contem as N linguagens mais usadas
    while(linguagens!=NULL){
        fprintf(outstream,"%s\n",*linguagens);
        linguagens++;
    }
}

*/