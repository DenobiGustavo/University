#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

char str1[20];
char vogal;
int count = 0, i;

printf("Digite uma frase: ");
fgets(str1, 20, stdin);

printf("Digite uma vogal: ");
scanf("%c", &vogal);

for(i = 0; i < 20; i++){

    if(str1[i] == vogal){

        count++;
    }
}

printf("%d", count);




return 0;

}