#include <stdio.h>

float ordenacao (float array[], int n){

    int i, j;

    for(i = 0; i < n; i++){

        if(n == 0){
            break;
        }
        else if(array[i] > array[i + 1]){

            array[i + 1] = array[i];
        }
    }
}
int main(){

   float comparacao;
   int i, j, max;

   printf("Escolha uma quantidade de numeros reais para digitar: ");
   scanf("%d", &max);

   float array_reais[max];
   
   for(j = 0; j < max; j++){

   printf("Digite os n numeros: ");
   scanf("%f", &array_reais[j]);
   
   }

   comparacao = ordenacao(array_reais, max);

   for(i = 0; i < max; i++){

    printf("%f\n", array_reais[i]);

   }

   return 0;

   }