#include <stdio.h>

int main(){

int i, j, matriz[4][5], biggest;

for(i = 0; i < 4; i++){

    for(j = 0; j < 5; j++){

        printf("Digite os valores da matriz: ");
        scanf("%d", &matriz[i][j]);
    }
}

biggest = maior (matriz);

printf("O maior é %d", biggest);

}

int maior (int mat[4][5]){

int i, j, maior_valor = 0;

for(i = 0; i < 4; i++){

    for(j = 0; j < 5; j++){

        if(mat[i][j] > maior_valor){

         maior_valor = mat[i][j];

     }
   }
}

return maior_valor;

}
