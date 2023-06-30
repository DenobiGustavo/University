#include <stdio.h>

int comparacao (int a, int b, int c){

    int maior;

    if(a > b && a > c){

        maior = a;   
     

    }
    else if(b > a && b > c){

        maior = b;

    }
    else if(c > a && c > b){

        maior = c;
    }

    return maior;
}

int main(){

    int a, b, c, compary;

    printf("Escolha tres numeros: ");
    scanf("%d%d%d", &a, &b, &c);

    compary = comparacao(a, b, c);

    printf("O maior e %d", compary);
}