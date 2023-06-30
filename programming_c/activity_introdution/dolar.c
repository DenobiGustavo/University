#include <stdio.h>

int main()
{
    float quantidade_dolar;
    float quantidade_real;

    printf("Quanto voce possui em dolar?: ");
    scanf("%f", &quantidade_dolar);

    quantidade_real = quantidade_dolar * 4.87;

    printf("Voce possui %.2f dolares", quantidade_real);

}