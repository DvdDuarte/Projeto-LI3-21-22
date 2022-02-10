/**
 * @file queries_output.h
 * @author grupo11
 * @brief Ficheiro que contém as funções para apresentar os resultados das queries
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../../include/view/queries_output.h"


void query1_output(FILE *outstream, int bots, int org, int user, int time){

    if(outstream == NULL) {
        printQueriesTop();
        puts(BOLD_CYAN);
        printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("                     ║                                                                                            ║\n");
        printf("                     ║        %sBot: %s%d",BOLD_BRIGHT_MAGENTA, RESET, bots);
        char sbots[buffer_size];
        sprintf(sbots, "%d", bots);
        int sbots_size = strlen(sbots); 
        for(int j = 79-sbots_size; j > 0; j--){
                printf(" ");
        }
        printf("%s║\n", BOLD_CYAN);
        printf("                     ║                                                                                            ║\n");
        printf("                     ║        %sOrganization: %s%d", BOLD_BRIGHT_MAGENTA, RESET, org);
        char sorg[buffer_size];
        sprintf(sorg, "%d", org);
        int sorg_size = strlen(sorg); 
        for(int j = 70-sorg_size; j > 0; j--){
                printf(" ");
        }
        printf("%s║\n", BOLD_CYAN);
        printf("                     ║                                                                                            ║\n");
        printf("                     ║        %sUser: %s%d", BOLD_BRIGHT_MAGENTA, RESET, user);
        char suser[buffer_size];
        sprintf(suser, "%d", user);
        int suser_size = strlen(suser); 
        for(int j = 78-suser_size; j > 0; j--){
                printf(" ");
        }
        printf("%s║\n", BOLD_CYAN);
        for(int i = 0; i < 12; i++)
            printf("                     ║                                                                                            ║\n");
        int sec = time / 1000;
        float msec = time % 100;
        //printf("                     %s║%s   Loading Time: %s%d.%d", BOLD_CYAN, BOLD_GREEN, RESET, time/1000, time%100);
        printf("                     %s║%s   Query Time: %s%d.%d",BOLD_CYAN, BOLD_GREEN, RESET, sec, msec);
        char ssec[buffer_size];
        sprintf(ssec, "%d.%d", sec, msec);
        int ssec_size = strlen(ssec); 
        for(int j = 76-ssec_size; j > 0; j--){
            printf(" ");
        }
        printf("%s║\n", BOLD_CYAN);
        printf("                     ║                                                                                            ║\n");
        printf("                     ║                                                                                            ║\n");
        printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝");
        printQueriesBottom();
    }
    else {
        fprintf(outstream, "Bot: %d\n", bots);
        fprintf(outstream, "Organization: %d\n", org);
        fprintf(outstream, "User: %d", user);
    }
}

void queries_pares_output(FILE *outstream, int flag, float avg, int time) {
    
    if(outstream == NULL && flag == 2) {
        printQueriesTop();
        printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("                     ║                                                                                            ║\n");
        printf("                     ║   %sNúmero médio de colaboradores por repositório: %s%.2f%s                                      ║\n", BOLD_BRIGHT_MAGENTA, RESET, avg, BOLD_CYAN);
        for(int i = 0; i < 16; i++) 
            printf("                     ║                                                                                            ║\n");
        int sec = time / 1000;
        float msec = time % 100;
        //printf("                     %s║%s   Loading Time: %s%d.%d", BOLD_CYAN, BOLD_GREEN, RESET, time/1000, time%100);
        printf("                     %s║%s   Query Time: %s%d.%d",BOLD_CYAN, BOLD_GREEN, RESET, sec, msec);
        char ssec[buffer_size];
        sprintf(ssec, "%d.%d", sec, msec);
        int ssec_size = strlen(ssec); 
        for(int j = 75-ssec_size; j > 0; j--){
            printf(" ");
        }
        printf("%s║\n", BOLD_CYAN);
        printf("                     ║                                                                                            ║\n");
        printf("                     ║                                                                                            ║\n");
        printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝");
        printQueriesBottom();
    }
    else if(outstream == NULL && flag == 4){
        printQueriesTop();
        printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("                     ║                                                                                            ║\n");
        printf("                     ║   %sQuantidade média de commits por utilizador: %s%.2f%s                                         ║\n", BOLD_BRIGHT_MAGENTA, RESET, avg, BOLD_CYAN);
        for(int i = 0; i < 16; i++) 
            printf("                     ║                                                                                            ║\n");
        int sec = time / 1000;
        float msec = time % 100;
        //printf("                     %s║%s   Loading Time: %s%d.%d", BOLD_CYAN, BOLD_GREEN, RESET, time/1000, time%100);
        printf("                     %s║%s   Query Time: %s%d.%d",BOLD_CYAN, BOLD_GREEN, RESET, sec, msec);
        char ssec[buffer_size];
        sprintf(ssec, "%d.%d", sec, msec);
        int ssec_size = strlen(ssec); 
        for(int j = 75-ssec_size; j > 0; j--){
            printf(" ");
        }
        printf("%s║\n", BOLD_CYAN);
        printf("                     ║                                                                                            ║\n");
        printf("                     ║                                                                                            ║\n");
        printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝");
        printQueriesBottom();
    } else {
        fprintf(outstream, "%.2f\n", avg);
    }
}

void query3_output(FILE *outstream, int bots, int time) {

if(outstream == NULL) {
        printQueriesTop();
        puts(BOLD_CYAN);
        printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("                     ║                                                                                            ║\n");
        printf("                     ║  %sQuantidade de repositórios com bots: %s%d",BOLD_BRIGHT_MAGENTA, RESET, bots);
        char sbots[buffer_size];
        sprintf(sbots, "%d", bots);
        int sbots_size = strlen(sbots); 
        for(int j = 53-sbots_size; j > 0; j--){
                printf(" ");
        }
        printf("%s║\n", BOLD_CYAN);
        printf("                     ║                                                                                            ║\n");
        printf("                     ║                                                                                            ║\n");
        printf("                     ║                                                                                            ║\n");
        printf("                     ║                                                                                            ║\n");
        for(int i = 0; i < 12; i++)
            printf("                     ║                                                                                            ║\n");
        int sec = time / 1000;
        float msec = time % 100;
        //printf("                     %s║%s   Loading Time: %s%d.%d", BOLD_CYAN, BOLD_GREEN, RESET, time/1000, time%100);
        printf("                     %s║%s   Query Time: %s%d.%d",BOLD_CYAN, BOLD_GREEN, RESET, sec, msec);
        char ssec[buffer_size];
        sprintf(ssec, "%d.%d", sec, msec);
        int ssec_size = strlen(ssec); 
        for(int j = 76-ssec_size; j > 0; j--){
            printf(" ");
        }
        printf("%s║\n", BOLD_CYAN);
        printf("                     ║                                                                                            ║\n");
        printf("                     ║                                                                                            ║\n");
        printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝");
        printQueriesBottom();
    }
    else {
        fprintf(outstream, "%d\n", bots);
    }
}

int paginacao_output(FTABLE ftable, int page_number, int pg_total, int time) {
/*
    int resto = 0;
    int nmr_paginas = 1;
    resto = topN % 19;
    if(topN > 19) {
        nmr_paginas = topN / 19;
        if(resto != 0) nmr_paginas++;
    }
*/
    if(ftable == NULL) return -1;
    char* filename = get_ftable_data(ftable);
    FILE * leitura = fopen(filename,"r");
    paginacaoTop();
    char buffer[buffer_size];

    int sec = time / 1000;
    float msec = time % 100;
    printf("                     %s   Query Time: %s%d.%d",BOLD_GREEN, RESET, sec, msec);

    //FILE *input_file = fopen(input_file_name, "r");
    puts(BOLD_CYAN);
    printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("                     ║                                                                                            ║\n");
    for(int i = 0; i < 19 && fgets(buffer, buffer_size, leitura); i++){
        /*if(fgets(buffer, buffer_size, leitura) == NULL) {
            system("clear");
            return -1;
            }*/
        char *buffer2;
        buffer2 = strtok(buffer, "\n");
        printf("                     ║ %s %s %s",RESET, buffer2, BOLD_CYAN);
        int tamanho = strlen(buffer2); 
        for(int j = 89-tamanho; j > 0; j--){
            printf(" ");
        }
        printf("║\n");
    }

    printf("                     ║ Page:%d/%d", page_number,pg_total);
    char page[buffer_size];
    sprintf(page, " Page:%d/%d", page_number,pg_total);
    int page_size = strlen(page); 
    for(int j = 92-page_size; j > 0; j--){
            printf(" ");
    }
    printf("║\n");
    printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝");
    puts(BOLD_CYAN);
    printPaginacaoBottom();
    puts(RESET);
    fclose(leitura);
    return 0;
}

