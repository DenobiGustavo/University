#include <stdio.h>

int main()

{
int num1, num2, num3;
printf("Escolha um numero: ");
scanf("%d", &num1);
printf("Escolha um numero: ");
scanf("%d", &num2);
printf("Escolha um numero: ");
scanf("%d", &num3);

if(num1 < num2 && num1 < num3){
    printf("o numero %d e o menor numero", num1);
    }
    else if(num2 < num1 && num2 < num3){
        printf("o numero %d e o menor numero", num2);
    }
    else if(num3 < num1 && num3 < num2){
        printf("o numero %d e o menor numero", num3);
    }
    else{
        printf("opsss");
    }
}
