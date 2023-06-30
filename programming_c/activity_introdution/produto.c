#include <stdio.h>

int main()
{
    int num1, num2, num3, num4;
    int calculo;

    printf("Escolha quatro numeros inteiros: ");
    scanf("%d%d%d%d", &num1, &num2, &num3, &num4);

    calculo = (num1*num2) - (num3*num4);

    printf("O resultado do calculo é: %d", calculo);


     
}
