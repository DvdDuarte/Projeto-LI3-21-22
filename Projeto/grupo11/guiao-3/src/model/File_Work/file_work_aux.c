/**
 * @file file_work_aux.c
 * @author grupo11
 * @brief Ficheiro que contém as funções auxiliares para trabalhar os ficheiros
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../../../include/model/File_Work/file_work_aux.h"

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

char * paginas_name(int nmr_pagina){
    char num[12];
    sprintf(num, "%d", nmr_pagina);
    char filename[50] = "saida/paginacao/";
    strcat(filename,num);
    strcat(filename,".txt");
    return filename;
}

FILE *paginas(int indice){

    char num[12];
    sprintf(num, "%d", indice);
    char filename[50] = "saida/paginacao/";
    strcat(filename,num);
    strcat(filename,".txt");
    FILE *file = fopen(filename, "w");

    return file;
}

void create_files_paginacao(char *file_to_split, int topN){
    FILE *leitura = fopen(file_to_split,"r");
    printf("%s\n",file_to_split);
    char buffer[buffer_size];
    int resto = 0;
    int nmr_pagina = 1;
    int nmr_linhas_pagina = 19;

    resto = topN % 19;
    
    if(topN > 19) {
        nmr_pagina = topN / 19;
        if(resto != 0) nmr_pagina++;
    }
    //printf("RESTO: %d\n",resto);
    //printf("NMR PAG: %d\n",nmr_pagina);


    for(int i = 1; i <= nmr_pagina; i++){
        if(i == nmr_pagina && resto!=0) nmr_linhas_pagina = resto;
        FILE *aux = paginas(i); 
        for(int j = 0; j < nmr_linhas_pagina; j++){
            fgets(buffer,buffer_size,leitura);
            fprintf(aux,"%s",buffer);
        }
        fclose(aux);
    }
    fclose(leitura);

}

void remove_files_paginacao(int nmr_paginas) {

    int paginas = 0;
    if(nmr_paginas >= 19) paginas = nmr_paginas / 19;

    for(int i = 1; i <= nmr_paginas; i++){
        char num[12];
        sprintf(num, "%d", i);
        char filename[50] = "saida/paginacao/";
        strcat(filename,num);
        strcat(filename,".txt");

        remove(filename);
    }
}