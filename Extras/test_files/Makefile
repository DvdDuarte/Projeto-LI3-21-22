CC     = gcc
CFLAGS = -Wall -Wextra -Wdouble-promotion -Wconversion -Wsign-conversion  -O0 -g -D_GNU_SOURCE

allprog: teste
	$(CC) $(CFLAGS)  teste.o -o teste

teste: teste.c
	$(CC) $(CFLAGS) $(LFLAGS) -o teste.o -c teste.c
