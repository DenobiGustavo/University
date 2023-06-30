#include <stdio.h>

int potencia (int x, int n){

    int calc = 0, count = 3;
    
    calc = (x * x);
    
   if(n > 2){
       
    do{
        calc = x * calc;

        count++;
     }
    while(count <= n);
   }
    
    return calc;
}

int main(){

    int x, n, valor_pow;

    printf("Escolha um numero: ");
    scanf("%d", &x);

    printf("Escolha uma potencia: ");
    scanf("%d", &n);

    valor_pow = potencia (x, n);

    printf("O resultado e: %d", valor_pow);
}