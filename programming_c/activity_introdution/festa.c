#include <stdio.h>

int main()
{
    char nome;
    int idade;
    printf("escreva seu nome: ");
    scanf("%c", &nome);
    printf("escrea sua idade: ");
    scanf("%d", &idade);

    if(idade >= 18){
        printf("Cola na festa");
    }
    else if(idade < 18){
        printf("vaza, parça");
    }
}