#include <stdio.h>

int count (int array[], int tamanho){

int ultimo_numero = array[tamanho - 1];
int contador = 0;
int i;

    for(i = 0; i < tamanho; i++){

        if(ultimo_numero == array[i]){

            contador++;

        }
    }

    return contador;

}

int main(){

    int n = 5, i, array_numeros[5], contagem;

    for(i = 0; i < n; i++){

        printf("Digite 5 numeros inteiros: ");
        scanf("%d", &array_numeros[i]);
    }

    contagem = count(array_numeros, 5);

    printf("O numero de repeticoes do ultimo numero e: %d", contagem);
}