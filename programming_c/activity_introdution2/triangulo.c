#include <stdio.h>

int main()
{
    float num1;
    float num2;
    float num3;

    printf("Escolha tres lados de um triangulo: ");
    scanf("%f%f%f", &num1, &num2, &num3);

    if(num1 == num2 && num1 == num3 && num2 == num3){
        printf("o triangulo e equilatero e isoceles");
    }
    else if(num1 == num2 || num1 == num3 || num2 == num3){
        printf("o triangulo e isoceles");
    }
    else{
        printf("o triangulo e escaleno");
    }
}