#include <stdio.h>

int main(){

    int i, j, mat[10][10];


    for(i = 0; i < 10; i++){

        for(j = 0; j < 10; j++){

            if(i == j){

             mat[i][j] = 0;

        }
             
            else{

             mat[i][j] = 1;

        }
     } 
}

    for(i = 0; i < 10; i++){

        for(j = 0; j < 10; j++){  

            printf("%d\n", mat[i][j]);

         } 
     }   

     return 0;
     
}