#include <stdio.h>

typedef struct lista Lista;

struct lista
{
  int info;
  Lista *prox;
};

void imprime_lista(Lista* lista){

  Lista* p;
  if(p == NULL){
    return 1;
  }
  else{
    printf("%d ", p->info);
    return imprime_lista(p->prox);
  }
}

Lista* buscar_lista(Lista* lista, int val){

  Lista* p;
  if(val == p->info){
    return p;
  }
  else{
    return buscar_lista(p->prox, val);
  }
  return NULL;
}






