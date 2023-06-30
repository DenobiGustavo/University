#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main(){

char str1[20];
int vogais; 

printf("Digite uma frase: ");
fgets(str1, 20, stdin);

vogais = vogal(str1, 20);

printf("%d", vogais);



return 0;

}

int vogal (char str[], int tam){

    int i, count = 0;

    for(i = 0; i < tam; i++){

        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){

            count++;
        }
    }



    return count;

}