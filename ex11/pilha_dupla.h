#include "pilha.h"
typedef struct pilha_dupla{
  Pilha A;
  Pilha B;
  elem vet[TamPilha];
  int qtd;
}PilhaDupla;
void cria_pilha_dupla(PilhaDupla *p2);
int empilha_A(PilhaDupla *p2, elem *x);
int desempilha_A(PilhaDupla *p2, elem *x);
int empilha_B(PilhaDupla *p2, elem *x);
int desempilha_B(PilhaDupla *p2, elem *x);
void mostrar_pilhas(PilhaDupla *p2);
