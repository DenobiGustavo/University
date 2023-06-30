#include <stdio.h>
#include <math.h>

float delta (float a, float b, float c){
   
   float calc_delta, x1, x2;

   calc_delta = ((b * b) - 4 * a * c);

   if(calc_delta < 0){

   printf("Nao existem raízes para a equacao...");
   
   return 0;
   }

   return calc_delta;
  
}

float raiz1 (float a, float b, float c){

   float x1;

   x1 = (-b + sqrt((b * b) - 4 * a * c)) / 2 * a;

   return x1;
}

float raiz2 (float a, float b, float c){

   float x2;

   x2 = (-b - sqrt((b * b) - 4 * a * c)) / 2 * a;

   return x2;
}

int main(){

    float a, b, c, valor_delta, valor_raiz1, valor_raiz2;

    printf("Escolha o a da equacao: ");
    scanf("%f", &a);

    printf("Escolha o b da equacao: ");
    scanf("%f", &b);

    printf("Escolha o c da equacao: ");
    scanf("%f", &c);

   valor_delta = delta(a, b, c);

   valor_raiz1 = raiz1(a, b, c);

   valor_raiz2 = raiz2(a, b, c);
   
   if(delta > 0){
       
      printf("os valores de delta, x1 e x2 sao:\n %.2f\n%.2f\n%.2f\n", valor_delta, valor_raiz1, valor_raiz2); 
   }

}