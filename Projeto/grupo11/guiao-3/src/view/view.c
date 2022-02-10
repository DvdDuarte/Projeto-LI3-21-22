/**
 * @file view.h
 * @author grupo11
 * @brief Ficheiro que contém as funções para apresentar as diferentes partes da interface
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../../include/view/view.h"

void printFrameTop(){
    system("clear");
    printf("  \n");
    puts(BOLD_CYAN);
    printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("                     ║%s                                                                      %s                      ║\n", BOLD_MAGENTA, BOLD_CYAN);
    printf("                     ║%s                                 ███████  ██████  ██████              %s                      ║\n", BOLD_MAGENTA, BOLD_CYAN);
    printf("                     ║%s                                 ██      ██       ██   ██             %s                      ║\n", BOLD_MAGENTA, BOLD_CYAN);
    printf("                     ║%s                                 ███████ ██   ███ ██████              %s                      ║\n", BOLD_MAGENTA, BOLD_CYAN);
    printf("                     ║%s                                      ██ ██    ██ ██   ██             %s                      ║\n", BOLD_MAGENTA, BOLD_CYAN);
    printf("                     ║%s                                 ███████  ██████  ██   ██             %s                      ║\n", BOLD_MAGENTA, BOLD_CYAN);
    printf("                     ║%s                                                                      %s                      ║\n", BOLD_MAGENTA, BOLD_CYAN);
    printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝");
    puts(BOLD_CYAN);
}
                         
void printFrameBottom(){
   puts(BOLD_CYAN);
   printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
   printf("                     ║                                                                                            ║\n");
   printf("                     ║                                                                                            ║\n");
   printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝");
   puts(RESET);
}

void printLoadingUsers(){
    int i,j,k;
    int rows = 10;
    int loadTime  = 5000;
    for(i = 0; i < 51; i++){
        system("clear");
        system("clear");
        printFrameTop();
        printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("                     %s║%s   ( 1/3) loading Users          [", BOLD_CYAN, RESET);
        for(j = 0; j < i; j++)
            printf("#");
        while(j < 20){
            printf("-");
            j++;
        }
        printf("] %i",i*2);
        if(i < 5) printf(" ");
        printf("%%  %s║\n", BOLD_CYAN);
        printf(BOLD_CYAN);
        for(k = 0; k < rows; k++){
            printf("                     ║                                                                                            ║\n");
        }
        printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝\n");
        printFrameBottom();
        usleep(loadTime);
    }
}

void printLoadingCommits(){
    int i,j,k;
    int rows = 9;
    int loadTime  = 5000;
    for(i = 0; i < 51; i++){
        system("clear");
        system("clear");
        printFrameTop();
        printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("                     %s║%s   ( 1/3) loading Users          [##################################################] 100", BOLD_CYAN, RESET);
        printf("%%  %s║\n", BOLD_CYAN);
        printf("                     %s║%s   ( 2/3) loading commits        [", BOLD_CYAN, RESET);
        for(j = 0; j < i; j++)
            printf("#");
        while(j < 20){
            printf("-");
            j++;
        }
        printf("] %i",i*2);
        if(i < 5) printf(" ");
        printf("%%  %s║\n", BOLD_CYAN);
        printf(BOLD_CYAN);
        for(k = 0; k < rows; k++){
            printf("                     ║                                                                                            ║\n");
        }
        printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝\n");
        printFrameBottom();
        usleep(loadTime);
    }
}

void printLoadingRepos(){
    int i,j,k;
    int rows = 8;
    int loadTime  = 5000;
    for(i = 0; i < 51; i++){
        system("clear");
        system("clear");
        system("clear");
        printFrameTop();
        printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("                     %s║%s    ( 1/3) loading Users          [##################################################] 100", BOLD_CYAN, RESET);
        printf("%% %s║\n", BOLD_CYAN);
        printf("                     %s║%s    ( 2/3) loading commits        [##################################################] 100", BOLD_CYAN, RESET);
        printf("%% %s║\n",BOLD_CYAN);
        printf("                     %s║%s    ( 3/3) loading Repos          [", BOLD_CYAN, RESET);
        for(j = 0; j < i; j++)
            printf("#");
        while(j < 20){
            printf("-");
            j++;
        }
        printf("] %i",i*2);
        if(i < 5) printf(" ");
        printf("%% %s║\n", BOLD_CYAN);
        printf(BOLD_CYAN);
        for(k = 0; k < rows; k++){
            printf("                     ║                                                                                            ║\n");
        }
        printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝\n");
        printFrameBottom();
        usleep(loadTime);
    }
}

void printBuildingApp(){
    int i,j,k;
    int rows = 7;
    int loadTime  = 5000;
    for(i = 0; i < 21; i++){
        system("clear");
        system("clear");
        system("clear");
        system("clear");
        printFrameTop();
        printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("                     ║                                                                                            ║\n");
        printf("                     %s║%s    ( 1/3) loading Users          [##################################################] 100", BOLD_CYAN, RESET);
        printf("%% %s║\n", BOLD_CYAN);
        printf("                     %s║%s    ( 2/3) loading commits        [##################################################] 100", BOLD_CYAN, RESET);
        printf("%% %s║\n",BOLD_CYAN);
        printf("                     %s║%s    ( 3/3) loading Repos          [##################################################] 100", BOLD_CYAN, RESET);
        printf("%% %s║\n", BOLD_CYAN);
        printf("                     ║                                                                                            ║\n");

        printf("                     %s║%s    \033[5mBuilding App...\033[0m                                                                         %s║\n", BOLD_CYAN, RESET, BOLD_CYAN);
        printf(BOLD_CYAN);
        for(k = 0; k < rows; k++){
            printf("                     ║                                                                                            ║\n");
        }
        printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝\n");
        printFrameBottom();
        usleep(loadTime);
    }
}

void printBuildingAppTime(int time){
    int i,j,k;
    int rows = 6;
    int loadTime  = 5000;
    for(i = 0; i < 21; i++){
        system("clear");
        system("clear");
        system("clear");
        system("clear");
        printFrameTop();
        printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("                     ║                                                                                            ║\n");
        printf("                     %s║%s    ( 1/3) loading Users          [##################################################] 100", BOLD_CYAN, RESET);
        printf("%% %s║\n", BOLD_CYAN);
        printf("                     %s║%s    ( 2/3) loading commits        [##################################################] 100", BOLD_CYAN, RESET);
        printf("%% %s║\n",BOLD_CYAN);
        printf("                     %s║%s    ( 3/3) loading Repos          [##################################################] 100", BOLD_CYAN, RESET);
        printf("%% %s║\n", BOLD_CYAN);
        printf("                     ║                                                                                            ║\n");
                                            
        printf("                     %s║%s    Build Finished ...                                                                      %s║\n", BOLD_CYAN, RESET, BOLD_CYAN);
        printf(BOLD_CYAN);
        for(k = 0; k < rows; k++){
            if (k != 4)
                printf("                     ║                                                                                            ║\n");
                else {
                    int sec = time / 1000;
                    float msec = time % 100;
                    //printf("                     %s║%s   Loading Time: %s%d.%d", BOLD_CYAN, BOLD_GREEN, RESET, time/1000, time%100);
                    printf("                     %s║%s   Loading Time: %s%d.%d",BOLD_CYAN, BOLD_GREEN, RESET, sec, msec);
                    char ssec[buffer_size];
                    sprintf(ssec, "%d.%d", sec, msec);
                    int ssec_size = strlen(ssec); 
                    for(int j = 75-ssec_size; j > 0; j--){
                        printf(" ");
                    }
                    printf("%s║\n", BOLD_CYAN);
                }
        }
        printf("                     ║                                 %s\033[5mPress Enter to Continue\033[0m                                    %s║\n", BOLD_BRIGHT_MAGENTA, BOLD_CYAN);
        printf("                     ║                                                                                            ║\n");
        printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝\n");
        printFrameBottom();
        usleep(loadTime);
    }
}

/*
void printLoadingDefaultFiles() {
 ██╗
███║
╚██║
 ██║
 ██║
 ╚═╝
    printFrameTop();
    puts(BOLD_CYAN);
    printf("           ╔════════════════════════════════════════════════════════╗\n");
    printf("           ║%s                           ██╗                   %s       ║\n", BOLD_BRIGHT_MAGENTA, BOLD_CYAN);
    printf("           ║%s                          ███║                     %s     ║\n", BOLD_BRIGHT_MAGENTA, BOLD_CYAN);
    printf("           ║%s                          ╚██║                     %s     ║\n", BOLD_BRIGHT_MAGENTA, BOLD_CYAN);
    printf("           ║%s                           ██║                  %s        ║\n", BOLD_BRIGHT_MAGENTA, BOLD_CYAN);
    printf("           ║%s                           ██║                 %s         ║\n", BOLD_BRIGHT_MAGENTA, BOLD_CYAN);
    printf("           ║%s                         ███████                 %s       ║\n", BOLD_BRIGHT_MAGENTA, BOLD_CYAN);
    printf("           ╚════════════════════════════════════════════════════════╝");
    puts(BOLD_CYAN);
    printFrameBottom();

}
*/

