#include <stdio.h>
#include <stdlib.h>

int main(){

    struct vendedor{             //mudei

    int id;
    int produto_vendido;
    
    };

    struct vendedor *v;

    int i, j, mat[11][61], identificacao, produto = 1, quantidade_produtos, maior_vendedor = 0, produto_menos_vendido = 50, vet_produtos[61], vet_vendedor[11], maior_venda = 0;

    float total_vendas = 0, vet_comissao[11], comissao = 0, valor = 1, valor_compra = 0, vet[61], lucro_vendedor1 = 0, lucro_vendedor2 = 0, lucro_vendedor3 = 0, lucro_vendedor4 = 0, lucro_vendedor5 = 0, lucro_vendedor6 = 0, lucro_vendedor7 = 0, lucro_vendedor8 = 0, lucro_vendedor9 = 0, lucro_vendedor10 = 0;
    
    
    for(i = 0; i < 10; i++){
        for(j = 0; j < 60; j++){

         mat[i][j] = 0;

        }
    }

    for(i = 0; i < 10; i++){

        vet_vendedor[i] = 0;

    }

    for(j = 0; j < 60; j++){

        vet_produtos[j] = 0;

    }

    v = (struct vendedor *) malloc(sizeof(struct vendedor));    //mudei
    
    for(i = 1; i < 60; i++){
        
        printf("PRODUTO %d: R$%.2f\n", i, valor);

        valor = valor + 0.80;

    }

    valor = 1;

    for(j = 0; j < 60; j++){

        vet[j] = valor;
        valor = valor + 0.80;

    }
  
    do{

        valor_compra = 0;
        i = 0;
        
        printf("\nINFORME SEU NUMERO DE IDENTIFICAÇAO (selecione 0 para encerrar): ");
        scanf("%d", &v->id);
     
        if(v->id == 0){

        printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

        break;

        }

        printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

        v->produto_vendido = -1; // acrescentei KKKKKKKKKKKKKKKKKKKKKKKKKKK
    
        while(v->produto_vendido != 0){
      
        printf("\nINFORME O PRODUTO VENDIDO (selecione 0 para encerrar): ");
        scanf("%d", &v->produto_vendido);
       
        if(v->produto_vendido == 0){
        
        printf("\nO VALOR TOTAL DA COMPRA FOI DE: %.2f", valor_compra);

        printf("\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");    

        v->produto_vendido = -1;

            break;

        }

        printf("\nINFORME A QUANTIDADE VENDIDA DO PRODUTO: ");
        scanf("%d", &quantidade_produtos);
        
        mat[v->id - 1][v->produto_vendido - 1] += quantidade_produtos;

        vet_produtos[v->produto_vendido - 1] = quantidade_produtos;

        valor_compra = valor_compra + quantidade_produtos * vet[v->produto_vendido - 1];

        vet_vendedor[v->id - 1] = quantidade_produtos * vet[v->produto_vendido - 1];

        }

    }while(v->id != 0);
        
        for(j = 0; j < 60; j++){

            lucro_vendedor1 = lucro_vendedor1 + (mat[0][j] * vet[j]);

            lucro_vendedor2 = lucro_vendedor2 + (mat[1][j] * vet[j]);

            lucro_vendedor3 = lucro_vendedor3 + (mat[2][j] * vet[j]);

            lucro_vendedor4 = lucro_vendedor4 + (mat[3][j] * vet[j]);

            lucro_vendedor5 = lucro_vendedor5 + (mat[4][j] * vet[j]);

            lucro_vendedor6 = lucro_vendedor6 + (mat[5][j] * vet[j]);

            lucro_vendedor7 = lucro_vendedor7 + (mat[6][j] * vet[j]);

            lucro_vendedor8 = lucro_vendedor8 + (mat[7][j] * vet[j]);

            lucro_vendedor9 = lucro_vendedor9 + (mat[8][j] * vet[j]);

            lucro_vendedor10 = lucro_vendedor10 + (mat[9][j] * vet[j]);
            
        }

        printf("\n\nO TOTAL DE VENDA EFETUADAS (em reais) PELO VENDEDOR 1 FOI DE %.2f\n", lucro_vendedor1);
        printf("\nO TOTAL DE VENDA EFETUADAS (em reais) PELO VENDEDOR 2 FOI DE %.2f\n", lucro_vendedor2);
        printf("\nO TOTAL DE VENDA EFETUADAS (em reais) PELO VENDEDOR 3 FOI DE %.2f\n", lucro_vendedor3);
        printf("\nO TOTAL DE VENDA EFETUADAS (em reais) PELO VENDEDOR 4 FOI DE %.2f\n", lucro_vendedor4);
        printf("\nO TOTAL DE VENDA EFETUADAS (em reais) PELO VENDEDOR 5 FOI DE %.2f\n", lucro_vendedor5);
        printf("\nO TOTAL DE VENDA EFETUADAS (em reais) PELO VENDEDOR 6 FOI DE %.2f\n", lucro_vendedor6);
        printf("\nO TOTAL DE VENDA EFETUADAS (em reais) PELO VENDEDOR 7 FOI DE %.2f\n", lucro_vendedor7);
        printf("\nO TOTAL DE VENDA EFETUADAS (em reais) PELO VENDEDOR 8 FOI DE %.2f\n", lucro_vendedor8);
        printf("\nO TOTAL DE VENDA EFETUADAS (em reais) PELO VENDEDOR 9 FOI DE %.2f\n", lucro_vendedor9);
        printf("\nO TOTAL DE VENDA EFETUADAS (em reais) PELO VENDEDOR 10 FOI DE %.2f\n\n", lucro_vendedor10);
        
        printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

        total_vendas = lucro_vendedor1 + lucro_vendedor2 + lucro_vendedor3 + lucro_vendedor4 + lucro_vendedor5 + lucro_vendedor6 + lucro_vendedor7 + lucro_vendedor8 + lucro_vendedor9 + lucro_vendedor10;
       
        printf("\n\nO LUCRO TOTAL OBTIDO (em reais) FOI DE R$%.2f", total_vendas);   
       
        printf("\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
        
        printf("\n\nO TOTAL DE COMISSÃO DE CADA VENDEDOR FOI DE: ");

        printf("\n\nVENDEDOR 1 R$%.2f", lucro_vendedor1 * 0.07);
        printf("\n\nVENDEDOR 2 R$%.2f", lucro_vendedor2 * 0.07);
        printf("\n\nVENDEDOR 3 R$%.2f", lucro_vendedor3 * 0.07);
        printf("\n\nVENDEDOR 4 R$%.2f", lucro_vendedor4 * 0.07);
        printf("\n\nVENDEDOR 5 R$%.2f", lucro_vendedor5 * 0.07);
        printf("\n\nVENDEDOR 6 R$%.2f", lucro_vendedor6 * 0.07);
        printf("\n\nVENDEDOR 7 R$%.2f", lucro_vendedor7 * 0.07);
        printf("\n\nVENDEDOR 8 R$%.2f", lucro_vendedor8 * 0.07);
        printf("\n\nVENDEDOR 9 R$%.2f", lucro_vendedor9 * 0.07);
        printf("\n\nVENDEDOR 10 R$%.2f", lucro_vendedor10 * 0.07);

        printf("\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
    
        for(j = 0; j < 60; j++){

            if(vet_produtos[j] == 0){

                printf("O PRODUTO %d TEVE ZERO VENDAS\n", j + 1);
            }   
        }

        printf("\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

         for(j = 0; j < 60; j++){

            printf("O PRODUTO %d TEVE %d VENDA(s)\n", j + 1, vet_produtos[j]);

    }

        printf("\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

         for(j = 0; j < 10; j++){
          
            if(vet_vendedor[j] > maior_vendedor){
                
                maior_vendedor = j + 1;

            }
    }

            printf("O MAIOR VENDEDOR FOI O FUNCIONÁRIO %d", maior_vendedor);

            printf("\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

            printf("\n\n=============== EXPEDIÊNTE FINALIZADO ===============\n\n");

    return 0;
}