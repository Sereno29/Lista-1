// ódigo de sala de aula reaproveitado
#define TamPilha 40
typedef int elem;
typedef struct pilha {
    elem positions[TamPilha];
    int topo;
} Pilha;
void cria_pilha(Pilha* p);
int push(Pilha* p, elem x);
int isEmpty(Pilha p);
int pop(Pilha* p, elem* x);
