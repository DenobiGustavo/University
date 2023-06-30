#include <stdio.h>

int main()
{
    float n1, n2, n3 ,n4;
    float media;
    
    printf("Entre com as quatro notas do aluno: ");
    scanf("%f%f%f%f", &n1, &n2, &n3 ,&n4);

    media = (n1, n2, n3, n4) / 4;
    
    printf("%.2f", media);
   
    if(media >= 7){
      printf("Aprovado!!!\n");
    } 
    else if(media >= 4 && media < 7){
      printf("voce esta de exame");
    }
    else{
     printf("Reprovado");
    }
}