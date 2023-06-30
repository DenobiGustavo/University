#include <stdio.h>

int main()
{
    int n, calc;

        calc = 1;
    do{
        printf("Digite um numero inteiro: ");
        scanf("%d", &n);


        if(n >= 0){
        break;
        }
        else if(n % 2 == 0){

        calc = calc * n;
        
        }
    }
    while(n > 0);

    if(calc == 1){
        printf("Ops, nao temos numeros suficientes!");
    }
    else if(calc != 1){
        printf("O valor do produto e: %d", calc);
    }
} 