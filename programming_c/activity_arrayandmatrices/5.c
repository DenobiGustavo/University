#include <stdio.h>

int main(){

    int i, j, l, c, soma = 0;
    float media;

    printf("Digite um parametro de uma matriz quadrada: ");
    scanf("%d%d", &l, &c);

    int mat[l][c];

    for(i = 0; i < l; i++){

        for(j = 0; j < c; j++){

            printf("Digite os valores: ");
            scanf("%d", &mat[i][j]);
        }
    }

    for(i = 0; i < l; i++){

        soma = soma + mat[i][i];

    }

    media = soma / l;

    printf("%.2f", media);

return 0;

}