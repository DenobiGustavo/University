#include <stdio.h>

float media_a (float nota1, float nota2){

    float calc_a;

    calc_a = (nota1 + nota2) / 2;

    return calc_a;
}

float media_p (float nota1, float nota2){

    float calc_p;

    calc_p = (nota1 * 3) + (nota2 * 2) / 3 + 2;

    return calc_p;

}

float media_h (float nota1, float nota2){

    float calc_h;

    calc_h = (nota1 * nota2) / ((nota1 + nota2) / 2);
}

int main(){

    float nota1, nota2, media_aritmetica, media_ponderada, media_harmonica;

    printf("Qual as media do aluno?: ");
    scanf("%f%f", &nota1, &nota2);

    media_aritmetica = media_a(nota1, nota2);
    media_ponderada = media_p(nota1, nota2);
    media_harmonica = media_h(nota1, nota2);

    printf("A media arit e %.2f\nA media pond e %.2f\nA media harm e %.2f\n", media_aritmetica, media_ponderada, media_harmonica);

    return 0;
}