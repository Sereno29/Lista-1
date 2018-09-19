#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  // Criando pilhas
  Pilha A,B,C;
  cria_pilha(&A);
  cria_pilha(&B);
  cria_pilha(&C);

  // Variáveis auxiliares
  elem x =4;
  elem* y = NULL;

  // Setando situação inicial e mostrando
  while(x--)
    empilha(&A,x);
  mostrar_situacao(&A,&B,&C);

  // Resolução do problema
  y = desempilha(&A);
  empilha(&C,*y);
  mostrar_situacao(&A,&B,&C);

  y = desempilha(&A);
  empilha(&B,*y);
  mostrar_situacao(&A,&B,&C);

  y = desempilha(&C);
  empilha(&B,*y);
  mostrar_situacao(&A,&B,&C);

  y = desempilha(&A);
  empilha(&C,*y);
  mostrar_situacao(&A,&B,&C);

  y = desempilha(&B);
  empilha(&A,*y);
  mostrar_situacao(&A,&B,&C);

  y = desempilha(&B);
  empilha(&C,*y);
  mostrar_situacao(&A,&B,&C);

  y = desempilha(&A);
  empilha(&C,*y);
  mostrar_situacao(&A,&B,&C);

  return 0;
}
