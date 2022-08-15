#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//verifica se a lista é vazia
int lista_vazia(Lista *l) {
    return l->primeiro == 0 && l->ultimo == 0;
}

//verifica se a lista está cheia
int lista_cheia(Lista *l) {
    return l->ultimo == TAMANHO-1;
}

//cria uma lista vazia
void cria_lista(Lista *l) {
    l->primeiro = 0;
    l->ultimo = l->primeiro;
}

//insere um elemento no final da lista
void insere_lista(Lista *l, int elem) {
    if (lista_cheia(l)) {
        printf("Lista cheia\n");
        return;
    }
    l->elementos[l->ultimo] = elem;
    l->ultimo++;
}

//remove o elemento do de posicao da lista
int remove_lista(Lista *l, int pos) {
    if (lista_vazia(l)) {
        printf("Lista vazia\n");
        return -1;
    }
    if (pos < 0 || pos >= l->ultimo) {
        printf("Posicao invalida\n");
        return -1;
    }
    int v = l->elementos[pos];
    for(int i = pos; i < l->ultimo; i++) {
        l->elementos[i] = l->elementos[i+1];
    }
    l->ultimo--;
}

//imprime a lista
void imprime_lista(Lista *l) {
    if (lista_vazia(l)) {
        printf("Lista vazia\n");
        return;
    }
    for(int i = 0; i < l->ultimo; i++) {
        printf("%d ", l->elementos[i]);
    }
    printf("\n");
}