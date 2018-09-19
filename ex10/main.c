#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
  // Criando pilha
  Pilha p;
  cria_pilha(&p);
  // Variáveis auxiliares
  char x;
  // Frase inicial
  elem frase[25] = "EAS*Y*QUE***ST***IO*N***";
  // Procedimento
  printf("\nResultado: ");
  for(int i = 0 ; frase[i] != '\0' ; i++){
    if(frase[i] == '*'){
      pop(&p,&x);
      printf("%c",x );
    }
    else
      push(&p,frase[i]);
  }
  printf("\n");
  return 0;
}
