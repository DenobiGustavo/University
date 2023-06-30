#include <stdio.h>

int main()
{
    int quantidade_produto, produto;
    float gasto, desconto;

    printf("Qual produto voce comprou?: ");
    scanf("%d", &produto);
    
   if(produto > 4){
       printf("Produto indisponivel");
       
       return 0;
    }
    
    printf("Quantos voce comprou?: ");
    scanf("%d", &quantidade_produto);

    switch (produto)
    {
    case 1 :
    produto = 5.3;
    break;

    case 2 :
    produto = 6;
    break;

    case 3 :
    produto = 3.2;
    break;

    case 4 :
    produto = 2.5;
    break;
    }

    gasto = quantidade_produto * produto;

    desconto = gasto - (gasto*15/100);

    if(quantidade_produto > 15 || gasto >= 40){
        printf("Voce deve pagar %.2f reais", desconto);
    }
    else if(quantidade_produto < 15 && gasto < 40){
        printf("voce deve pagar %.2f reais", gasto);
    }
}