/**
 * @file Funcoes_Aux.c
 * @author grupo11
 * @brief Ficheiro que contém as funções auxiliares
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../../include/model/Funcoes_Aux.h"

int digitorChar(char* line){

    if(strcmp(line, "") == 0)
        return -1;
    for(int i = 0;line[i]; i++)
        if(!isdigit(line[i]))
            return -1;

    return atoi(line);

}
