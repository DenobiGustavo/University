#include <stdio.h>
#define MAX 10

int main(){

    int array_num[MAX], count, i, x;

    for(i = 0; i < MAX; i++){
        printf("Escolha um numero: ");
        scanf("%d", &array_num[i]);
    }
      
        count = 0;
        x = 2;

    for(i = 0; i < MAX; i++){
      
        if(array_num[i] == x){
            count++;
        }
    }
         printf("O numero %d apareceu %d vezes", x, count);
}