#define max 250
#include <stdio.h> 

int main(){

    float array[max];
    int i, j, count = 0;

    do{

         for(i = 0; i < max; i++){

         printf("Digite um numero: ");
         scanf("%f", &array[i]);

    }

    }while (i != -1);

    for(j = 0; j < max; j++){

         if(array[j] > 10 && array[j] < 50){

             count++;

        }
    }
    
     printf("O quantidade de nbumneros entre 10 e 50 e: %d", count);

     return 0;
    
}
