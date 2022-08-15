//estrutura de lista usando vetor
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10

struct lista{
    int elementos[TAMANHO];
    int primeiro;
    int ultimo;
};

typedef struct lista Lista;

int lista_vazia(Lista *l);
int lista_cheia(Lista *l);
void cria_lista(Lista *l);
void insere_lista(Lista *l, int elem);
int remove_lista(Lista *l, int pos);
void imprime_lista(Lista *l);