#ifndef ESTACIONAMENTO_H
  #define ESTACIONAMENTO_H
  #include "pilha.h"
  void inicializa_parking(void);
  int estaciona_carro(elem placa);
  int retira_carro(elem placa);
  void finaliza_parking(void);
  void mostrar_situacao(void);
#endif
/* A implementação será feita por uma estrutura de dados que seja feita por
2 filas. Uma a original, a qual realmente os carros estão estacionados e a outra
para guardar a ordem dos carros realocados quando algum deles for sair.*/
