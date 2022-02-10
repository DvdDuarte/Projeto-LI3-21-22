#include "../../include/model/file_work_aux.h"

GHashTable *ler_file_aux(char *filename){
    FILE *leitura = fopen(filename,"r");
    GHashTable *Tid = g_hash_table_new(g_int_hash, g_int_equal);

    if(leitura == NULL) {
        perror("File not found - aux!");
        return NULL;
    }

    char *buffer = malloc(sizeof(char) * 1000000);
    int i = 0;
    int key = 0;
    while(fgets(buffer,1000000, leitura)) {
        char *aux = buffer;
        key = atoi(strsep(&aux,";\n"));
        int *keyaux = malloc(sizeof(int));
        *keyaux = key;
        g_hash_table_insert(Tid, keyaux, key);
        i++;
    }

    fclose(leitura);

    return Tid;
}

FILE *output(int indice){

    char num[12];
    sprintf(num, "%d", indice);
    char filename[50] = "saida/command";
    strcat(filename,num);
    strcat(filename,"_output.txt");

    FILE *file = fopen(filename, "w");

    return file;
}