#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Função que faz os cálculos quando a pilha possui 2 operandos(números).*/
char conta(Pilha* p,int* erro,int *marker){
  /* Variáveis auxiliares */
  int a,b;
  char x;
  /* Transformação dos caracteres em seus respectivos valores inteiros e cálculos */
  if(!pop(p,&x))
    b = x-'0';
  else
    *erro = 1;
  if(*marker == 0){
    if(!pop(p,&x))
      a = x-'0';
      else
        *erro = 1;
  }
  else{
    if(!pop(p,&x))
      a = x;
    else
      *erro = 1;
  }

  if(pop(p,&x))
    *erro = 1;
  else{
    switch (x) {
      case '*':
        x = a*b;
        break;
      case '+':
        x = a+b;
        break;
      case '/':
        x = a/b;
        break;
      case '-':
        x = a-b;
        break;
    }
  }
  /* O marker serve para que depois do primeiro cálculo não precisemos ter mais
  a necessidade de somar '0'. Dessa maneira aumentando o range de resultados
  possíveis. */
  if(*marker == 0)
    *marker = 1;
    printf("%d\n",*erro );
  /* Resultado é transformado em um caractere de acordo com a tabela ASCII */
    return x;
}

int main(int argc, char* argv[]){
  // Criando Pilha
  Pilha p;
  cria_pilha(&p);
  // Obtendo string do usuário
  elem not[25];
  printf("NOTAÇÂO POLONESA******\nInsira uma string válida para a notação polonesa: ");
  scanf("%s",not);
  // Procedimento de empilhar caracteres da string lida e fazer cálculos
  int operandos = 0, i=0,marker=0,erro=0;
  char x;
  while(1){

    for(;operandos != 2 ; i++){
      if(not[i] == '\0'){
        i = pop(&p,&x);
        printf("\nResultado: %d\n",x);
        return 0;
      }
      if(not[i]!= '*' && not[i]!= '/' && not[i]!= '+' && not[i]!= '-' )
        operandos++;
      push(&p,not[i]);
    }

    operandos-=2;
    x = conta(&p,&erro,&marker);
    if(erro==1){
      printf("Um erro ocorreu! Encerrando programa!\n");
      return 1;
    }
    push(&p,x);
    operandos++;
  }
  return 0;
}

/* OBS: Este programa somente cumprirá o seu objetivo caso o usuário insira
        uma expressão em notação polonesa prefixa que seja válida. Além disso,
        por estarmos usando uma pilha de char os valores de resultado estão
        limitados para resultados obtidos com 1 byte = char (-128 a 127). A fim
        de melhorar a solução, a pilha deveria aceitar valores inteiros e char
        como elementos, implementação esta que necessitaria de ponteiros
        genéricos (void).
        */
