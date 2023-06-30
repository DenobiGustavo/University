#include <stdio.h>

int main(){

    int i;
    char str[20];

    printf("Digite uma frase: ");
    fgets(str, 20, stdin);

    for(i = 0; i < 20; i++){

        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){

            str[i] = '*';

        }
    }

    for(i=0; i < 20; i++){

       printf("%c", str[i]);

    }



return 0;

}