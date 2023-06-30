#include <stdio.h>

int comparacao (int a, int b){

    int maior, menor;

    if(a > b){

        maior = a;   
     

    }
    else{

        maior = b;

    }
    
    return maior;
}

int main(){

    int a, b, compary;

    printf("Escolha dois numeros: ");
    scanf("%d%d", &a, &b);

    compary = comparacao(a, b);

    printf("O maior e %d", compary);
}