void printDefaultScreen() {

/*
░█░░░█▀█░█▀█░█▀▄░░░█▀▀░▀█▀░█░░░█▀▀░█▀▀
░█░░░█░█░█▀█░█░█░░░█▀▀░░█░░█░░░█▀▀░▀▀█
░▀▀▀░▀▀▀░▀░▀░▀▀░░░░▀░░░▀▀▀░▀▀▀░▀▀▀░▀▀▀
*/
    printFrameTop();
    puts(BOLD_CYAN);
    printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("                     ║                                                                                            ║\n");
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s                            ░█░░░█▀█░█▀█░█▀▄░░░█▀▀░▀█▀░█░░░█▀▀░█▀▀   %s                       ║\n", BOLD_BRIGHT_MAGENTA, BOLD_CYAN);
    printf("                     ║%s                            ░█░░░█░█░█▀█░█░█░░░█▀▀░░█░░█░░░█▀▀░▀▀█   %s                       ║\n", BOLD_BRIGHT_MAGENTA, BOLD_CYAN);
    printf("                     ║%s                            ░▀▀▀░▀▀▀░▀░▀░▀▀░░░░▀░░░▀▀▀░▀▀▀░▀▀▀░▀▀▀   %s                       ║\n", BOLD_BRIGHT_MAGENTA, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║                                                                                            ║\n");
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s                                    Press Enter to Continue          %s                       ║\n", BOLD_BRIGHT_MAGENTA, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    puts(BOLD_CYAN);
    printFrameBottom();
}

void printQueriesTop() {
    /*
 ██████╗ ██╗   ██╗███████╗██████╗ ██╗███████╗███████╗
██╔═══██╗██║   ██║██╔════╝██╔══██╗██║██╔════╝██╔════╝
██║   ██║██║   ██║█████╗  ██████╔╝██║█████╗  ███████╗
██║▄▄ ██║██║   ██║██╔══╝  ██╔══██╗██║██╔══╝  ╚════██║
╚██████╔╝╚██████╔╝███████╗██║  ██║██║███████╗███████║
 ╚══▀▀═╝  ╚═════╝ ╚══════╝╚═╝  ╚═╝╚═╝╚══════╝╚══════╝
                                                     */
    system("clear");
    puts(BOLD_CYAN);
    printf("  \n");
    printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s                      ██████╗ ██╗   ██╗███████╗██████╗ ██╗███████╗███████╗%s                  ║\n", BOLD_MAGENTA, BOLD_CYAN);
    printf("                     ║%s                     ██╔═══██╗██║   ██║██╔════╝██╔══██╗██║██╔════╝██╔════╝%s                  ║\n", BOLD_MAGENTA, BOLD_CYAN);
    printf("                     ║%s                     ██║   ██║██║   ██║█████╗  ██████╔╝██║█████╗  ███████╗%s                  ║\n", BOLD_MAGENTA, BOLD_CYAN);
    printf("                     ║%s                     ██║▄▄ ██║██║   ██║██╔══╝  ██╔══██╗██║██╔══╝  ╚════██║%s                  ║\n", BOLD_MAGENTA, BOLD_CYAN);
    printf("                     ║%s                     ╚██████╔╝╚██████╔╝███████╗██║  ██║██║███████╗███████║%s                  ║\n", BOLD_MAGENTA, BOLD_CYAN);
    printf("                     ║%s                      ╚══▀▀═╝  ╚═════╝ ╚══════╝╚═╝  ╚═╝╚═╝╚══════╝╚══════╝%s                  ║\n", BOLD_MAGENTA, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝");
    puts(BOLD_CYAN);

}

void printQueriesScreen() {
    puts(BOLD_CYAN);
    printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    1: Quantidade dos tipos de Utilizadores  %s                                               ║\n", BOLD_BRIGHT_MAGENTA, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    2: Número médio de colaboradores por repositório  %s                                      ║\n", BOLD_BRIGHT_MAGENTA, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    3: Quantidade de Repositórios com bots     %s                                             ║\n", BOLD_BRIGHT_MAGENTA, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    4: Quantidade média de Commits por Utilizador %s                                          ║\n", BOLD_BRIGHT_MAGENTA, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    5: Top Utilizadores com mais Commits num Intervalo de tempo  %s                           ║\n", BOLD_BRIGHT_MAGENTA, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    6: Top Utilizadores com mais Commits numa linguagem  %s                                   ║\n", BOLD_BRIGHT_MAGENTA, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    7: Repositórios inativos a partir de uma determinada data  %s                             ║\n", BOLD_BRIGHT_MAGENTA, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    8: Top linguagens mais utilizadas a partir de uma determinada data  %s                    ║\n", BOLD_BRIGHT_MAGENTA, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    9: Top Utilizadores com commits em repositórios cujo o owner seja um amigo seu  %s        ║\n", BOLD_BRIGHT_MAGENTA, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s   10: Top Utilizadores com maiores mensagens de commit por repositório  %s                   ║\n", BOLD_BRIGHT_MAGENTA, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝");
    puts(BOLD_CYAN);

}

void printQueriesScreen1() {
    puts(BOLD_CYAN);
    printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    > %s\033[5m1: Quantidade dos tipos de Utilizadores%s <\033[0m  %s                                           ║\n", RESET, BUI_BRIGHT_MAGENTA, RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    2: Número médio de colaboradores por repositório  %s                                      ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    3: Quantidade de Repositórios com bots     %s                                             ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    4: Quantidade média de Commits por Utilizador %s                                          ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    5: Top Utilizadores com mais Commits num Intervalo de tempo  %s                           ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    6: Top Utilizadores com mais Commits numa linguagem  %s                                   ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    7: Repositórios inativos a partir de uma determinada data  %s                             ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    8: Top linguagens mais utilizadas a partir de uma determinada data  %s                    ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    9: Top Utilizadores com commits em repositórios cujo o owner seja um amigo seu  %s        ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s   10: Top Utilizadores com maiores mensagens de commit por repositório  %s                   ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝");
    puts(BOLD_CYAN);

}

void printQueriesScreen2() {
    puts(BOLD_CYAN);
    printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    1: Quantidade dos tipos de Utilizadores  %s                                               ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s  > \033[5m%s2: Número médio de colaboradores por repositório%s <\033[0m  %s                                    ║\n", RESET, BUI_BRIGHT_MAGENTA, RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    3: Quantidade de Repositórios com bots     %s                                             ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    4: Quantidade média de Commits por Utilizador %s                                          ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    5: Top Utilizadores com mais Commits num Intervalo de tempo  %s                           ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    6: Top Utilizadores com mais Commits numa linguagem  %s                                   ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    7: Repositórios inativos a partir de uma determinada data  %s                             ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    8: Top linguagens mais utilizadas a partir de uma determinada data  %s                    ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    9: Top Utilizadores com commits em repositórios cujo o owner seja um amigo seu  %s        ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s   10: Top Utilizadores com maiores mensagens de commit por repositório  %s                   ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝");
    puts(BOLD_CYAN);

}

void printQueriesScreen3() {
    puts(BOLD_CYAN);
    printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    1: Quantidade dos tipos de Utilizadores  %s                                               ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    2: Número médio de colaboradores por repositório  %s                                      ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s  > %s\033[5m3: Quantidade de Repositórios com bots%s <\033[0m  %s                                              ║\n", RESET, BUI_BRIGHT_MAGENTA, RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    4: Quantidade média de Commits por Utilizador %s                                          ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    5: Top Utilizadores com mais Commits num Intervalo de tempo  %s                           ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    6: Top Utilizadores com mais Commits numa linguagem  %s                                   ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    7: Repositórios inativos a partir de uma determinada data  %s                             ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    8: Top linguagens mais utilizadas a partir de uma determinada data  %s                    ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    9: Top Utilizadores com commits em repositórios cujo o owner seja um amigo seu  %s        ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s   10: Top Utilizadores com maiores mensagens de commit por repositório  %s                   ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝");
    puts(BOLD_CYAN);

}

void printQueriesScreen4() {
    puts(BOLD_CYAN);
    printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    1: Quantidade dos tipos de Utilizadores  %s                                               ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    2: Número médio de colaboradores por repositório  %s                                      ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    3: Quantidade de Repositórios com bots     %s                                             ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s  > %s\033[5m4: Quantidade média de Commits por Utilizador%s <\033[0m  %s                                       ║\n", RESET, BUI_BRIGHT_MAGENTA, RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    5: Top Utilizadores com mais Commits num Intervalo de tempo  %s                           ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    6: Top Utilizadores com mais Commits numa linguagem  %s                                   ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    7: Repositórios inativos a partir de uma determinada data  %s                             ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    8: Top linguagens mais utilizadas a partir de uma determinada data  %s                    ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    9: Top Utilizadores com commits em repositórios cujo o owner seja um amigo seu  %s        ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s   10: Top Utilizadores com maiores mensagens de commit por repositório  %s                   ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝");
    puts(BOLD_CYAN);

}

void printQueriesScreen5() {
    puts(BOLD_CYAN);
    printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    1: Quantidade dos tipos de Utilizadores  %s                                               ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    2: Número médio de colaboradores por repositório  %s                                      ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    3: Quantidade de Repositórios com bots     %s                                             ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    4: Quantidade média de Commits por Utilizador %s                                          ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s  > %s\033[5m5: Top Utilizadores com mais Commits num Intervalo de tempo%s <\033[0m  %s                         ║\n", RESET, BUI_BRIGHT_MAGENTA, RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    6: Top Utilizadores com mais Commits numa linguagem  %s                                   ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    7: Repositórios inativos a partir de uma determinada data  %s                             ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    8: Top linguagens mais utilizadas a partir de uma determinada data  %s                    ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    9: Top Utilizadores com commits em repositórios cujo o owner seja um amigo seu  %s        ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s   10: Top Utilizadores com maiores mensagens de commit por repositório  %s                   ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝");
    puts(BOLD_CYAN);

}

void printQueriesScreen6() {
    puts(BOLD_CYAN);
    printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    1: Quantidade dos tipos de Utilizadores  %s                                               ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    2: Número médio de colaboradores por repositório  %s                                      ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    3: Quantidade de Repositórios com bots     %s                                             ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    4: Quantidade média de Commits por Utilizador %s                                          ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    5: Top Utilizadores com mais Commits num Intervalo de tempo  %s                           ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s  > %s\033[5m6: Top Utilizadores com mais Commits numa linguagem%s <\033[0m  %s                                 ║\n", RESET, BUI_BRIGHT_MAGENTA, RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    7: Repositórios inativos a partir de uma determinada data  %s                             ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    8: Top linguagens mais utilizadas a partir de uma determinada data  %s                    ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    9: Top Utilizadores com commits em repositórios cujo o owner seja um amigo seu  %s        ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s   10: Top Utilizadores com maiores mensagens de commit por repositório  %s                   ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝");
    puts(BOLD_CYAN);

}

void printQueriesScreen7() {
    puts(BOLD_CYAN);
    printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    1: Quantidade dos tipos de Utilizadores  %s                                               ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    2: Número médio de colaboradores por repositório  %s                                      ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    3: Quantidade de Repositórios com bots     %s                                             ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    4: Quantidade média de Commits por Utilizador %s                                          ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    5: Top Utilizadores com mais Commits num Intervalo de tempo  %s                           ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    6: Top Utilizadores com mais Commits numa linguagem  %s                                   ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s  > %s\033[5m7: Repositórios inativos a partir de uma determinada data%s <\033[0m  %s                           ║\n", RESET, BUI_BRIGHT_MAGENTA, RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    8: Top linguagens mais utilizadas a partir de uma determinada data  %s                    ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    9: Top Utilizadores com commits em repositórios cujo o owner seja um amigo seu  %s        ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s   10: Top Utilizadores com maiores mensagens de commit por repositório  %s                   ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝");
    puts(BOLD_CYAN);

}

void printQueriesScreen8() {
    puts(BOLD_CYAN);
    printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    1: Quantidade dos tipos de Utilizadores  %s                                               ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    2: Número médio de colaboradores por repositório  %s                                      ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    3: Quantidade de Repositórios com bots     %s                                             ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    4: Quantidade média de Commits por Utilizador %s                                          ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    5: Top Utilizadores com mais Commits num Intervalo de tempo  %s                           ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    6: Top Utilizadores com mais Commits numa linguagem  %s                                   ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    7: Repositórios inativos a partir de uma determinada data  %s                             ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s  > %s\033[5m8: Top linguagens mais utilizadas a partir de uma determinada data%s <\033[0m  %s                  ║\n", RESET, BUI_BRIGHT_MAGENTA, RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    9: Top Utilizadores com commits em repositórios cujo o owner seja um amigo seu  %s        ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s   10: Top Utilizadores com maiores mensagens de commit por repositório  %s                   ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝");
    puts(BOLD_CYAN);

}

void printQueriesScreen9() {
    puts(BOLD_CYAN);
    printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    1: Quantidade dos tipos de Utilizadores  %s                                               ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    2: Número médio de colaboradores por repositório  %s                                      ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    3: Quantidade de Repositórios com bots     %s                                             ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    4: Quantidade média de Commits por Utilizador %s                                          ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    5: Top Utilizadores com mais Commits num Intervalo de tempo  %s                           ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    6: Top Utilizadores com mais Commits numa linguagem  %s                                   ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    7: Repositórios inativos a partir de uma determinada data  %s                             ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    8: Top linguagens mais utilizadas a partir de uma determinada data  %s                    ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s  > %s\033[5m9: Top Utilizadores com commits em repositórios cujo o owner seja um amigo seu%s <\033[0m  %s      ║\n", RESET, BUI_BRIGHT_MAGENTA, RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s   10: Top Utilizadores com maiores mensagens de commit por repositório  %s                   ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝");
    puts(BOLD_CYAN);

}

void printQueriesScreen10() {
    puts(BOLD_CYAN);
    printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    1: Quantidade dos tipos de Utilizadores  %s                                               ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    2: Número médio de colaboradores por repositório  %s                                      ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    3: Quantidade de Repositórios com bots     %s                                             ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    4: Quantidade média de Commits por Utilizador %s                                          ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    5: Top Utilizadores com mais Commits num Intervalo de tempo  %s                           ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    6: Top Utilizadores com mais Commits numa linguagem  %s                                   ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    7: Repositórios inativos a partir de uma determinada data  %s                             ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    8: Top linguagens mais utilizadas a partir de uma determinada data  %s                    ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s    9: Top Utilizadores com commits em repositórios cujo o owner seja um amigo seu  %s        ║\n", RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s > %s\033[5m10: Top Utilizadores com maiores mensagens de commit por repositório%s <\033[0m  %s                 ║\n", RESET, BUI_BRIGHT_MAGENTA, RESET, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝");
    puts(BOLD_CYAN);

}

int printQueriesBottom() {
   int query;
   puts(BOLD_CYAN);
   printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
   printf("                     ║                                                                                            ║\n");
   /*printf("                     ║      Insira Aqui o número da Query:                                                        ║\n");
   scanf("%d", &query);*/
   // Tentar imprimir a parte de baixo ao mesmo tempo, no entanto fica a espera do input
   printf("                     ║                 %s(UP ARROW) & (DOWN ARROW) : To go to desired query%s%s                         ║\n", BI_BRIGHT_MAGENTA, RESET, BOLD_CYAN);

   printf("                     ║                          %s(TAB) : Quit APP | (BACKSPACE) : Menu%s%s                             ║\n", BI_BRIGHT_MAGENTA, RESET, BOLD_CYAN);
   printf("                     ║                                                                                            ║\n");
   printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝");
   
   puts(RESET);

   return query;
}

void printQueries(int q){
    int query;
    printQueriesTop();
    //printQueriesScreen();
    switch(q){
        case(0):
            printQueriesScreen1();
            break;
        case(1):
            printQueriesScreen1();
            break;
        case(2):
            printQueriesScreen2();
            break;
        case(3):
            printQueriesScreen3();
            break;
        case(4):
            printQueriesScreen4();
            break;
        case(5):
            printQueriesScreen5();
            break;    
        case(6):
            printQueriesScreen6();
            break;
        case(7):
            printQueriesScreen7();
            break;
        case(8):
            printQueriesScreen8();
            break;
        case(9):
            printQueriesScreen9();
            break;
        case(10):
            printQueriesScreen10();
            break;
    }
    

    query = printQueriesBottom();
}

void printLoadingUI(){
    printLoadingUsers();
    printLoadingCommits();
    printLoadingRepos();
    printBuildingApp();
}

void printPaginacaoBottom(){
   puts(BOLD_CYAN);
   printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
   printf("                     ║                                                                                            ║\n");
   /*printf("                     ║      Insira Aqui o número da Query:                                                        ║\n");
   scanf("%d", &query);*/
   // Tentar imprimir a parte de baixo ao mesmo tempo, no entanto fica a espera do input
   printf("                     ║            %s< (LEFT ARROW) : Previous Page | (RIGHT ARROW) : Next Page >%s%s                    ║\n", BI_BRIGHT_MAGENTA, RESET, BOLD_CYAN);

   printf("                     ║                         %s(i) : Choose Page | (BACKSPACE) : Menu%s%s                             ║\n", BI_BRIGHT_MAGENTA, RESET, BOLD_CYAN);
   printf("                     ║                         %s            (TAB) : Quit APP%s%s                                       ║\n", BI_BRIGHT_MAGENTA, RESET, BOLD_CYAN);
   printf("                     ║                                                                                            ║\n");
   printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝");
   
   puts(RESET);

}

void paginacaoTop() {
/*
░█▀█░█▀█░█▀▀░▀█▀░█▀█░█▀█░▀█▀░▀█▀░█▀█░█▀█
░█▀▀░█▀█░█░█░░█░░█░█░█▀█░░█░░░█░░█░█░█░█
░▀░░░▀░▀░▀▀▀░▀▀▀░▀░▀░▀░▀░░▀░░▀▀▀░▀▀▀░▀░▀
*/
        system("clear");
    puts(BOLD_CYAN);
    printf("  \n");
    printf("                     ╔════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("                     ║                                                                                            ║\n");
    printf("                     ║%s                          ░█▀█░█▀█░█▀▀░▀█▀░█▀█░█▀█░▀█▀░▀█▀░█▀█░█▀█%s                          ║\n", BOLD_MAGENTA, BOLD_CYAN);
    printf("                     ║%s                          ░█▀▀░█▀█░█░█░░█░░█░█░█▀█░░█░░░█░░█░█░█░█%s                          ║\n", BOLD_MAGENTA, BOLD_CYAN);
    printf("                     ║%s                          ░▀░░░▀░▀░▀▀▀░▀▀▀░▀░▀░▀░▀░░▀░░▀▀▀░▀▀▀░▀░▀%s                          ║\n", BOLD_MAGENTA, BOLD_CYAN);
    printf("                     ║                                                                                            ║\n");
    printf("                     ╚════════════════════════════════════════════════════════════════════════════════════════════╝");
    puts(BOLD_CYAN);

}