/**
 * @file queries_estatisticas.c
 * @author grupo11
 * @brief Ficheiro que contém as funções que executam as queries estatísticas
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../../../include/model/queries/queries_estatisticas.h"
#define buffer_size 1000000

// Query 1
void query1(int indice, SGR sgr){
    clock_t start = clock();
    if(indice != -1) {
        FILE *outstream = output(indice);
        if(outstream == NULL)
            perror("Could not open file!");
        int bots = sgr_get_CU_bots(sgr);
        int org = sgr_get_CU_org(sgr);
        int user = sgr_get_CU_user(sgr);
        clock_t fim = clock() - start;
        int msec = fim * 1000 / CLOCKS_PER_SEC;
        query1_output(outstream, bots, org, user, msec);
        fclose(outstream);

    } else if(indice == -1) {
        int bots = sgr_get_CU_bots(sgr);
        int org = sgr_get_CU_org(sgr);
        int user = sgr_get_CU_user(sgr);
        clock_t fim = clock() - start;
        int msec = fim * 1000 / CLOCKS_PER_SEC;
        query1_output(NULL, bots, org, user, msec);
        //fprintf(stdout, "Bot: %d\nOrganization: %d\nUser: %d\n", bots, org, user);
    }
    

}


// Query 2

void query2(int indice, SGR sgr) {

    clock_t start = clock();
    if(indice != -1) {
        FILE *outstream = output(indice);
        if(outstream == NULL)
            perror("Could not open file!");

        float avg;
        int colaboradores = sgr_get_CC_user(sgr);
        int repos = sgr_get_CC_repos(sgr);
        avg = colaboradores / repos;
        clock_t fim = clock() - start;
        int msec = fim * 1000 / CLOCKS_PER_SEC;
        queries_pares_output(outstream, 2, avg, msec);
        //fprintf(outstream, "%.2f\n", avg);
        fclose(outstream);
    } else if(indice == -1) {
        float avg;
        int colaboradores = sgr_get_CC_user(sgr);
        int repos = sgr_get_CC_repos(sgr);
        avg = colaboradores / repos;
        clock_t fim = clock() - start;
        int msec = fim * 1000 / CLOCKS_PER_SEC;
        queries_pares_output(NULL, 2, avg, msec);
    }


}


// Query 3

void query3(int indice, SGR sgr) {

    clock_t start = clock();
    int bots = sgr_get_CC_bots(sgr);

    if(indice != -1) {
        FILE *outstream = output(indice);

        if(outstream == NULL)
            perror("Could not open file!");
        clock_t fim = clock() - start;
        int msec = fim * 1000 / CLOCKS_PER_SEC;
        query3_output(outstream, bots, msec);

        //fprintf(outstream, "%d\n", bots);
    
    fclose(outstream);
    } else {
        clock_t fim = clock() - start;
        int msec = fim * 1000 / CLOCKS_PER_SEC;
        query3_output(NULL, bots, msec);
    }
}

// Query 4

void query4(int indice, SGR sgr) {

    clock_t start = clock();
    int nusers = sgr_get_CC_user(sgr);
    int ncommits = sgr_get_CC_total_commits(sgr);
    float avg = ncommits / nusers;

    if(indice != -1) {
        FILE *outstream = output(indice);

        if(outstream == NULL)
            perror("Could not open file!");
        clock_t fim = clock() - start;
        int msec = fim * 1000 / CLOCKS_PER_SEC;
        queries_pares_output(outstream, 4, avg, msec);

    //fprintf(outstream, "%.2f\n", avg);
    
    fclose(outstream);
    } else {
        clock_t fim = clock() - start;
        int msec = fim * 1000 / CLOCKS_PER_SEC;
        queries_pares_output(NULL, 4, avg, msec);
    }
}
