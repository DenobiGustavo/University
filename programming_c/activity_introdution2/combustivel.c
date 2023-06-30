#include <stdio.h>

int main()
{
   int km, litros;
   int categoria; 

   printf("Quantos km vc rodou?: ");
   scanf("%d", &km);
   
   printf("Qual a categoria de seu carro? DIgite 1 para(a), 2 para(b) ou 3 para(c): ");
   scanf("%d", &categoria);

   switch (categoria)
   {
   case 1 :
   categoria = 15;
   break;

   case 2 :
   categoria = 12;
   break;

   case 3 :
   categoria = 10;
   break;
   
   default :
   printf("Nao existe essa categoria");
   }
   
   litros = km / categoria;

   if(categoria == 15 || categoria == 12 || categoria == 10){
   printf("Seu consumo foi de %d litros", litros);
   }
 }

  