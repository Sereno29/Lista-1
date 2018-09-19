#include "circulo.h"
#include <stdio.h>
#include <stdlib.h>
/* Usou-se a função exit caso houvesse erro na criação de um ponto ou círculo */

int main(int argc, char* argv[]){
  float x,y,raio;
  int erro;
  PONTO* ponto;
  CIRCULO* circulo;

  // Setando o ponto
  printf("VERIFICAÇÃO: PONTO DENTRO DE CÍRCULO\n");
  printf("Criando Ponto:\nInsira a componente x (número real): ");
  scanf(" %f",&x );
  printf("Insira a componente y (número real): ");
  scanf(" %f",&y );
  ponto = ponto_criar(x,y,&erro);
  if(erro == 1){
    printf("Erro ao criar Ponto!\nPrograma será finalizado!");
    exit;
  }
  // Setando o circulo
  printf("Criando Círculo:\nInsira a componente x do centro do círculo (número real): ");
  scanf(" %f",&x );
  printf("Insira a componente y do centro do círculo (número real): ");
  scanf(" %f",&y );
  printf("Insira o raio do círculo (número real): ");
  scanf(" %f",&raio );
  circulo = circulo_criar(x,y,raio,&erro);
  if(erro == 1){
    printf("Erro ao criar Círculo!\nPrograma será finalizado!");
    exit;
  }

  // Checando se o ponto está dentro ou sobre o círculo
  if(ponto_dentro_circulo(ponto,circulo))
    printf("\nO ponto inserido está dentro do círculo. \n");
  else
    printf("O ponto inserido não está dentro do círculo. Ele está fora ou sobre o círculo.\n");

  //Desalocando a memória utilizada
  ponto_apagar(ponto);
  circulo_apagar(circulo);
  return 0;
}
