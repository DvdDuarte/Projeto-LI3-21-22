/**
 * @file table.c
 * @author grupo11
 * @brief Ficheiro que contém as funções para trabalhar com FTABLE
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../../include/model/table.h"

struct file_node{
    char *data;
    struct file_node *next; // Pointer to next node in DLL
    struct file_node *prev; // Pointer to previous node in DLL
};

FTABLE init_ftable(FILE *new_data){
    FTABLE ftable = malloc(sizeof(struct file_node));
    ftable->data = new_data;
    ftable->prev = NULL;
    ftable->next = NULL;
}

FTABLE fill_ftable(FTABLE ftable, int topN){
    
    int resto = 0;
    int nmr_pagina = 1;
    
    if(topN > 19) {
        resto = topN % 19;
        nmr_pagina = topN / 19;
        if(resto != 0) nmr_pagina++;
    }
    
    for(int i = 1; i <= nmr_pagina; i++){
        char num[12];
        sprintf(num, "%d", i);
        char filename[50] = "saida/paginacao/";
        strcat(filename,num);
        strcat(filename,".txt");
        
        ftable = ftable_add_node(ftable, filename);
        //printf("Filled %d with name\n", i);
    }
    return ftable;
}

char * get_ftable_data(FTABLE ftable){
    if(ftable->data != NULL)
        return strdup(ftable->data);
    else return strdup(ftable->prev->data);
}

FTABLE get_ftable_next(FTABLE ftable){
    if(ftable->next != NULL)
        return ftable->next;
    else return ftable;
}

FTABLE get_ftable_prev(FTABLE ftable){
    if(ftable->prev != NULL)
        return ftable->prev;
    else return ftable;
}

FTABLE ftable_add_node(FTABLE ftable, char *new_data){

    FTABLE new_node = (FTABLE)malloc(sizeof(struct file_node));

    FTABLE last = ftable;


    new_node->data = strdup(new_data);


    new_node->next = NULL;


    if (ftable == NULL)
    {
        new_node->prev = NULL;
        ftable = new_node;
        return ftable;
    }


    while (last->next != NULL)
        last = last->next;

    last->next = new_node;

    new_node->prev = last;

    return ftable;
}


void free_table(FTABLE ftable){
    if(ftable != NULL) {
        free(ftable->data);
        free_table(ftable->next);
        free(ftable);
    }
}