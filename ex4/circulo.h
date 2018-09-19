#ifndef CIRCULO_H
  #define CIRCULO_H
  #include "ponto.h"
  typedef struct circulo_ CIRCULO;
  CIRCULO* circulo_criar (float x, float y,float raio, int* erro);
  float circulo_area(CIRCULO* circulo);
  int ponto_dentro_circulo(PONTO* p, CIRCULO* c);
  void circulo_apagar(CIRCULO* circulo);
#endif
