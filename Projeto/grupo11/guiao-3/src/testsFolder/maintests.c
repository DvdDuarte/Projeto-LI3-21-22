/**
 * @file tests.h
 * @author grupo11
 * @brief Ficheiro que contém a função principal do executável de testes
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../../include/testsFolder/tests.h"
#include "../../include/model/queries/queries_estatisticas.h"
#include "../../include/model/queries/queries_parametrizaveis.h"
#include "../../include/model/sgr/sgr.h"


void test_query_1(int indice,SGR sgr){
    query1(indice,sgr);
}

void test_query_2(int indice, SGR sgr){
    query2(indice,sgr);
}

void test_query_3(int indice, SGR sgr){
    query3(indice,sgr);
}

void test_query_4(int indice, SGR sgr){
    query4(indice,sgr);
}

void test_query_5(int indice, int top, char * inicio, char *fim , SGR sgr){
    query5(indice,top,inicio,fim,sgr);
}


int main(){
    int nquery,topN;
    char datai[20],dataf[20];


    SGR sgr;
    sgr = init_sgr();

    fill_sgr(sgr, "users.csv", "commits.csv", "repos.csv");

    escreve();
 while(1){
     int check = 0;
     while( nquery < 0 || nquery > 10 || check != 1) {
        printf("Insira a query desejada:  ");
        check = scanf("%d",&nquery);
        if(check != 1) clean_stdin();
     }
    
    switch (nquery) {
	case 1:;
            clock_t start1 = clock();
            test_query_1(1,sgr);
            clock_t end1   = clock();
            double time1 =(((double)(end1-start1) / CLOCKS_PER_SEC));
            (time1>5.0) ? printf("A query 1 não executou em tempo útil. %.5f seconds\n", time1):printf("A query 1 executou em tempo útil. %.5f seconds\n", time1);
            compereQum("entrada/expected1_output.txt","saida/command1_output.txt");            
            break;
        case 2:;
            clock_t start2 = clock();
            test_query_2(2,sgr);
            clock_t end2   = clock();
            double time2 =(((double)(end2-start2) / CLOCKS_PER_SEC));
            (time2>5.0) ? printf("A query 2 não executou em tempo útil. %.5f seconds\n", time2):printf("A query 2 executou em tempo útil. %.5f seconds\n", time2);
            compere("entrada/expected2_output.txt","saida/command2_output.txt");
            break;
        case 3:;
            clock_t start3 = clock();
            test_query_3(3,sgr);
            clock_t end3   = clock();
            double time3 =(((double)(end3-start3) / CLOCKS_PER_SEC));
            (time3>5.0) ? printf("A query 3 não executou em tempo útil. %.5f seconds\n", time3):printf("A query 3 executou em tempo útil. %.5f seconds\n", time3);
            compere("entrada/expected3_output.txt","saida/command3_output.txt");
	    break;
        case 4:;
            clock_t start4 = clock();
            test_query_4(4,sgr);
            clock_t end4   = clock();
            double time4 =(((double)(end4-start4) / CLOCKS_PER_SEC));
            (time4>5.0) ? printf("A query 4 não executou em tempo útil. %.5f seconds\n", time4):printf("A query 4 executou em tempo útil. %.5f seconds\n", time4);
            compere("entrada/expected4_output.txt","saida/command4_output.txt");
            break;
        case 5:;
            printf("Insira o top N de utilizadores: \n");
            scanf("%d",&topN);
            printf("Insira a data inicial: \n");
            scanf("%s",datai);
            printf("Insira a data final: \n");
            scanf("%s",dataf);
            clock_t start5 = clock();
            test_query_5(5,topN,datai,dataf,sgr);
            clock_t end5   = clock();
            double time5 =(((double)(end5-start5) / CLOCKS_PER_SEC));
            (time5>5.0) ? printf("A query 5 não executou em tempo útil. %.5f seconds\n", time5):printf("A query 5 executou em tempo útil. %.5f seconds\n", time5);
            compere("entrada/expected5_output.txt","saida/command5_output.txt");
	    break;
        case 6:
            printf("Query Não Definida\n");
            break;
        case 7:
            printf("Query Não Definida\n");
            break;
        case 8:
            printf("Query Não Definida\n");
            break;
        case 9:
            printf("Query Não Definida\n");
            break;
        case 10:
            printf("Query Não Definida\n");
            break;
	case 0:
	    return 0;
  	}
  
 }
   
}
