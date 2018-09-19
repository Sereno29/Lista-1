/* Código feito em aula reaproveitado */
#define TamPilha 100
typedef char elem;
typedef struct pilha {
    elem vet[TamPilha];
    int topo;
} Pilha;

void cria_pilha(Pilha* p);

int push(Pilha* p, elem x);

int isEmpty(Pilha p);

int pop(Pilha* p, elem* x);
