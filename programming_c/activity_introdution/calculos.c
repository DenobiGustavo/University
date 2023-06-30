#include <stdio.h>

int main()
{
    float num1;
    float num2;
    float num3;
    float conta1;
    float conta2;
    float conta3;
    float conta4;

    printf("Escolha 3 numeros: ");
    scanf("%f%f%f", &num1, &num2, &num3);

    conta1 = (num1*num2)/num3;
    conta2 = num1*num1 + num2 + 5*num3;
    conta3 = num1*num2*num3 + num2 + (num3/3)*5 - 1;
    conta4 = ((num1*num2*num3)*(num1*num2*num3)*(num1*num2*num3))/2;

    printf("O resultado da conta 1 e: %.2f \n", conta1);
    printf("O resultado da conta 2 e: %.2f \n", conta2);
    printf("O resultado da conta 3 e: %.2f \n", conta3);
    printf("O resultado da conta 4 e: %.2f \n", conta4);
    
 return 0;

}