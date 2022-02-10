
#include "../../include/controller/exercicios.h"
#include "../../include/model/File_Work.h"
#include "../../include/model/queries/queries_estatisticas.h"

int exercicio1() {

    //ler_Ficheiro("users-g3.csv");
    ler_Ficheiro("commits-g3.csv");
    ler_Ficheiro("repos-g3.csv");

    return 0;
}

int exercicio2() {


    GHashTable *UTable = ler_file_user_ok();
    GArray *CArray = ler_file_commits_ok(UTable);
    GHashTable *RTable = ler_file_repos_ok(UTable);

    return 0;
}

int guiao1(char *argumento) {
    if(strcmp(argumento, "exercicio-1")  == 0) {
        //printf("Argumento correto\n");
        exercicio1();
    }

    if(strcmp(argumento, "exercicio-2")  == 0) {
        //printf("Argumento correto\n");
        exercicio2();
    }
}
