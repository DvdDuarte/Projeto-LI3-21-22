CC     = gcc
CFLAGS = -Wall -Wextra -Wdouble-promotion -Wconversion -Wsign-conversion  -O0 -g -D_GNU_SOURCE
LFLAGS = `pkg-config --cflags --libs glib-2.0`
SRC    = src/
INCLUDE= include/
OBJ    = obj/
CONTROLLER = controller/
MODEL      = model/
CCOMMITS   = Catalogo_Commits/
CREPOS     = Catalogo_Repos/
CUSER      = Catalogo_User/
SGR		   = sgr/
SAIDA	   = saida/


allprog: guiao-1 main
	$(CC) $(CFLAGS) $(OBJ)/*.o -o guiao-1 $(LFLAGS)

guiao-1: model controller

model: aux user repo commit file SGR

aux: Data Funcoes_Aux GHash_Func

user: User Catalogo_user

commit: Commits Catalogo_commits

repo: Repos Catalogo_repos

file: File_Work file_work file_work_aux

model: aux user repo commit file

controller: Exercicios Interpretador

Data: $(SRC)$(MODEL)Data.c $(INCLUDE)$(MODEL)Data.h 
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)Data.o -c $(SRC)$(MODEL)Data.c

Funcoes_Aux: $(SRC)$(MODEL)Funcoes_Aux.c $(INCLUDE)$(MODEL)Funcoes_Aux.h
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)Funcoes_Aux.o -c $(SRC)$(MODEL)Funcoes_Aux.c

GHash_Func: $(SRC)$(MODEL)ghash_func_gerais.c $(INCLUDE)$(MODEL)ghash_func_gerais.h
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)ghash_func_gerais.o -c $(SRC)$(MODEL)ghash_func_gerais.c

User: $(SRC)$(MODEL)$(CUSER)users.c $(INCLUDE)$(MODEL)$(CUSER)users.h 
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)users.o -c $(SRC)$(MODEL)$(CUSER)users.c

Commits: $(SRC)$(MODEL)$(CCOMMITS)commits.c $(INCLUDE)$(MODEL)$(CCOMMITS)commits.h
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)commits.o -c $(SRC)$(MODEL)$(CCOMMITS)commits.c

Repos: $(SRC)$(MODEL)$(CREPOS)repos.c $(INCLUDE)$(MODEL)$(CREPOS)repos.h 
	$(CC) $(CFLAGS) -o $(OBJ)repos.o -c $(SRC)$(MODEL)$(CREPOS)repos.c $(LFLAGS) 

File_Work: $(SRC)$(MODEL)File_Work.c $(INCLUDE)$(MODEL)File_Work.h 
	$(CC) $(CFLAGS) -o $(OBJ)File_Work.o -c $(SRC)$(MODEL)File_Work.c $(LFLAGS)

Exercicios: $(SRC)$(CONTROLLER)exercicios.c $(INCLUDE)$(CONTROLLER)exercicios.h
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)exercicios.o -c $(SRC)$(CONTROLLER)exercicios.c

Interpretador: $(SRC)$(CONTROLLER)interpretador.c $(INCLUDE)$(CONTROLLER)interpretador.h
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)interpretador.o -c $(SRC)$(CONTROLLER)interpretador.c

SGR: $(SRC)$(MODEL)$(SGR)sgr.c $(INCLUDE)$(MODEL)$(SGR)sgr.h Catalogo_commits Catalogo_repos Catalogo_user 
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)sgr.o -c $(SRC)$(MODEL)$(SGR)sgr.c

file_work: $(SRC)$(MODEL)file_work.c $(INCLUDE)$(MODEL)file_work.h Data
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)file_work.o -c $(SRC)$(MODEL)file_work.c

file_work_aux: $(SRC)$(MODEL)file_work_aux.c $(INCLUDE)$(MODEL)file_work_aux.h Data
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)file_work_aux.o -c $(SRC)$(MODEL)file_work_aux.c

Catalogo_user: $(SRC)$(MODEL)$(CUSER)catalogo_users.c $(INCLUDE)$(MODEL)$(CUSER)catalogo_users.h
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)catalogo_users.o -c $(SRC)$(MODEL)$(CUSER)catalogo_users.c

Catalogo_commits: $(SRC)$(MODEL)$(CCOMMITS)catalogo_commits.c $(INCLUDE)$(MODEL)$(CCOMMITS)catalogo_commits.h 
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)catalogo_commits.o -c $(SRC)$(MODEL)$(CCOMMITS)catalogo_commits.c

Catalogo_repos: $(SRC)$(MODEL)$(CREPOS)catalogo_repos.c $(INCLUDE)$(MODEL)$(CREPOS)catalogo_repos.h Repos
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)catalogo_repos.o -c $(SRC)$(MODEL)$(CREPOS)catalogo_repos.c

main: $(SRC)main.c
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)main.o -c $(SRC)main.c

git_clean:
	@echo -n "Cleaning...\n"
	@rm -rf $(OBJ) 
	@rm guiao-1	

clean: 
	@echo -n "Cleaning...\n"
	@rm -rf $(OBJ) 
	@rm guiao-1

