#define _XOPEN_SOURCE
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/model/Data.h"

struct timeC{
    int ano;
    int mes;
    int dia;
};

struct timeH{
    int hora;
    int minuto;
    int segundo;
};

struct time{
    LCalendario calendario;
    LHorario horario;
};

int valid_Data(char* line){

    struct tm time = {0};
    strptime(line, "%Y-%m-%d %H:%M:%S", &time);

    char new_time[30];
    strftime(new_time, 30, "%Y-%m-%d %H:%M:%S", &time);

    if(strcmp(line, new_time) != 0)
        return 0;
    int year = time.tm_year + 1900;
    if(year >= 2005 && year <= 2021){
        int month = time.tm_mon + 1;
        int day = time.tm_mday;
        if((year == 2005 && (month < 4  || (month == 4 && day < 7 ))) || (year == 2021 && (month > 11 || (month == 11 && day > 7))))
            return 0;
        switch (month) {
            case 1:
                if (day <= 0 || day > 31)
                    return 0;
                break;
            case 2:
                if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)){
                    if (day <= 0 || day > 29)
                        return 0;
                }else if(day <= 0 || day > 28)
                    return 0;
                break;
            case 3:
                if(day <= 0 || day > 31 )
                    return 0;
                break;
            case 4:
                if(day <= 0 || day > 30 )
                    return 0;
                break;
            case 5:
                if(day <= 0 || day > 31 )
                    return 0;
                break;
            case 6:
                if(day <= 0 || day > 30 )
                    return 0;
                break;
            case 7:
                if(day <= 0 || day > 31 )
                    return 0;
                break;
            case 8:
                if(day <= 0 || day > 31 )
                    return 0;
                break;
            case 9:
                if(day <= 0 || day > 30 )
                    return 0;
                break;
            case 10:
                if(day <= 0 || day > 31 )
                    return 0;
                break;
            case 11:
                if(day <= 0 || day > 30 )
                    return 0;
                break;
            case 12:
                if(day <= 0 || day > 31 )
                    return 0;
                break;
        }

        int hora = time.tm_hour;
        int min = time.tm_min;
        int sec = time.tm_sec;
        if(hora < 0 || hora > 23 || min < 0 || min > 59 || sec < 0 || sec > 59)
            return 0;
        return 1;
    } else
        return 0;

}


LCalendario build_calendario(char* line){

    struct tm time = {0};
    strptime(line, "%Y-%m-%d", &time);

    LCalendario c = malloc(sizeof(NCalendario));

    c->ano = time.tm_year;
    c->mes = time.tm_mon;
    c->dia = time.tm_mday;

    return c;
}

LHorario build_horario(char* line){

    struct tm time = {0};
    strptime(line, "%H:%M:%S", &time);

    LHorario h = malloc(sizeof(NHorario));

    h->hora = time.tm_hour;
    h->minuto = time.tm_min;
    h->segundo = time.tm_sec;

    return h;
}

LTempo build_time(char* line){

    LTempo t = malloc(sizeof(NTempo));

    if(valid_Data(line)){
        struct tm time = {0};
        strptime(line, "%Y-%m-%d %H:%M:%S", &time);
        char* calendario = malloc(sizeof(char) * 30);
        strftime(calendario, 30, "%Y-%m-%d", &time);
        char* horas = malloc(sizeof(char) * 30);
        strftime(horas, 30, "%H:%M:%S", &time);
        t->calendario = build_calendario(calendario);
        t->horario = build_horario(horas);
    }else
        t = NULL;

    return t;
}

LCalendario clone_Calendario(LCalendario c){

    LCalendario c_new = malloc(sizeof(NCalendario));

    c_new->ano = c->ano;
    c_new->mes = c->mes;
    c_new->dia = c->dia;

    return c_new;
}

LHorario clone_Horario(LHorario h){

    LHorario h_new = malloc(sizeof(NHorario));

    h_new->hora = h->hora;
    h_new->minuto = h->minuto;
    h_new->segundo = h->segundo;

    return h_new;
}

LTempo clone_Tempo(LTempo t){

    if(t == NULL)
        return NULL;

    LTempo nt = malloc(sizeof(NTempo));

    nt->calendario = clone_Calendario(t->calendario);
    nt->horario = clone_Horario(t->horario);

    return nt;
}

char* toString_Tempo(LTempo t){

    if(t == NULL)
        return NULL;

    struct tm time = {0};

    time.tm_year = t->calendario->ano;
    time.tm_mon  = t->calendario->mes;
    time.tm_mday = t->calendario->dia;
    time.tm_hour = t->horario->hora;
    time.tm_min  = t->horario->minuto;
    time.tm_sec  = t->horario->segundo;

    char* new_time = malloc(sizeof(char) * 40);
    strftime(new_time, 40, "%Y-%m-%d %H:%M:%S", &time);

    return strdup(new_time);

}
