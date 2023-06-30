#include <stdio.h>

int main()
{
    float num1, num2, operation;
    

    printf("Choose a number: ");
    scanf("%f", &num1);

    printf("Choose another number: ");
    scanf("%f", &num2);

    printf("Choose one of the four operating options available, 1, 2, 3 or 4: ");
    scanf("%f", &operation);

   if(operation == 1){
   operation = (num1 + num2) / 2;
    }
   
   else if(operation == 2 && num1 > num2){
    operation = num1 - num2;
   }
   else if(operation == 2 && num1 < num2){
    operation = num2 - num1;
   }
    
  else if(operation == 3){
    operation = num1 * num2;
   }

  else if(operation == 4 && num2 == 0){
    printf("Operation not available!");
    
    return 0;
   }
   else if(operation == 4 && num2 != 0){
       operation = num1 / num2;
   }
   
    printf("The result of the operation is: %.2f", operation);

}