#include <stdio.h>
#include <stdlib.h>

//implementação do tipo de dados fila em C
#define TAM 10

struct fila{
    int dados[TAM];
    int fim;
};

typedef struct fila Fila;

int fila_vazia(Fila *f); //verifica se a fila está vazia
int fila_cheia(Fila *f); //verifica se a fila está cheia
void fila_enfileira(Fila *f, int v); //insere um elemento no final da fila
int fila_desenfileira(Fila *f); //remove um elemento do início da fila
void fila_imprime(Fila *f); //imprime os elementos da fila
Fila *fila_cria(); //cria uma fila vazia
void fila_libera(Fila *f); //libera a fila