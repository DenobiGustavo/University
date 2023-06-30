#include <stdio.h>

int main(){

    int funcionarios, i, j, numerador;
    float aliquota;

    printf("Qual seu numero de funcionarios(max 50)?: ");
    scanf("%d", &funcionarios);

    float array_funcionarios[funcionarios];

    for(i = 0; i < funcionarios; i++){

        printf("Qual o salario do funcionario?: ");
        scanf("%f", &array_funcionarios[i]);

    }
    
    for(j = 0; j < funcionarios; j++){

        numerador = j + 1; 

        if(array_funcionarios[j] <= 1904){

            printf("Funcionario %d, Voce esta isento de impostos!!!\n", numerador);

        }

        else if(array_funcionarios[j] > 1904 && array_funcionarios[j] <= 2827){

            aliquota = (array_funcionarios[j] * (7.5/100));

             printf("Funcionario %d, esta e sua aliquota: %.2f!!!\n", numerador, aliquota);
        }

        else if(array_funcionarios[j] > 2827 && array_funcionarios[j] <= 3751){

            aliquota = (array_funcionarios[j] * (15.0/100));

             printf("Funcionario %d, esta e sua aliquota: %.2f!!!\n", numerador, aliquota);
        }

        else if(array_funcionarios[j] > 3751 && array_funcionarios[j] <= 4665){

            aliquota = (array_funcionarios[j] * (22.5/100));

             printf("Funcionario %d, esta e sua aliquota: %.2f!!!\n", numerador, aliquota);
        }

        else if(array_funcionarios[j] > 4665){

            aliquota = (array_funcionarios[j] * (27.5/100));
            
             printf("Funcionario %d, esta e sua aliquota: %.2f!!!\n", numerador, aliquota);
            
        }
    }

    return 0;
    
}