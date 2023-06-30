#include <stdio.h>

int main()
{
    int n, num, soma, count;
    float media;

    count = 1;
    soma = 0;

    printf("Quantos numeros vai digitar?: ");
    scanf("%d", &n);

    do{
        printf("digite um numero: ");
        scanf("%d", &num);
        soma = soma + num;
        count++;
    }
    while(count <= n);

    media = soma / n;

    printf("A media dos numeros escolhidos e: %.2f", media);
}