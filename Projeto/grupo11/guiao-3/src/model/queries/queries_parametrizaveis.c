/**
 * @file queries_parametrizaveis.c
 * @author grupo11
 * @brief Ficheiro que contém as funções que executam as queries parametrizáveis
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../../../include/model/queries/queries_parametrizaveis.h"
#include "../../../include/model/Data.h"
#include "../../../include/model/Catalogo_Commits/catalogo_commits.h"
#include "../../../include/model/Catalogo_Commits/commits.h"
#include "../../../include/model/File_Work/file_work_aux.h"


/*-----------------Query 5-------------------------*/
int query5(int indice, int N, char* inicio, char* fim, SGR sgr){
    //int *chave = malloc(sizeof(int));
    //*chave = 5351700;
    clock_t start = clock();
    LCalendario c_inicio = build_calendario(inicio);
    LCalendario c_fim = build_calendario(fim);
    FILE *outstream = NULL;
    if(indice!=-1) { //PAGINAÇÃO
        outstream = output(indice);
    } else{
        outstream = fopen("saida/paginacao/query5_paginacao.csv","w+");
    }    

    int i;
    for (i = 0; i < N; i++) {
        //int j= maxOcor_Hash(sgr_get_cc_GOcorr(sgr), sgr_get_CC_usersID(sgr), sgr_get_CC_user(sgr));
        int j = g_array_index(sgr_get_CC_usersID(sgr),
        int,i);
        char *u = get_Login(sgr_get_CU_GUser(sgr, j));
        //int x = nOcor_Hash(sgr_get_cc_GOcorr(sgr), sgr_get_CC_usersID(sgr), sgr_get_CC_user(sgr));
        int *chave = malloc(sizeof(int));
        *chave = j;
        int x = g_hash_table_lookup(sgr_get_cc_GOcorr(sgr), chave);
        //g_hash_table_remove(sgr_get_cc_GOcorr(sgr), chave);
        fprintf(outstream, "ID: %i ; Login: %s ; Commit_qtty: %i\n", j, u, x);
    }
    //fprintf(outstream, " %i %s %s \n",N,inicio,fim);
    //encapsulamento hashtable ocorrencias

    fclose(outstream);
    clock_t end = clock() - start;
    int msec = end * 1000 / CLOCKS_PER_SEC;
    return msec;
}

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