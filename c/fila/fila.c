#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

//verifica se a fila está vazia
int fila_vazia(Fila *f){
    return f->fim == -1;
}

//verifica se a fila está cheia
int fila_cheia(Fila *f){
    return f->fim == TAM - 1;
}

//insere um elemento no final da fila
void fila_enfileira(Fila *f, int v){
    if(fila_cheia(f)){
        printf("Fila cheia!\n");
        return;
    }
    f->fim++;
    f->dados[f->fim] = v;
}

//remove um elemento do início da fila
int fila_desenfileira(Fila *f){
    if(fila_vazia(f)){
        printf("Fila vazia!\n");
        return -1;
    }
    int v = f->dados[0];
    for(int i = 0; i < f->fim; i++){
        f->dados[i] = f->dados[i+1];
    }
    f->fim--;
    return v;
}

//imprime os elementos da fila
void fila_imprime(Fila *f){
    int i;
    if(fila_vazia(f)){
        printf("Fila vazia!\n");
        return;
    }
    for(i = 0; i <= f->fim; i++){
        printf("%d ", f->dados[i]);
    }
    printf("\n");
}

//cria uma fila vazia
Fila *fila_cria(){
    Fila *f = (Fila *) malloc(sizeof(Fila));
    f->fim = -1;
    return f;
}

//libera a fila
void fila_libera(Fila *f){
    free(f);
}