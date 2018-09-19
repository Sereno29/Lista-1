#include "pilha.h"

void cria_pilha(Pilha* p){
    p->topo = -1;
    return;
}

int push(Pilha* p, elem x){
    if (p->topo == TamPilha-1)
        return 1;
    p->topo++;
    p->vet[p->topo] = x;
    return 0;
}

int isEmpty(Pilha p) {
    return p.topo == -1;
}

int pop(Pilha* p, elem* x) {
    if (isEmpty(*p))
        return 1;
    *x = p->vet[p->topo];
    p->topo--;
    return 0;
}

elem top(Pilha p, int* erro) {
    if (isEmpty(p)) {
        *erro = 1;
        return -1;
    }
    *erro = 0;
    return p.vet[p.topo];
}

void empty(Pilha* p) {
    cria_pilha(p);
    return;
}

int iguais(Pilha p1, Pilha p2) {
    if (p1.topo != p2.topo)
        return 0;
    else
        for (int i=0; i<p1.topo; i++) {
            if (p1.vet[i] != p2.vet[i])
                return 0;
        }
    return 1;
}

/*Checando se a plavara só tem anbn: primeiramente ler a string.
Fazer um for grande ao longo da string com strlen e colocar em uma pillha
os as e os bs na outra. Quando o caractere virar b, não pode voltar a ser b.*/
