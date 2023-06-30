#include <stdio.h>

int main()
{
    float salario, reajuste_salario;
    int cargo;

    printf("Digite seu salario: ");
    scanf("%f", &salario);

    printf("Digite 1 para vendedor, 2 para auxiliar de escritorio, 3 para auxiliar de enfermagem e 4 para bibliotecario: ");
    scanf("%d", &cargo);

    switch (cargo)
    {
      case 1:
      reajuste_salario = salario + (salario * 0.1);
      
      printf("Seu novo salario e: %f", reajuste_salario);

        break;

      case 2:
      reajuste_salario = salario + (salario * 0.07);

      printf("Seu novo salario e: %f", reajuste_salario);

        break;

      case 3:
      reajuste_salario = salario + (salario * 0.12);

      printf("Seu novo salario e: %f", reajuste_salario);

        break;

      case 4:
      reajuste_salario = salario + (salario * 0.11);

      printf("Seu novo salario e: %.2f", reajuste_salario);

        break;
    
    default:
     
      printf("Nenhum cargo encontrado!");
    
       
    }

}