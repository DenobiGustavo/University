#include <stdio.h>

int main()
{
    int num1, num2, num3;

    printf("Escolha um numero inteiro: ");
    scanf("%d", &num1);

    printf("Escolha um numero inteiro: ");
    scanf("%d", &num2);

    printf("Escolha um numero inteiro: ");
    scanf("%d", &num3);

    if(num1 == num2 && num1 == num3 && num3 == num2){
        printf("1");
    }
    else if(num1 != num2 && num1 != num3 && num3 != num2){
        printf("2");
    }
    else{
        printf("3");
}
}