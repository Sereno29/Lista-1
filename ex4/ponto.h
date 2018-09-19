#ifndef PONTO_H
  #define PONTO_H
  typedef struct ponto_ PONTO;
  PONTO* ponto_criar (float x, float y, int* erro);
  float distancia_pontos(PONTO* ponto1 , PONTO* ponto2);
  void ponto_apagar(PONTO* p);
#endif
