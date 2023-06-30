#include <stdio.h>

int main()
{
    int numero_identificacao;
    int horas_trabalhadas;
    float valor_por_hora;
    float salario;
    
    printf("Qual seu numero de identificacao: ");
    scanf("%d", &numero_identificacao);
    printf("Suas horas trabalhadas: ");
    scanf("%d", &horas_trabalhadas);
    printf("Qual o seu valor por hora: ");
    scanf("%f", &valor_por_hora);
    

    salario = horas_trabalhadas * valor_por_hora;
    
    printf("Seu numero de identificacao e seu salario é: %d\n %f", numero_identificacao, salario);
}