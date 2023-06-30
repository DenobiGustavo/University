#include <stdio.h> 

int main(){

int i;
char str[20];

printf("Digite uma frase: ");
fgets(str, 20, stdin);

for(i = 20; i >= 0; i--){

    printf("%c", str[i]);


    return 0;

   } 
}

   