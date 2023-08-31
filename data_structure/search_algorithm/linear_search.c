int busca_linear(int *V, int N, int elem){

  int i;
  for(i=0; i<N; i++){
    if(elem==v[i]){
      return i;
    }
  return -1;
}

//Complexidade

//O(1) = melhor caso(primeiro elemento)
//O(n) = pior caso(ultimo elemento)
//O(n/2) = caso medio

int busca_sequencial_ordenadas(int *V, int N, int elem){

int i;
for(i=0; i<N; i++){
  if(elem==v[i]){
    return i;
}

else if(elem < V[i]){
  return -1;
}

return -1;
}

//Complexidade

//O(1) = melhor caso(primeiro elemento)
//O(n) = pior caso(ultimo elemento)
//O(n/2) = caso medio

int busca_binaria(int *V, int N, int elem){

  int i, inicio, meio, final;
  inicio = 0;
  final = N - 1;

  while(inicio <= final){
    meio = (inicio + final) / 2;

    if(elem < V[meio]){
      final = meio - 1;
    }

    else if(elem > V[meio]){

      inicio = meio + 1;
    }

    else{
      return meio;
    }
  }
  return -1;
}

//Complexidade 
//O(1), melhor caso
//O(log2N), pior caso, o elemento não existe
//O(log2N), caso medio...

typedef struct aluno Aluno;

int busca_por_matricula(Aluno *V, int N, int elem){

int i;
for(i=0; i<N; i++){
  if(elem == V[i].matricula){
    return i;
  }
  return -1;
}
}

int busca_por_nome(Aluno *V, int N, int elem){
int i;
for(i=0;i<N;i++){
  if(strcmp(elem, V[i].nome) == 0){
    return i;
  }
}
return -1;
}

//qual a complexidade?

//o que é chave..
