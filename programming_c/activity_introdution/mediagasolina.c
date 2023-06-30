#include <stdio.h>

int main()
{
    int km;
    int combustivel;
    int media;

    printf("Quantos km vc andou?: ");
    scanf("%d", &km);

    printf("Quantos litros de combustivel vc gastou?: ");
    scanf("%d", &combustivel);

    media = km/combustivel;

    printf("A media de consumo de seu carro é : %d km por litro", media); 
}