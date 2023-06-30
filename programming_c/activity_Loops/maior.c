#include <stdio.h>

int main(){

   int i, j, max, maior;

   printf("Escolha uma quantidade de numeros inteiros para digitar: ");
   scanf("%d", &max);

   int array[max];
   
   for(j = 0; j < max; j++){

   printf("Digite os n numeros: ");s
   scanf("%d", &array[j]);
   
   }

   maior = 0;

   for(i = 0; i < max; i++){

    if(max == 0){
        printf("Zero nao e uma possivel escolha!");
    }
    else if(array[i] > maior){

        maior = array[i];

    }
   }

   printf("%d", maior);

   return 0;
}