#include <stdio.h>

int main()
{
int n, count, num_divisores;
 
printf("Escolha um numero inteiro: ");
scanf("%d", &n);

count = 0;
num_divisores = 0;

printf("Os divisores de %d sao:\n", n);

for(count = 1; count <= n; count++)
{
   if(n % count == 0)
   {
       printf("%d\n", count);
       num_divisores++;
   }
}
 printf("O numero %d possui %d divisore(s)", n, num_divisores);
}
