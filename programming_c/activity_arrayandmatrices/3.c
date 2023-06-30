#include <stdio.h>

int main(){

int i, j, k = 0, matriz[2][2], array[23];

for(i = 0; i < 2; i++){

    for(j = 0; j < 2; j++){

        printf("Digite os valores da matriz: ");
        scanf("%d", &matriz[i][j]);
    }
}

for(i = 0; i < 2; i++){

    for(j = 0; j < 2; j++){

        if(matriz[i][j] %7 == 0){

            array[k] = matriz[i][j];

            k++;
         
    }
  }
}

for(i = 0; i < k; i++){

    printf("%d\n", array[i]);

}

return 0;

}