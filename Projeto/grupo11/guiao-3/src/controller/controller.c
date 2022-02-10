/**
 * @file controller.c
 * @author grupo11
 * @brief Ficheiro que contém as funções que controlam o programa
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../../include/controller/controller.h"

int controller(int argc, char *argv[]) {
    char *program_name;
    program_name = strstr(argv[0], "guiao-3");

    if(program_name == NULL || strcmp(program_name, "guiao-3") != 0){
        errno = 1;
        perror("ERROR");
        exit(-1);
    }

    FILE *comandos;
    char buffer[buffer_size];
    int indice = 0;
    SGR sgr;
    sgr = init_sgr();
    fill_sgr(sgr, "users.csv", "commits.csv", "repos.csv");
    getchar();

    if (argc < 2 && strcmp(program_name, "guiao-3") == 0) {
        bool flag;
        flag = true;
        printQueries(1);
        while(flag) {
            int rValue = menuController(sgr);
            if (rValue == -1) flag = false;
        }
    } else if (strcmp(program_name, "guiao-3") == 0 && argc == 2) {
    	char filepath[] = "entrada/";
        char *teste = argv[1];
        char *filename = strcat(filepath, teste);
        comandos = fopen(filename, "r");

        if(comandos == NULL) {
            perror("File not found - commands.txt!");
            return 1;
        }
        printDefaultScreen();
        getchar();
        // Ler Ficheiro de comandos
        for (indice = 1; fgets(buffer, buffer_size, comandos); indice++) {
            //printf("%d | ARG:%s\n",indice, buffer);
            interpretador(sgr,buffer, indice);
        }
    } else {
        errno = 1;
        perror("ERROR");
        exit(-1);
        }

        return 0;

}

int menuController(SGR sgr){
    int l = 1 ,c = -1 , q = 0;   
    char buffer = NULL;
    printQueries(1);
    while (1) {   
        system("/bin/stty raw");
        buffer = getchar();
        system("/bin/stty cooked");
        
        switch (buffer)
        {
            case (65): // UpArrow
                if(l > 1 && l <= 10) l--;
                break;
            case (66): // DownArrow
                if(l > 0 && l < 10) l++;
                break;
            case (67): // RightArrow
                if(l == -1 && c==4) c++;
                break;
            case (68): // LeftArrow
                if(l == -1 && c==0) c--;
                break;
            case (13): // ENTER
                //doQuery(l, sgr);
                q = 1;
                break;
            case (32):
                return l;
            case (9): // TAB
                return -1;
            case (127): //BACKSPACE
                l = 1; 
                c = -1;
                q = 0;
                printf("Backspace\n");
                printQueries(1);
                break;
            default: 
                break;
        }
        
        int res = switchWindowQueries(l,q,sgr);
        if(res == -1) {
            return res;
        } else if(res == -2) {
            printQueries(1);
            l = 1;
        }
        q = 0;
    //printf("c=%d  l=%d  q=%d  buffer=%d\n", c , l, q, buffer);
    }
    
}

int switchWindowQueries(int l, int q, SGR sgr){
    switch (q){
        case (0):    
            switch (l){
                case(0):
                printQueries(1);
                return 0;
                break;
                case (1):
                printQueries(1);
                return 0;
                break;
                case (2):
                printQueries(2);
                return 0;
                break;
                case (3):
                printQueries(3);
                return 0;
                break;
                case (4):
                printQueries(4);
                return 0;
                break;
                case (5):
                printQueries(5);
                return 0;
                break;
                case (6):
                printQueries(6);
                return 0;
                break;
                case (7):
                printQueries(7);
                return 0;
                break;
                case (8):
                printQueries(8);
                return 0;
                break;
                case (9):
                printQueries(9);
                return 0;
                break;
                case (10):
                printQueries(10);
                return 0;
                break;
            }
            break;
        
        case (1):
        switch (l){
                case (1):
                return doQuery(1,sgr);
                break;
                case (2):
                return doQuery(2,sgr);
                break;
                case (3):
                return doQuery(3,sgr);
                break;
                case (4):
                return doQuery(4,sgr);
                break;
                case (5):
                return doQuery(5,sgr);
                break;
                case (6):
                return doQuery(6,sgr);
                break;
                case (7):
                return doQuery(7,sgr);
                break;
                case (8):
                return doQuery(8,sgr);
                break;
                case (9):
                return doQuery(9,sgr);
                break;
                case (10):
                return doQuery(10,sgr);
                break;
            }
    }
    return 0;
}

int doQuery(int query, SGR sgr) {
    int res = 0;
    int topN = 0;
    int check = 0;
    char datai[20], dataf[20];
    switch (query)
    {
        case(-1):
            return 0;
    case (1):
        query1(-1, sgr);
        return 0;
        break;
    case (2):
        query2(-1, sgr);
        return 0;
        break;
    case (3):
        query3(-1, sgr);
        return 0;
        break;
    case (4):
        query4(-1, sgr);
        return 0;
        break;
    case (5):
        while(check != 1) {
            paginacaoTop();
            puts(RESET);
            printf("Insira o top N de utilizadores: \n");
            check = scanf("%d",&topN);
            if(check != 1) clean_stdin();
        }
        printf("Insira a data inicial: \n");
        scanf("%s",datai);
        
        printf("Insira a data final: \n");
        scanf("%s",dataf);
        
        int time = query5(-1,topN,datai,dataf,sgr);
        
        //printf("%d / %d",time/1000,time%100);
        
        res = paginacao_controller(query, topN, time);
        remove("saida/paginacao/query5_paginacao.csv");
        return res;
        break;
    case (6):
        building();
        //query6(query, sgr);
        return 0;
        break;
    case (7):
        building();
        //query7(query, sgr);
        return 0;
        break;
    case (8):
        building();
        //query8(query, sgr);
        return 0;
        break;
    case (9):
        building();
        //query9(query, sgr);
        return 0;
        break;
    case (10):
        building();
        //query10(query, sgr);
        return 0;
        break;
    
    
    default:
        return 0;
        break;
    }
    return 0;
}


int paginacao_controller(int query, int topN, int time){
    
    switch (query)
    {
    case 5:
        create_files_paginacao("saida/paginacao/query5_paginacao.csv", topN);
        break;
    case 6:
        create_files_paginacao("saida/paginacao/query6_paginacao.csv", topN);
        break;
    case 7:
        create_files_paginacao("saida/paginacao/query7_paginacao.csv", topN);
        break;
    case 8:
        create_files_paginacao("saida/paginacao/query8_paginacao.csv", topN);
        break;
    case 9:
        create_files_paginacao("saida/paginacao/query9_paginacao.csv", topN);
        break;
    case 10:
        create_files_paginacao("saida/paginacao/query10_paginacao.csv", topN);
        break;
    default:
        break;
    }

    FTABLE table = NULL;
    table = fill_ftable(table,topN);

    int eof = 0;
    int pagina = 1;
    int pg_atual = 0;
    int pg_pretendida = 0;
    int resto = 0;
    double total_paginas = 1;
    int pg_total;
    resto = topN % 19;
    if(topN > 19) {
        total_paginas = floor(topN / 19);
        if(resto != 0) total_paginas++;
    }
    pg_total = (int) total_paginas;
    eof = paginacao_output(table, pagina, pg_total, time);
    

    char buffer = NULL;
    while (1) {   
        system("/bin/stty raw");
        buffer = getchar();
        system("/bin/stty cooked");
        switch (buffer)
        {
            case (67): // RightArrow
                table = get_ftable_next(table);
                if(((resto) == 0 && pagina < pg_total) || ((resto) != 0 && pagina < pg_total)) pagina++;
                eof = paginacao_output(table,pagina, pg_total, time);
                if (eof == -1) return;
                break;
            case (68): // LeftArrow
                table = get_ftable_prev(table);
                if(pagina > 1) pagina--;
                eof = paginacao_output(table,pagina, pg_total, time);
                break;
            case (105): // i for inserting page number
                pg_pretendida = 0;
                int check = 0;
                while(pg_pretendida <= 0 || pg_pretendida > pg_total || check != 1) {
                    paginacaoTop();
                    puts(RESET);
                    printf("Insira o número da página (encontra-se na página %d/%d): ", pagina, pg_total);
                    check = scanf("%d",&pg_pretendida);
                    if(check != 1) clean_stdin();
                }
                //if(pg_pretendida > total_paginas) pg_pretendida = pagina;
                pg_atual = pagina;
                if(((resto) == 0 && pagina < pg_total) || ((resto) != 0 && pagina < pg_total) && pg_pretendida <= pg_total) pagina = pg_pretendida;
                if(pg_pretendida > 1) pagina = pg_pretendida;

                for(int i = pg_atual; i < pg_pretendida; i++) {
                    table = get_ftable_next(table);
                }

                for(int i = pg_atual; i > pg_pretendida; i--) {
                    table = get_ftable_prev(table);
                }

                eof = paginacao_output(table,pagina, pg_total, time);
                if (eof == -1) return;
                break;
            case (9): // TAB
                remove_files_paginacao(topN);
                free_table(table);
                return -1;
            case (127): //BACKSPACE
                remove_files_paginacao(topN);
                free_table(table);
                return -2;
                break;
            default: 
                break;
        }
        
    }
    return 0;
}

void clean_stdin(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
