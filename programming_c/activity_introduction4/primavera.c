#include <stdio.h>

int mes (int a){

    int estacao;

    if(a >= 9 && a <= 12){

        estacao = 1;
    }
    else if(a == 12 || a >= 1 && a <=3){

        estacao = 2;
    }
    else if(a >= 3 && a <= 6){

        estacao = 3;
    }
    else{

        estacao = 4;
    }

    return estacao;
}

int main(){

    int a, estacao_correspondente;

    printf("Escolha um numero de 1 a 12 correspondente a um mes do ano: ");
    scanf("%d", &a);

    estacao_correspondente = mes(a);

    if(a == 1){

        printf("Seu mes corresponte a primavera!");
    }
    else if(a == 2){

        printf("Seu mes corresponde ao verao!");
    }
    else if(a == 3){

        printf("Seu mes corresponde ao outono!");
    }
    else{

        printf("Seu mes corresponde ao inverno!");
    }


}