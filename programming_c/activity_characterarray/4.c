#include <stdio.h>

int main(){

   char str[20], count;

   printf("Digite uma frase: ");
   fgets(str, 20, stdin);

   count = contabilizador(str, 20);

   printf("%d", count);


   return 0;

}

int contabilizador (char str[], int tam){

    int i, contador = 0;

    for(i = 0; i < 20; i++){

        if(str[i] == ' '){

            contador++;
        }
    }


    return contador;

}