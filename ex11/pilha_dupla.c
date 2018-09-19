#include "pilha_dupla.h"
#include <stdio.h>

// Função que inicializa os valores da pilha dupla
void cria_pilha_dupla(PilhaDupla *p2){
  cria_pilha(&p2->A);
  cria_pilha(&p2->B);
  p2->qtd = 0;
}

// Função a qual faz todas as comparações na
// procura pela posição a qual o próximo elemento
// a ser empilhado deve ser colocado
int repetition(int *topo_menor, int *topo_maior, int *positions_menor, int *positions_maior, int *qtd){
  int marker1,marker2,k;
  marker1 = marker2 = 0;
  for(int i = 0; i <= *topo_menor;i++){
    if(i != positions_menor[i]){
      for(int l = 0;l <= i;l++){
        if(i == positions_menor[l])
          marker1 = 1;
      }
      for(int l=0;l <= *topo_maior;l++){
        if(i == positions_maior[l])
          marker2 = 1;
      }
      if(marker1 == 0 && marker2==0)
        return i;
    }
    else
      continue;
    marker1 = marker2 = 0;
  }

  marker1 = marker2 = 0;
  for(int i = *topo_menor+1; i <= *topo_maior;i++){
    if(i != positions_maior[i]){
      for(int l = 0;l <= *topo_menor;l++){
        if(i == positions_menor[l])
          marker1 = 1;
      }
      for(int l = 0;l <= *topo_maior;l++){
        if(i == positions_maior[l])
          marker2 = 1;
      }
      if(marker1 == 0 && marker2==0)
        return i;
    }
    else
      continue;
    marker1 = marker2 = 0;
  }

  return *qtd;
}

// Função a qual delimita os casos de busca de posição e retorna
// a posição no vetor da pilha dupla a ser usada para empilhar
int buscar_posicao(Pilha *A,Pilha *B,int *qtd){
  int posicao;
  if(!isEmpty(*A) && !isEmpty(*B)){
    if(A->topo >= B->topo){
      posicao = repetition(&B->topo,&A->topo,B->positions,A->positions,qtd);
      return posicao;
      }else{
      posicao = repetition(&A->topo,&B->topo,A->positions,B->positions,qtd);
      return posicao;
      }
  }else{
    if(isEmpty(*A))
      return B->topo+1;
    if(isEmpty(*B))
      return A->topo+1;
  }
}

// Empilhar na pilha A
int empilha_A(PilhaDupla *p2, elem *x){
  if (p2->qtd == TamPilha)
    return 1;
  int i = buscar_posicao(&p2->A,&p2->B,&p2->qtd);
  p2->qtd++;
  p2->vet[i] = *x;
  push(&p2->A,i);
  return 0;
}

// Desempilhar da pilha A
int desempilha_A(PilhaDupla *p2, elem *x){
  if (isEmpty(p2->A))
      return 1;
  pop(&p2->A,x);
  *x = p2->vet[*x];
  p2->qtd--;
  return 0;
}

// Empilhar na pilha B
int empilha_B(PilhaDupla *p2, elem *x){
  if (p2->qtd == TamPilha)
    return 1;
  int i = buscar_posicao(&p2->A,&p2->B,&p2->qtd);
  p2->qtd++;
  p2->vet[i] = *x;
  push(&p2->B,i);
  return 0;
}

// Desempilha na pilha B
int desempilha_B(PilhaDupla *p2, elem *x){
  if (isEmpty(p2->B))
      return 1;
  pop(&p2->B,x);
  *x = p2->vet[*x];
  p2->qtd--;
  return 0;
}

// Mostrar os elementos e posições na pilha dupla de cada pilha
void mostrar_pilhas(PilhaDupla *p2){
  printf("Pilha A: ");
  if(!isEmpty(p2->A)){
    for(int i=0; i<=p2->A.topo;i++){
      printf("%d(posição %d)\t",p2->vet[p2->A.positions[i]],p2->A.positions[i]);
    }
  }
  else
    printf("Pilha vazia");


  printf("\nPilha B: ");
  if(!isEmpty(p2->B)){
    for(int i=0; i<=p2->B.topo;i++){
      printf("%d(posição %d)\t",p2->vet[p2->B.positions[i]],p2->B.positions[i]);
    }
  }
  else
    printf("Pilha vazia");

  printf("\n*******************************\n\n");
}
