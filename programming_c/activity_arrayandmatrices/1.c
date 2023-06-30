#include <stdio.h>

int main(){

int m, n, i, j, soma_pares = 0, soma_impares = 0;

printf("Digite um paremetro para a matriz sendo 2 ≤ M ≤ 15 e 3 ≤ N ≤ 20: ");
scanf("%d%d", &m, &n);

int matriz[m][n];

for(i = 0; i < m; i++){

    for(j = 0; j < n; j++){


        printf("Digite os valores da matriz: ");
        scanf("%d", &matriz[i][j]);

    }
}

for(i = 0; i < m; i++){

    for(j = 0; j < n; j++){

        if(matriz[i][j] %2 == 0){

            soma_pares = soma_pares + matriz[i][j];
        }
        else{

            soma_impares = soma_impares + matriz[i][j];
        }
   }
}

printf("A soma dos pares e %d e, a soma dos impares e %d!!!", soma_pares, soma_impares);

return 0;

}