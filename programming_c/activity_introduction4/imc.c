#include <stdio.h>

float imc (float altura, float peso){

    float calc_imc;

    calc_imc = peso / (altura * altura);

    return calc_imc;
}

int parametro (float calc2_imc){

    int tipo;

    if(calc2_imc < 18.5){

        tipo = 1;
     
    }
    else if(calc2_imc >= 18.5 && calc2_imc <= 24.9){

        tipo = 2;

    }
    else if(calc2_imc >= 25 && calc2_imc <= 29.9){

        tipo = 3;

    }
    else{

        tipo = 4;

    }

    return tipo;
}

int main(){

    float peso, altura, valor_imc, classificacao;
    
    printf("Qual seu peso?: ");
    scanf("%f", &peso);

    printf("Qual sua altura?: ");
    scanf("%f", &altura);

    valor_imc = imc(altura, peso);
    
    classificacao = parametro(valor_imc);

    printf("Seu imc e %.2f\n", valor_imc);

    if(classificacao == 1){

        printf("Sua classificacao e abaixo do peso ideal!");
    }

    else if(classificacao == 2){

        printf("Sua classificacao e peso normal!");
    }

    else if(classificacao == 3){

        printf("Sua classificacao e sobrepeso!");
    }

    else if(classificacao == 4){

        printf("Sua classificacao e obeso!");
    }

return 0;

}