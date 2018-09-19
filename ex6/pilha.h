/* Código feito em aula reaproveitado */

#define TamPilha 3
typedef int elem;

/* Struct pilha é declarada no pilha.h já que se queria
instaciar uma variável Pilha na main*/
typedef struct pilha {
    elem vet[TamPilha];
    int topo;
} Pilha;
void cria_pilha(Pilha* p);
void empilha(Pilha* p, elem x);
elem* desempilha(Pilha* p);
void mostrar_situacao(Pilha* A,Pilha* B,Pilha* C);
void esvaziar(Pilha* p);
