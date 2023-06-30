#include <stdio.h>

int main()
{
    int num;
    int antecessor;
    int sucessor;

    printf("Escolha um numero inteiro: ");
    scanf("%d", &num);
    
    antecessor = num - 1;
    sucessor = num + 1;
    
    printf("Seu numero escolhido e: %d\nSeu antecessor e: %d\nSeu sucessor e: %d\n", num, antecessor, sucessor);
    
}