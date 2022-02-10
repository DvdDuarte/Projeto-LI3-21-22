/**
 * @file catalogs_file_work.h
 * @author grupo11
 * @brief Ficheiro que contém as funções que para trabalhar com os ficheiros para preencher os catalogos
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef GRUPO11_FILE_WORK_H
#define GRUPO11_FILE_WORK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glib-2.0/glib.h"
#include "../Catalogo_User/catalogo_users.h"
#include "../Catalogo_Commits/catalogo_commits.h"
#include "../Catalogo_Repos/catalogo_repos.h"
#include "file_work_aux.h"

#define buffer_size 1000000

//THash *HashOcor_commits(CUSER catalogo_users,CCOMMITS catalogo_commits, LCalendario data1 , LCalendario data2);


/**
 * Função que lê o ficheiro com os dados dos users e armazena num Catálogo de users
 * @param filepath O caminho e o nome do ficheiro a ler dos users
 * @return O catálogo de users que contém a informação necessária pra ser usada nas queries
 */
CUSER ler_file_user(CUSER catalogo_user, char *filepath);

/**
 * Função que lê o ficheiro com os dados dos commits e armazena num Catálogo de commits
 * @param catalogo_users O catálogo de users que vai ser utilizado pra realizar validações
 * @param filepath O caminho e o nome do ficheiro a ler dos commits
 * @param catalogo_commits O catálogo de commits onde vai ser armazenada a informção do ficheiro lido
 * @return O catálogo de commits que contém a informação necessária pra ser usada nas queries
 */
CCOMMITS ler_file_commits(CUSER catalogo_users, CCOMMITS catalogo_commits, char *filepath);

/**
 * Função que lê o ficheiro com os dados dos repos e armazena num Catálogo de repos
 * @param catalogo_users O catálogo de users que vai ser utilizado pra realizar validações
 * @param catalogo_commits O catálogo de commits que vai ser utilizado pra realizar validações
 * @param catalogo_repos O catálogo de repos onde vai ser armazenada a informção do ficheiro lido
 * @param filepath O caminho e o nome do ficheiro a ler dos repos
 * @return O catálogo de repos que contém a informação necessária pra ser usada nas queries
 */
CREPOS  ler_file_repos(CUSER catalogo_users, CCOMMITS catalogo_commits, CREPOS catalogo_repos, char *filepath);

#endif //GRUPO11_FILE_WORK_H
