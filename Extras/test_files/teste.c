#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 100

int main(){

FILE *fp1, *fp2;

fp1=fopen("file1.txt", "r");
fp2 = fopen("file2.txt","r");

char l1[MAXSIZE], l2[MAXSIZE];
int c = 1;

        while(fgets(l1,MAXSIZE,fp1) && fgets(l2,MAXSIZE,fp2)){
                if(strcmp(l1,l2)==0){
                        printf("equal; line: %d\n",c);
                }
                else{
                        printf("NOT Equal; line: %d\n",c);
                }
                c++;
        }
        fclose(fp1);
        fclose(fp2);
  return 0;
}