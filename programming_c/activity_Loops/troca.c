#include <stdio.h>

int main(){

     int i, j, k, array[5], newarray[5];
 
     for(i = 0; i < 6; i++){

        printf("Digite um numero: ");
        scanf("%d", &array[i]);

     }

     k = 0;

     for(j = 3; j < 6; j++){

         newarray[k] = array [j];

         k++; 
        
    }
         
     for(j = 0; j < 3; j++){

         newarray[k] = array [j];

         k++; 

}
     
     for(i = 0; i < 6; i++){

         printf("%d\n", newarray[i]);

     }
     
}