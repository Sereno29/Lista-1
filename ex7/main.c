#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

/* Função que confere se a string é do tipo a(^n)b(^n)
    - marker_b impede que ao se começar a identificar caracteres 'b',
      possa-se ler novamente carcateres 'a'
    - aux só auxilia na chamada da função pop
    */
int checa_string(char* string){
  Pilha p;
  cria_pilha(&p);
  int i = 0,marker_b = 0;
  elem aux;
  while(string[i]!='\0'){
    switch(string[i]){
      case 'a':
        if(marker_b == 0)
          push(&p,string[i]);
        else
          return 0;
        break;
      case 'b':
        marker_b =1;
        if(pop(&p,&aux))
          return 0;
        break;
      default:
        return 0;
    }
    i++;
  }
  if(isEmpty(p))
    return 1;
  else
    return 0;
}

int main(int argc, char* argv[]){
  char string[80];
  printf("TESTE DE STRING A^(N)B^(N)\nInsira a string a ser verificada: ");
  scanf(" %s",string);
  if(checa_string(string))
    printf("\nA string fornecida é da forma a(^n)b(^n).\n");
  else
    printf("\nA string fornecida não é da forma a(^n)b(^n).\n");

  return 0;
}
