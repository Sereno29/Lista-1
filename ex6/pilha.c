/* Código feito em aula reaproveitado */
#include "pilha.h"
#include <stdio.h>

void cria_pilha(Pilha* p){
    p->topo = -1;
    return;
}

void empilha(Pilha* p, elem x){
    if (p->topo == TamPilha-1)
        return;
    p->topo++;
    p->vet[p->topo] = x;
    return;
}


elem* desempilha(Pilha* p) {
    elem* x = &p->vet[p->topo];
    p->topo--;
    return x;
}

void mostrar_situacao(Pilha* A,Pilha* B,Pilha* C){
  printf("\nPilha A:\t");
  if(A->topo != -1){
    for(int i = 0; i <= A->topo;i++)
      printf(" %d\t", A->vet[i]);
  }else
    printf(" Pilha vazia" );

  printf("\nPilha B:\t");
  if(B->topo != -1){
    for(int i = 0; i <= B->topo;i++)
      printf(" %d\t", B->vet[i] );
  }else
    printf(" Pilha vazia" );

  printf("\nPilha C:\t");
  if(C->topo != -1){
    for(int i = 0; i <= C->topo;i++)
      printf(" %d\t", C->vet[i] );
  }else
    printf(" Pilha vazia" );

    printf("\n********************************************\n");
    return;
}


void esvaziar(Pilha* p) {
    cria_pilha(p);
    return;
}
