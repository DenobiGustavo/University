#include <stdio.h>

int main()
{
    int num;
    
    printf("Escreva um numero inteiro: ");
    scanf("%d", &num);
   
    if(num %2 == 0 && num >= 0){
        printf("O numero escolhido e par e positivo");
        }
        else if(num %2 == 0 && num < 0){
            printf("O numero escolhido e par e negativo");
        }
     if(num %2 != 0 && num >= 0){
                printf("O numero escolhido e impar e positivo"); 
            }
        else if(num %2 != 0 && num < 0){
                     printf("O numero escolhido e impar e negativo");      
                }
    }    

