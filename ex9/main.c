#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
  /* Criando pilha */
  Pilha p;
  cria_pilha(&p);
  /* Recebendo string do usuário */
  char frase[100];
  printf("INVERTER A ORDEM DAS LETRAS DE CADA PALAVRA DE UMA FRASE******\n");
  printf("Insira uma frase: ");
  fgets(frase,100,stdin);
  printf("\n");

  /* Procedimento de impressão de cada palavra invertida*/
  int erro = 0;
  char x;
  for(int i = 0; ; i++){
    if(frase[i] != ' ' && frase[i]!='\n'){
      if(push(&p,frase[i]))
        erro = 1;
    }
    else{
      while(!pop(&p,&x))
        printf("%c",x);
      printf(" ");
    }
    if(frase[i]=='\n')
      break;
    if(erro==1)
      return 1;
  }
  printf("\n");
  return 0;
}

/* Não se soube se era para alterar a string com as palavras invertidas, então
   optou-se por simplismente imprimir as palacras invertidas, deixando a string
   original inalterada.*/
