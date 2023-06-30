#include <stdio.h>

int main()
{
    int n1, n2, n3, n4, aluno;
    float media;
   
    for(aluno = 0; aluno < 10; aluno++)
    {
        printf("Qual as 4 notas do aluno: \n");
        scanf("%d%d%d%d", &n1, &n2, &n3, &n4);
        media = (n1 + n2 + n3 + n4)/4;
        printf("A media e %.2f\n", media);
    }
}