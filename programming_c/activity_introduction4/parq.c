#include <stdio.h>

float conta_brinquedos (int y, float n)
{
    float brinq1, brinq2, brinq3;
    int count, idad1, idad2, idad3;

    count = 0;
    
    brinq1 = 150;
    idad1 = 12;
    
    brinq2 = 140;
    idad2 = 14;
    
    brinq3 = 170;
    idad3 = 16;

    if(brinq1 <= n && idad1 <= y){
        count++;
    }
    if(brinq2 <= n && idad2 <= y){
        count++;
    }
    if(brinq3 <= n && idad3 <= y){
        count++;
    }    
    
    return count;
}
    
int main()
{
    
    int y, quantidade_brinquedos;
    float n;

    printf("Digite sua altura: ");
    scanf("%f", &n);

    printf("Digite sua idade: ");
    scanf("%d", &y);

    quantidade_brinquedos = conta_brinquedos(n, y);
    
    printf("%d", quantidade_brinquedos);
    
}
