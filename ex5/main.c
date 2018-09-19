/* Programa teste para ver se o código dá certo */
#include "estacionamento.h"
#include <stdio.h>
#define num 6

int main(int argc, char* argv[]){
  inicializa_parking();
  elem placa[num] = {"CHA9368","FUC2156","FUI9963","VLW1029","SIM0387","NAO5319"};
  /* Outros exemplos de placa: "SIM0387","NAO5319","QUI7284","CAR4356","SOL2845" */

  /* Estaciona um certo de número carros de exemplo representado por num */
  for(int i = 0; i < num; i++){
    if( estaciona_carro(placa[i]) )
      printf("\nErro ao se inserir um carro no estacionamento\n");
    mostrar_situacao();
  }

  /* Mostra exemplo de retirada do segundo carro a entrar no estacionamento */
  printf("\n||||Retirando o 2º carro||||\n");
  if( retira_carro(placa[1]) )
    printf("Erro ao retirar o carro escolhido.\n");

  /* Desalocando a memória usada */
  finaliza_parking();
  return 0;
}
