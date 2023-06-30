#include <stdio.h>

int procurando (int matriz[][], int l, int c, int num){

    int i, j;

    for(i = 0; i < l; i++){

        for(j = 0; j < c; j++){

            if(matriz[i][j] == num){

                return 1;
            }
            else{

                return 0;
            }
        }
    }
}

int main(){

    int l, c, i, j, procurando_num, num_usuario;

    printf("Digite um parametro para a matriz: ");
    scanf("%d%d", &l, &c);

    int mat[l][c];

    for(i = 0; i < l; i++){

        for(j = 0; j < c; j++){

            printf("Digite os valores da matriz: ");
            scanf("%d", &mat[i][j]);

        }
    }
       
    
    printf("Digite um numero que queira procurar: ");
    scanf("%d", &num_usuario);

    procurando_num = procurando(mat, num_usuario);

    printf("%d", num_usuario);




    return 0;

}




