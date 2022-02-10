/**
 * @file exercicios.c
 * @author grupo11
 * @brief Ficheiro que contém as funções necessárias para os guiões 1,2 e 3
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../../include/controller/exercicios.h"
#include "../../include/model/queries/queries_estatisticas.h"

int exercicio1(char *userpath, char *commitspath, char *repospath) {

    ler_Ficheiro_users(userpath);
    ler_Ficheiro_commits(commitspath);
    ler_Ficheiro_repos(repospath);


    return 0;
}

int exercicio2() {


    GHashTable *UTable = ler_file_user_ok();
    GArray *CArray = ler_file_commits_ok(UTable);
    GHashTable *RTable = ler_file_repos_ok(UTable);

    return 0;
}

int guiao1(char *argumento) {
    if(!strcmp(argumento, "exercicio-1")) {
        //printf("Argumento correto\n");
        exercicio1("entrada/users.csv", "entrada/commits.csv", "entrada/repos.csv");
    }

    if(!strcmp(argumento, "exercicio-2")) {
        //printf("Argumento correto\n");
        exercicio2();
    }
}

int guiao2(SGR sgr, char *queryID, int indice) {
    

    if(strcmp(queryID,"1\n") == 0) query1(indice,sgr);

    if(strcmp(queryID,"2\n") == 0) query2(indice,sgr);

    if(strcmp(queryID,"3\n") == 0) query3(indice,sgr);

    if(strcmp(queryID,"4\n") == 0) query4(indice,sgr);


    // Falta Fazer para as queries parametrizaveis

    return 0;
}
