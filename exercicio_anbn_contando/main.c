#include "palavra.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  char string[80];
  printf("TESTE DE STRING A^(N)B^(N)\nInsira a string a ser verificada: ");
  scanf("%s",string);
  if(checa_string(string))
    printf("\nA string fornecida é da forma anbn.\n");
  else
    printf("\nA string fornecida não é da forma anbn.\n");

  return 0;
}
