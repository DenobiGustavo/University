#include <stdio.h>

int main()
{
    int numero, count;

    printf("Escolha um numero inteiro: ");
    scanf("%d", &numero);
    
    count = 0;
    
    do{
    
    printf("%d x %d = %d\n", numero, count, (numero * count));
     count++;
    }
        while (count <= 10);
}
