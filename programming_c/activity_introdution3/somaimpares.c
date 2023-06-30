#include <stdio.h>

int main()
{
    int numero = 1;
    int soma = 0;

    do{
        if(numero % 2 != 0){
        soma = numero + soma;
        }
        numero++;
    }
    while(numero <= 10);
    printf("a soma e : %d", soma);
}
    