#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, delta, raiz_positiva, raiz_negativa;
    
    printf("Escolha o primeiro numero: ");
    scanf("%f", &a);
    printf("Escolha o segundo numero: ");
    scanf("%f", &b);
    printf("Escolha o terceiro numero: ");
    scanf("%f", &c);

    delta = (b*b) - 4*a*c;
    raiz_positiva = (-b + pow(delta, 0.5))/2*a;
    raiz_negativa = (-b - pow(delta, 0.5))/2*a;
    
    if(delta < 0){
        printf("Nao existem raizes reais");
    }
    else if(delta > 0){
        printf("As raizes da equação sao %f e %f", raiz_positiva, raiz_negativa);
    }
    else{
        printf("A equação nao é do segundo grau");
    }

}
