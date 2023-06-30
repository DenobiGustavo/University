#include <stdio.h>

int fat (int n) {

    int fat = 1;
    while(n  > 1){

        fat*= n;
        n--;

    }
    return fat;
}

int main(){
    int x, resultado;

    printf("Digite um valor: ");
    scanf("%d", &x);

    resultado = fat(x);
 
    printf("O resultado e: %d", resultado);
}