#source files
SRC = src/main.c src/Data.c src/File_Work.c src/Funcoes_Aux.c src/exercicios.c src/ghash_func_gerais.c src/interpretador.c
CAU = src/Catalogo_User/users.c
CAC = src/Catalogo_Commits/commits.c
CAR = src/Catalogo_Repos/repos.c

#all files
OBJ = $(SRC) $(CAU) $(CAC) $(CAR)

#executable name
OUT = guiao-1

#c compiler flags
CCFLAGS = -O2 -Wall -ansi `pkg-config --cflags --libs glib-2.0` -std=c99  #-I$(IDIR)

#compiler
CC = gcc

#libraries
IDIR = -lm

$(OUT): $(OBJ)
		$(CC) -o $(OUT) $(CCFLAGS) $(OBJ) $(IDIR)

clean:
	rm -f *.o .a *~ Makefile.bak $(OUT)
