#include <stdio.h>

int main()
{
    int quantidade_terrenos, count;
    float area, comprimento, largura;
    
    count = 1;

    printf("Quantos terrenos voce possui?: ");
    scanf("%d", &quantidade_terrenos);

    while(count <= quantidade_terrenos){

        printf("Qual o comprimento do terreno?: ");
        scanf("%f", &comprimento);

        printf("Qual a largura do terreno?: ");
        scanf("%f", &largura);

        area = largura * comprimento;
        count++;

        printf("A area de seu terreno e: %.2f\n", area);
    }

    return 0;
}