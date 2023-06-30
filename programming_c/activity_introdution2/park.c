#include <stdio.h>

int main()
{
    int age, hight;
    int total = 0;

    printf("Write your age: ");
    scanf("%d", &age);

    printf("What's your hight?: ");
    scanf("%d", &hight);

    if(hight >= 150 && age >= 12){
        total++;
    }

    if(hight >= 140 && age >= 14){
        total++;
    }

    if(hight >= 170 && age >= 16){
        total++;
    }
    
    if(total >= 1){
    printf("You can go in %d amusements park toy, niceee!", total);
    }
    else{
        printf("Sorry, you can't go to amusements park toy");
    }

}