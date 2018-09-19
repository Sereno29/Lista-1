// Código de sala de aula reaproveitado
#include "pilha.h"

void cria_pilha(Pilha* p){
    p->topo = -1;
    return;
}

int push(Pilha* p, elem x){
    if (p->topo == TamPilha-1)
        return 1;
    p->topo++;
    p->positions[p->topo] = x;
    return 0;
}

int isEmpty(Pilha p) {
    return (p.topo == -1);
}

int pop(Pilha* p, elem* x) {
    if (isEmpty(*p))
        return 1;
    *x = p->positions[p->topo];
    p->topo--;
    return 0;
}
