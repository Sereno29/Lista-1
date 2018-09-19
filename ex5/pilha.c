/* Código da aula adaptado para o problema */
#include "pilha.h"
#include <stdlib.h>
#include <string.h>

void cria_pilha(Pilha* p){
    p->topo = -1;
    for(int i = 0; i<TamPilha;i++){
      p->vet[i] = (elem)malloc(8*sizeof(char));
      if(p->vet[i]==NULL){
        for(int j = i;j>=0;j--)
          free(p->vet[j]);
        exit;
      }
    }
    return;
}

int push(Pilha* p, elem x){
    if (p->topo == TamPilha-1)
        return 1;
    p->topo++;
    strcpy(p->vet[p->topo],x);
    return 0;
}

int isEmpty(Pilha p) {
    return (p.topo == -1);
}

int pop(Pilha* p, elem x) {
    if (isEmpty(*p))
        return 1;
    strcpy(x,p->vet[p->topo]);
    p->topo--;
    return 0;
}

void desaloca(Pilha* p){
  for(int j = 0;j<TamPilha;j++)
    free(p->vet[j]);
  return;
}
