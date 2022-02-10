/**
 * @file ghash_func_gerais.h
 * @author grupo11
 * @brief Ficheiro que contém as funções para trabalhar com *GHashTable
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _GHASH_FUNC_GERAIS_H_
#define _GHASH_FUNC_GERAIS_H_

#include "glib-2.0/glib.h"

/**
 * Função que verifica se uma chave existe numa HashTable
 * @param key A chave a verificar se existe na HashTable
 * @param hash A HashTable onde se vai fazer a verificação
 * @return Retorna 1 se a chave existe e 0 se a chave não existe
 */
int GContainsKey (int key, GHashTable *hash);

/**
 * Função que remove uma chave e um valor de uma HashTable
 * @param hash A HashTable onde se vai remover o par chave valor
 * @param key A chave a retirar
 * @return Retorna 1 se a chave existe e 0 se a chave não existe
 */
int GRemove (GHashTable *hash, int key);

/**
 * Função que obtem um GArray* de uma GHashTable*
 * @param key A chave onde se pretende buscar o GArray*
 * @param hashTable A HashTable onde se vai fazer a pesquisa
 * @return O GArray* contido na HashTable com a chave indicada
 */
GArray *GHGetArray(int key, GHashTable *hashTable);

/**
 * Função que adiciona um GArray* a uma GHashTable*
 * @param gArray O GArray* a ser adicionado
 * @param key A chave onde se vai inserir o gArray
 * @param hashTable A GHashTable* onde se vai inserir o gArray com a chave key
 */
void GHAddGArray (GArray *gArray, int key, GHashTable *hashTable);

/**
 * Função que dá free da HashTable
 * @param hash A HashTable a libertar da memória
 */
void GHashTable_free(GHashTable *hash);

#endif