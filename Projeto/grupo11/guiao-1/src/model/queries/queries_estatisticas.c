#include "../../../include/model/queries/queries_estatisticas.h"
#define buffer_size 1000000



// Query 1
void query1(int indice, SGR sgr){


    FILE *outstream = output(indice);

    if(outstream == NULL)
        perror("Culd not open file!");

    int bots = sgr_get_CU_bots(sgr);
    int org = sgr_get_CU_org(sgr);
    int user = sgr_get_CU_user(sgr);

    fprintf(outstream, "Bot: %d\nOrganization: %d\nUser: %d\n", bots, org, user);
    
    fclose(outstream);

}


// Query 2

void query2(int indice, SGR sgr) {

    FILE *outstream = output(indice);

    if(outstream == NULL)
        perror("Could not open file!");

    float avg;
    int colaboradores = sgr_get_CC_user(sgr);
    int repos = sgr_get_CC_repos(sgr);
    avg = colaboradores / repos;

    fprintf(outstream, "%.2f\n", avg);
    
    fclose(outstream);
}


// Query 3

void query3(int indice, SGR sgr) {

    FILE *outstream = output(indice);

    if(outstream == NULL)
        perror("Could not open file!");

    int bots = sgr_get_CC_bots(sgr);

    fprintf(outstream, "%d\n", bots);
    
    fclose(outstream);
}

// Query 4

void query4(int indice, SGR sgr) {
    FILE *outstream = output(indice);

    if(outstream == NULL)
        perror("Could not open file!");

    int nusers = sgr_get_CC_user(sgr);
    int ncommits = sgr_get_CC_total_commits(sgr);
    float avg = ncommits / nusers;

    fprintf(outstream, "%.2f\n", avg);
    
    fclose(outstream);
}
