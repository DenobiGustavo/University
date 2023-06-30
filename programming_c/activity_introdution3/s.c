#include <stdio.h>

int main()
{
    int divisor, dividendo;
    float soma;
    
    dividendo = 1;
    divisor = 1;
    soma = 0;

    
  
    while(dividendo <= 99){

      soma = soma  + (dividendo / divisor);
      dividendo+= 2;
      divisor++;
    }
    
    printf("%.2f", soma);
    
    return 0;
}