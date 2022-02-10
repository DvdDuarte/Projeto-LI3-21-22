#ifndef _FILE_WORK_H_
#define _FILE_WORK_H_

#include "Catalogo_Commits/commits.h"
#include "Catalogo_User/users.h"
#include "Catalogo_Repos/repos.h"
#define buffer_size 1000000

/**
 *
 * @param file_name
 */
void ler_Ficheiro(char* file_name);

/**
 *
 * @return
 */
GHashTable *ler_file_user_ok();

/**
 *
 * @param filename
 * @return
 */
GHashTable * ler_file_aux_ok(char *filename);

/**
 *
 * @param table
 * @return
 */
GArray *ler_file_commits_ok(GHashTable *table);

/**
 *
 * @param users
 * @return
 */
GHashTable  *ler_file_repos_ok(GHashTable *users);

#endif //_FILE_WORK_H_
