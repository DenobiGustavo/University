#include <stdio.h>

int main()
{
    int pago;
    int perdeu;

    printf("Quando voce inseriu na maquina(multiplo de 5)?");
    scanf("%d", &pago);

    perdeu = pago % 7;

    printf("Voce perdeu %d reais", perdeu);

}