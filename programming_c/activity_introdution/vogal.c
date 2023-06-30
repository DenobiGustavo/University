#include <stdio.h>

int main()
{
    char letra;
    printf("Escolha uma vogal: ");
    scanf("%c", &letra);

    if(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' || letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U'){
        printf("Vogal\n"); 
    }
    else{
        printf("nao e vogal\n");
    }
    return 0;
}