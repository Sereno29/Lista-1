/* Código da aula adaptado para o problema */
#define TamPilha 10
typedef char* elem;
typedef struct pilha {
    elem vet[TamPilha];
    int topo;
} Pilha;

void cria_pilha(Pilha* p);

int push(Pilha* p, elem x);

int isEmpty(Pilha p);

int pop(Pilha* p, elem x);

void desaloca(Pilha* p);
