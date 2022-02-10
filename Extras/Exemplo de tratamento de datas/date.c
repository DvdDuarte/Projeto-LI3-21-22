#define _XOPEN_SOURCE

#include <time.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {
    char *date = "2014-02-07 01:01:35";
    printf("Original date: %s\n", date);

    struct tm time = {0};
    strptime(date, "%Y-%m-%d %H:%M:%S", &time);
    
    printf("%d\n", time.tm_year +1900);
    printf("%d\n", time.tm_mday);
    printf("%d-%d-%d %d:%d:%d\n", time.tm_year +1900, time.tm_mon +1, time.tm_mday, time.tm_hour, time.tm_min, time.tm_sec);
    
    //tm_sec -> segundos (0-60)
    //tm_min -> minutos (0-59)
    //tm_hour -> horas (0-23)
    //tm_mday -> dia do mes (1-31)
    //tm_mon -> mes (0-11)
    //tm_year -> o ano + 1900
    //tm_wday -> dia da semana (0-6, Sunday = 0)
    //tm_yday -> dia do ano (0-365, 1 Jan = 0)
    //tm_isdst -> daylight saving time

    return 0;    
}
