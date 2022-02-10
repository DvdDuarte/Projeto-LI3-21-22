/**
 * @file ghash_func_gerais.c
 * @author grupo11
 * @brief Ficheiro que contém as funções para trabalhar com *GHashTable
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../../include/model/ghash_func_gerais.h"

int GContainsKey (int key, GHashTable *hash) {
    //if(g_hash_table_lookup(hash,&key) != NULL)
    if(g_hash_table_contains(hash,&key))
        return 1;
    return 0;
}

int GRemove (GHashTable *hash, int key) {
    if(g_hash_table_remove(hash, &key)) return 1;
    else return 0;
}

GArray *GHGetArray(int key, GHashTable *hashTable){
    GArray *gArray;
    gArray = g_hash_table_lookup(hashTable, &key);
    return gArray;
}

void GHAddGArray (GArray *gArray, int key, GHashTable *hashTable) {
    g_hash_table_replace(hashTable, &key, gArray);
}

void GHashTable_free(GHashTable *hash) {
    g_hash_table_destroy(hash);
}