#include <stdio.h>
int main()
{
    float num1, num2, num3, media;
    int acima_media = 0;

    printf("Escolha um numero positivo: ");
    scanf("%f", &num1);
    printf("Escolha um numero positivo: ");
    scanf("%f", &num2);
    printf("Escolha um numero positivo: ");
    scanf("%f", &num3);
    
    media = (num1 + num2 + num3)/3;

    if(num1 > media){
      acima_media++;  
    }
    if(num2 > media){
        acima_media++;
    }
    if(num3 > media){
        acima_media++;
    }
    printf("%d e o tanto de numeros acima da media", acima_media);
}