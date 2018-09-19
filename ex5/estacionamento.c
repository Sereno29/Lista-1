#include "estacionamento.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definição da struct estacionamento_ e com uma instância para o programa*/
struct estacionamento_{
  Pilha estacionados;
  Pilha retirados;
}e1;

/* Inicializando as pilhas da struct estacionamento */
void inicializa_parking(void){
  cria_pilha(&e1.estacionados);
  cria_pilha(&e1.retirados);
}

/* Função que insere carro no estacionamento */
int estaciona_carro(elem placa){
  return ( push(&e1.estacionados,placa) );
}

/* Função que faz o processo de retirar o carro com certa placa e retornar os
   carros em sua respectiva ordem.
    -elem x foi usado como uma variável auxiliar para retirar placas e comparar
     para ver se a placa era a do carro a ser retirado. E depois para colocar os
     carros na sua ordem original. */
int retira_carro(elem placa){
  elem x = (elem)malloc(8*sizeof(char));
  if(!isEmpty(e1.estacionados)){
    while(!pop(&e1.estacionados,x)){
      if(strcmp(x,placa)==0){
        mostrar_situacao();
        break;
      }else{
        if (push(&e1.retirados,x)){
          free(x);
          return 1;
        }
      }
      mostrar_situacao();
    }
    while(!pop(&e1.retirados,x)){
      if(push(&e1.estacionados,x)){
        free(x);
        return 1;
      }
      mostrar_situacao();
    }
    free(x);
    return 0;
  }
  free(x);
  return 1;
}

/* Mostra a situação dos carros estacionados e dos que estão sendo realocados
para a saída de um carro no caso de uma chamada da função retira_carro */
void mostrar_situacao(void){
  printf("\nCarros Estacionados:\t");
  if(e1.estacionados.topo != -1){
    for(int i = 0; i <= e1.estacionados.topo;i++)
      printf(" %s\t", e1.estacionados.vet[i]);
  }else
    printf(" Pilha vazia" );

  printf("\nCarros Realocados:\t");
  if(e1.retirados.topo != -1){
    for(int i = 0; i <= e1.retirados.topo;i++)
      printf(" %s\t", e1.retirados.vet[i] );
  }else
    printf(" Pilha vazia" );

    printf("\n********************************************\n");
    return;
}

/* Desaloca a memória das duas pilhas usadas no estacionamento */
void finaliza_parking(void){
  desaloca(&e1.estacionados);
  desaloca(&e1.retirados);
  return;
}
