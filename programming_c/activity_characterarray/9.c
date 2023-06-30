#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

char str1[20], str2[20];
int tam, i;

printf("Digite uma frase: ");
fgets(str1, 20, stdin);

tam = 20;

for(i = 0; i < 20; i++){

     str2[tam] = str1[i];

     tam--;
}
 
for(i = 0; i < 20; i++){

    if(str1[i] == str2[i]){

        printf("A palavra e um polindromo!!");

    }
}


    return 0;

}


deu errado mas fds