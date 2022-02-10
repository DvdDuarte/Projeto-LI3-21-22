
#include "../../include/controller/exercicios.h"
#include "../../include/model/queries/queries_estatisticas.h"

int exercicio1() {

    ler_Ficheiro("users.csv");
    ler_Ficheiro("commits.csv");
    ler_Ficheiro("repos.csv");

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
        exercicio1();
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
