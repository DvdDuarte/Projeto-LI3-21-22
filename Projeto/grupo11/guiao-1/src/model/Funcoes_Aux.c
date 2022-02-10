
#include "../../include/model/Funcoes_Aux.h"

int digitorChar(char* line){

    if(strcmp(line, "") == 0)
        return -1;
    for(int i = 0;line[i]; i++)
        if(!isdigit(line[i]))
            return -1;

    return atoi(line);

}
