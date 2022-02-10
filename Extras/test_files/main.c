#include <stdio.h>
#include <stdlib.h>

void print_info(char *c, FILE *f) {
    fprintf(f,"%s",c);
}

int main() {

    char *c = "Hello World\n";
    print_info(c, stdout);
    FILE *f = fopen("teste.md","w+");
    print_info(c,f);
    fclose(f);

    return 0;

}