#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main(){

char str1[20], str2[20];
int i, count1 = 0, count2 = 0, semelhanca, tamanho1, tamanho2;

printf("Digite uma frase: ");
fgets(str1, 20, stdin);

printf("Digite outra frase: ");
fgets(str2, 20, stdin);

semelhanca = strcmp(str1, str2);

tamanho1 = strlen(str1);
tamanho2 = strlen(str2);

printf("%d%d%d", semelhanca, tamanho1, tamanho2);

}






