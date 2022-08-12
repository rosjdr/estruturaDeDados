#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_PILHA 100 // tamanho da pilha

struct pilha {
    int topo; //representa a posição do topo da pilha
    int elementos[TAMANHO_PILHA];
};

// verifica se a pilha está vazia
int pilha_vazia(struct pilha *p) {
    return (p->topo == -1);
}

//verifica se a pilha está cheia
int pilha_cheia(struct pilha *p) {
    return (p->topo == TAMANHO_PILHA - 1);
}

//inicia a pilha
void cria_pilha(struct pilha *p) {
    p->topo = -1;
}

//imprime a pilha
void imprime_pilha(struct pilha *p) {
    int i;
    for (i = p->topo; i >= 0; i--) {
        printf("%d\n", p->elementos[i]);
    }
    printf("\n");
}

// insere um elemento na pilha
void empilha(struct pilha *p, int elemento) {
    if (pilha_cheia(p)) {
        printf("Pilha cheia\n");
        return;
    }
    p->topo++;
    p->elementos[p->topo] = elemento;
}

// remove um elemento da pilha
int desempilha(struct pilha *p) {
    if (pilha_vazia(p)) {
        printf("Pilha vazia\n");
        return -1;
    }
    return p->elementos[p->topo--];
}

struct pilha p; // declaração da pilha

int main(){
    struct pilha p;
    cria_pilha(&p);
    empilha(&p, 1);
    empilha(&p, 2);
    empilha(&p, 3);
    empilha(&p, 4);
    imprime_pilha(&p);
    int x = desempilha(&p);
    printf("Desempilhado -> %d\n", x);
    imprime_pilha(&p);
}