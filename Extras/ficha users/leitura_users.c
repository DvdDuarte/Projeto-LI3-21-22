#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define buffer_size 1024

// =============***************** IDEIA DE STRUCT PARA USER *****************=============
struct gh_user{
	char *public_repo; //int public_repo;
	char *id; //int id;
	char *followers; //int followers;
	char *follower_list; //int *follower_list;
	char *type;
	char *following_list;
	char *public_gits; //int public_gists;
	char *created_at;
	char *following; //int following;
	char *login;
};

typedef struct gh_user* GH_USER;

//int verifica_dados (char *dado)  --> user->....
/**int verifica_user (GH_USER) {

	if(verifica_dados(user->public_repo)) return 1;
	if(verifica_dados(u->id)) return 1;

	for(int i = 0; i < strlen(u->follower_list); i++) {
		if(verifica_dados(u->follower_lisr[i])) return 1;
	}


	return 0;
}
*/

GH_USER build_user(char *line) {
	
	GH_USER u = malloc(sizeof(struct gh_user));

	u->public_repo = strdup(strsep(&line, ";\n"));
	u->id = strdup(strsep(&line, ";\n"));
	u->followers = strdup(strsep(&line, ";\n"));
	u->follower_list = strdup(strsep(&line, ";\n"));
	u->type = strdup(strsep(&line, ";\n"));
	u->following_list = strdup(strsep(&line, ";\n"));
	u->public_gits = strdup(strsep(&line, ";\n"));
	u->created_at = strdup(strsep(&line, ";\n"));
	u->following = strdup(strsep(&line, ";\n"));
	u->login = strdup(strsep(&line, ";\n"));

	return u;
}

void print_user(GH_USER u) {

	printf("public_repo: %s\nid: %s\nfollowers: %s\nfollower_list_: %s\ntype: %s\nfollowing_list: %s\npublic_gits: %s\ncreated_at: %s\nfollowing: %s\nlogin: %s\n",
	u->public_repo,
	u->id,
	u->followers,
	u->follower_list,
	u->type,
	u->following_list,
	u->public_gits, 
	u->created_at,
	u->following,
	u->login
	);

}

void free_user_content(GH_USER u) {
	free(u->public_repo);
	free(u->id);
	free(u->followers);
	free(u->follower_list);
	free(u->type);
	free(u->following_list);
	free(u->public_gits);
	free(u->created_at);
	free(u->following);
	free(u->login);
}

int main(int argc, char *argv[]) {

	FILE *f = fopen("users100.csv","r");
	
	if(f == NULL) {
		perror("FILE NOT FOUND");
		return 1;
	}

	char buffer[124];
	char *buffer2;
	char *linhas[buffer_size];
	int i = 0;
	GH_USER *user = malloc(sizeof(GH_USER) * 2);

	fgets(buffer, 124, f);

	while(fgets(buffer,124, f)) {

		//linhas[i] = malloc(sizeof(char) * (strlen(buffer)));
		//strcpy(linhas[i],buffer);
		//linhas[i] = strdup(buffer);

		buffer2 = buffer;
		user = realloc(user, sizeof(GH_USER) * (i + 1));
		user[i] = build_user(buffer2);

		i++;
	}

	for(int j = 0; j < i; j++) { 
		print_user(user[j]);
		free_user_content(user[j]);
		free(user[j]);
	}

	//free(user[i+1]);
	free(user);

	fclose(f);
	
	return 0;
}
