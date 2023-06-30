#include <stdio.h>

int main()
{
    float salario;
    int cargo;

    printf("Qual seu cargo, digite 1 para Vendedor(a), 2 para Auxiliar de escritorio, 3 para Auxiliar de Enfermagem e 4 para Bibliotecario(a)?: ");
    scanf("%d", &cargo);

    printf("Qual seu salario?: ");
    scanf("%f", &salario);

    if(cargo > 4 || cargo <= 0){
        printf("Proficao invalida!");
        
        return 0;
    }

    switch (cargo)
    {
    case 1 :
    salario = salario + (salario * 0.1);
        break;
    case 2 :
    salario = salario + (salario * 0.07);
        break;
    case 3 :
    salario = salario + (salario * 0.12);
        break;
    case 4 :
    salario = salario + (salario * 0.11);
        break;
    }

    printf("Seu novo salario e em reais: %.2f", salario);
}