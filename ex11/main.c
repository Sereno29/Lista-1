//Teste para ver funcionamento do programa
#include "pilha_dupla.h"

int main(int argc, char* argv[]){
  PilhaDupla p2;
  cria_pilha_dupla(&p2);
  int aux;
  for(int i = 0 ; i<11 ; i++){
    if(i%2 ==0 ){
      empilha_A(&p2,&i);
      mostrar_pilhas(&p2);
    }
    if(i%2==1){
      empilha_B(&p2,&i);
      mostrar_pilhas(&p2);
    }
  }

  for(int i=0;i<3;i++){
    desempilha_B(&p2,&aux);
    mostrar_pilhas(&p2);
  }

  for(int i = 11;i<14;i++){
    empilha_A(&p2,&i);
    mostrar_pilhas(&p2);
  }

  return 0;
}

/* Nos últimos passos deste programa se vê que se usou a posição 9
   do vetor em vez da 7, uma vez que o *topo_maior neste caso era 6.
   Como corrigir sem errar em casos onde uma alteração levaria a um
   acesso inválido de vetores?*/
