#include "circulo.h"
#include <stdlib.h>
#define PI 3.14159

/* Definição da struct circulo_ */
struct circulo_{
  PONTO* ponto_c;
  float raio;
};

/* Função que aloca memória para uma estrutura CIRCULO e para a estrutura PONTO
que é um campo de CIRCULO e seta os valores do CIRCULO. Esta função também
checa por erros de alocação. */
CIRCULO* circulo_criar(float x, float y, float raio, int* erro){
  CIRCULO* circle;
  circle = (CIRCULO*)malloc(sizeof(CIRCULO));
  if( circle!= NULL ){
    circle->raio = raio;
    circle->ponto_c = ponto_criar(x,y,erro);
  }
  else
    *erro =1;
  return  circle;
}

/* Função que calcula a área do círculo */
float circulo_area(CIRCULO* circulo){
  return PI * circulo->raio * circulo->raio;
}

/*Função que checa se o ponto está dentro do círculo. 1 para verdadeiro e 0 para
 falso. Usou-se a função de distância entre pontos do ponto.c para tornar a
 solução do problema mais geral e podendo ser utilizada em outras aplicações.*/
int ponto_dentro_circulo(PONTO* p, CIRCULO* c){
  return (distancia_pontos(p,c->ponto_c) < c->raio);
}


/* Função que desaloca a memória de um círculo */
void circulo_apagar(CIRCULO* circulo){
  ponto_apagar(circulo->ponto_c);
  free(circulo);
}

/* A operação para ver se o ponto está dentro
do circulo é feita por meio da distância
entre o ponto e o centro do círculo e comparando
com o raio do círculo */
