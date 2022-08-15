#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

//verifica se a pilha está vazia
int pilha_vazia(Pilha *p){
    return p->topo == -1;
} 
//verifica se a pilha está cheia
int pilha_cheia(Pilha *p){
    return p->topo == TAM - 1;
}
//insere um elemento no final da pilha
void empilha(Pilha *p, int v){
    if(pilha_cheia(p)){
        printf("Pilha cheia!\n");
        return;
    }
    p->topo++;
    p->dados[p->topo] = v;
}
//remove um elemento do início da pilha
int desempilha(Pilha *p){
    if(pilha_vazia(p)){
        printf("Pilha vazia!\n");
        return -1;
    }
    int v = p->dados[p->topo];
    p->topo--;
    return v;
}
//imprime os elementos da pilha
void pilha_imprime(Pilha *p){
    int i;
    if(pilha_vazia(p)){
        printf("Pilha vazia!\n");
        return;
    }
    for(i = 0; i <= p->topo; i++){
        printf("%d ", p->dados[i]);
    }
    printf("\n");
}

//cria uma pilha vazia
Pilha *pilha_cria(){
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    p->topo = -1;
    return p;
}
//libera a pilha
void pilha_libera(Pilha *p){
    free(p);
}