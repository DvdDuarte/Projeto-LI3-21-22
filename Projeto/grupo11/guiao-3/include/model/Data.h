/**
 * @file Data.h
 * @author grupo11
 * @brief Ficheiro que contém as funções que para trabalhar com o tipo de LTempo
 * @version 1.0
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _DATA_H_
#define _DATA_H_

/**Tipo de Dados Calendario*/
typedef struct timeC NCalendario, *LCalendario;

/** Tipo de Dados Horario*/
typedef struct timeH NHorario, *LHorario;

/** Tipo de Dados Tempo*/
typedef struct time NTempo, *LTempo;


LCalendario build_calendario(char* line);

/**
 * Função que transforma uma string no tipo de dados LTempo
 * @param line A string que contém os valores da data
 * @return A data no tipo LTempo
 */
LTempo build_time(char* line);

/**
 * Função que valida se uma data está dentro dos parametros descritos no guião 1
 * @param line A string que contém os valores da data
 * @return A função retorna 0/1 se a data se encontra dentro dos parametros 0/1 caso contrário
 */
int valid_Data(char* line);

/**
 * @brief Função que verifica se um Calendário está dentro de um intervalo de tempo
 * 
 * @param inicio Início do Intervalo de Tempo
 * @param fim Fim do Intervalo de Tempo
 * @param atual Calendário a ser testado
 * @return int Se estiver dentro do intervalo devolve 1, caso o contrário devolve 0
 */
int Calendario_Compere(LCalendario inicio, LCalendario fim, LCalendario atual);

/**
 * @brief Função que faz clone do tipo de Dados Calendário 
 * 
 * @param c Calendário
 * @return LCalendario nova cópia de Calendário
 */
LCalendario clone_Calendario(LCalendario c);

/**
 * Função que retorna um clone de uma variável do tipo LTempo
 * @param t A data que se pretende obter
 * @return Um clone da data contida em t
 */
LTempo clone_Tempo(LTempo t);

/**
 * Função que transforma o tipo LTempo numa string
 * @param t A data a ser transformada numa string
 * @return Uma string que contém a data de t
 */
char* toString_Tempo(LTempo t);

#endif //_DATA_H_
