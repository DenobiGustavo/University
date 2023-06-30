#include <stdio.h>

int main()
{
    int x, y, count;

    printf("Escolha dois numeros inteiros:");
    scanf("%d%d", &x, &y);

    count = x + 1;

    do{
        if(x < 7){
            printf("ops, nenhum numero encontrado!");
        }
          else if (count % 5 == 2 || count % 5 == 3){
            printf("%d\n", count);
        }

        count++;

    }
    while(count < y);
}