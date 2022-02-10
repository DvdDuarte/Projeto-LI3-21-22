CC     = gcc
CFLAGS = -Wall -Wextra -Wdouble-promotion -Wconversion -Wsign-conversion  -O0 -g -D_GNU_SOURCE
LFLAGS = `pkg-config --cflags --libs glib-2.0`
SRC    = src/
INCLUDE= include/
OBJ    = obj/
CONTROLLER = controller/
MODEL      = model/
VIEW       = view/
CCOMMITS   = Catalogo_Commits/
CREPOS     = Catalogo_Repos/
CUSER      = Catalogo_User/
QUERIES    = queries/
SGR		   = sgr/
SAIDA	   = saida/
FILE       = File_Work/
TESTS      = testsFolder/
OBJ_MAIN_FILES = $(filter-out obj/maintests.o, $(wildcard obj/*.o))
OBJ_TEST_FILES = $(filter-out obj/main.o, $(wildcard obj/*.o))

allprog: build guiao-3 main tests testsmain 
	$(CC) $(CFLAGS) $(OBJ_MAIN_FILES) -o guiao-3 $(LFLAGS)
	$(CC) $(CFLAGS) $(OBJ_TEST_FILES) -o test_exec $(LFLAGS)

tests: testes

guiao-3: model controller interface

model: aux user repo commit file query SGR table

table: Table

aux: Data Funcoes_Aux GHash_Func

user: User Catalogo_user

repo: Repos Catalogo_repos

commit: Commits Catalogo_commits

file: File_work_validacoes Catalogs_file_work File_work_aux

query: QueryE QueryP

controller : Exercicios Interpretador Controller

interface: Queries_Output View

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

Exercicios: $(SRC)$(CONTROLLER)exercicios.c $(INCLUDE)$(CONTROLLER)exercicios.h
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)exercicios.o -c $(SRC)$(CONTROLLER)exercicios.c

Interpretador: $(SRC)$(CONTROLLER)interpretador.c $(INCLUDE)$(CONTROLLER)interpretador.h
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)interpretador.o -c $(SRC)$(CONTROLLER)interpretador.c

SGR: $(SRC)$(MODEL)$(SGR)sgr.c $(INCLUDE)$(MODEL)$(SGR)sgr.h Catalogo_commits Catalogo_repos Catalogo_user 
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)sgr.o -c $(SRC)$(MODEL)$(SGR)sgr.c

File_work_validacoes: $(SRC)$(MODEL)$(FILE)file_work_validacoes.c $(INCLUDE)$(MODEL)$(FILE)file_work_validacoes.h 
	$(CC) $(CFLAGS) -o $(OBJ)file_work_validacoes.o -c $(SRC)$(MODEL)$(FILE)file_work_validacoes.c $(LFLAGS)

Catalogs_file_work: $(SRC)$(MODEL)$(FILE)catalogs_file_work.c $(INCLUDE)$(MODEL)$(FILE)catalogs_file_work.h Data
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)catalogs_file_work.o -c $(SRC)$(MODEL)$(FILE)catalogs_file_work.c

File_work_aux: $(SRC)$(MODEL)$(FILE)file_work_aux.c $(INCLUDE)$(MODEL)$(FILE)file_work_aux.h Data
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)file_work_aux.o -c $(SRC)$(MODEL)$(FILE)file_work_aux.c

Catalogo_user: $(SRC)$(MODEL)$(CUSER)catalogo_users.c $(INCLUDE)$(MODEL)$(CUSER)catalogo_users.h
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)catalogo_users.o -c $(SRC)$(MODEL)$(CUSER)catalogo_users.c

Catalogo_commits: $(SRC)$(MODEL)$(CCOMMITS)catalogo_commits.c $(INCLUDE)$(MODEL)$(CCOMMITS)catalogo_commits.h 
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)catalogo_commits.o -c $(SRC)$(MODEL)$(CCOMMITS)catalogo_commits.c

Catalogo_repos: $(SRC)$(MODEL)$(CREPOS)catalogo_repos.c $(INCLUDE)$(MODEL)$(CREPOS)catalogo_repos.h Repos
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)catalogo_repos.o -c $(SRC)$(MODEL)$(CREPOS)catalogo_repos.c

QueryE: $(SRC)$(MODEL)$(QUERIES)queries_estatisticas.c $(INCLUDE)$(MODEL)$(QUERIES)queries_estatisticas.h
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)queries_estatisticas.o -c $(SRC)$(MODEL)$(QUERIES)queries_estatisticas.c

QueryP: $(SRC)$(MODEL)$(QUERIES)queries_parametrizaveis.c $(INCLUDE)$(MODEL)$(QUERIES)queries_parametrizaveis.h
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)queries_parametrizaveis.o -c $(SRC)$(MODEL)$(QUERIES)queries_parametrizaveis.c

Queries_Output: $(SRC)$(VIEW)queries_output.c $(INCLUDE)$(VIEW)queries_output.h
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)queries_output.o -c $(SRC)$(VIEW)queries_output.c

Table:$(SRC)$(MODEL)table.c $(INCLUDE)$(MODEL)table.h
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)table.o -c $(SRC)$(MODEL)table.c

View: $(SRC)$(VIEW)view.c $(INCLUDE)$(VIEW)view.h
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)view.o -c $(SRC)$(VIEW)view.c

Controller: $(SRC)$(CONTROLLER)controller.c $(INCLUDE)$(CONTROLLER)controller.h
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)controller.o -c $(SRC)$(CONTROLLER)controller.c

testes: $(SRC)$(TESTS)tests.c $(INCLUDE)$(TESTS)tests.h
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)tests.o -c $(SRC)$(TESTS)tests.c

testsmain: $(SRC)$(TESTS)maintests.c
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)maintests.o -c $(SRC)$(TESTS)maintests.c

main: $(SRC)main.c
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ)main.o -c $(SRC)main.c

build: 
	@mkdir saida/paginacao/
	@touch saida/paginacao/README.md
	@mkdir obj/
	
clean: 
	@echo -n "Cleaning...\n"
	@rm -f $(OBJ)*.o
	@rm -rf obj/ saida/paginacao/ 
	@rm guiao-3
	@rm test_exec

