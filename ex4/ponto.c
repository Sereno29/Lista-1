#include "ponto.h"
#include <stdlib.h>
#include <math.h>

/* Definição da struct ponto_ */
struct ponto_{
  float x;
  float y;
};

/* Função que aloca memória para a criação de um PONTO */
PONTO* ponto_criar (float x, float y, int* erro){
  PONTO* p;
  p = (PONTO*) malloc( sizeof(PONTO) );
  if(p != NULL){
    p->x = x;
    p->y = y;
    *erro = 0;
  }
  else
    *erro = 1;
  return  p;
}

/* Função que calcula a distância entre 2 pontos */
float distancia_pontos(PONTO* ponto1 , PONTO* ponto2){
  return sqrt( pow(ponto1->x-ponto2->x,2) + pow(ponto1->y - ponto2->y,2) );
}

/* Função que desaloca a memória do PONTO criado */
void ponto_apagar(PONTO* p){
  free(p);
}