void building(){
    /*
░█▀█░█▀█░▀█▀░░░▀█▀░█▄█░█▀█░█░░░█▀▀░█▄█░█▀▀░█▀█░▀█▀░█▀▀░█▀▄
░█░█░█░█░░█░░░░░█░░█░█░█▀▀░█░░░█▀▀░█░█░█▀▀░█░█░░█░░█▀▀░█░█
░▀░▀░▀▀▀░░▀░░░░▀▀▀░▀░▀░▀░░░▀▀▀░▀▀▀░▀░▀░▀▀▀░▀░▀░░▀░░▀▀▀░▀▀░
*/
        printQueriesTop();
        puts(BOLD_CYAN);
        printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
               for(int i = 0; i < 8; i++)
            printf("                     ║                                                                                            ║\n");
       
        printf("                     ║  %s           ░█▀█░█▀█░▀█▀░░░▀█▀░█▄█░█▀█░█░░░█▀▀░█▄█░█▀▀░█▀█░▀█▀░█▀▀░█▀▄%s                     ║\n", BOLD_BRIGHT_MAGENTA, BOLD_CYAN);
        printf("                     ║  %s           ░█░█░█░█░░█░░░░░█░░█░█░█▀▀░█░░░█▀▀░█░█░█▀▀░█░█░░█░░█▀▀░█░█%s                     ║\n", BOLD_BRIGHT_MAGENTA, BOLD_CYAN);
        printf("                     ║  %s           ░▀░▀░▀▀▀░░▀░░░░▀▀▀░▀░▀░▀░░░▀▀▀░▀▀▀░▀░▀░▀▀▀░▀░▀░░▀░░▀▀▀░▀▀░%s                     ║\n", BOLD_BRIGHT_MAGENTA, BOLD_CYAN);
        printf("                     ║                                                                                            ║\n");
        printf("                     ║                                                                                            ║\n");
        for(int i = 0; i < 8; i++)
            printf("                     ║                                                                                            ║\n");
        printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝");
        printQueriesBottom();
}