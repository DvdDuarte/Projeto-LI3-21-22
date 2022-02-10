/**
 * @file main.c
 * @author grupo11
 * @brief Ficheiro que contém a função principal do sistema de gestão de repositórios
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "../include/controller/controller.h"


int main(int argc, char *argv[]) {

    controller(argc, argv);

    return 0;

}

