#include <stdio.h>
#include <stdlib.h>

//implementação do tipo de dados pilha em C
#define TAM 10

struct pilha{
    int dados[TAM];
    int topo;
};

typedef struct pilha Pilha;

int pilha_vazia(Pilha *f); //verifica se a Pilha está vazia
int pilha_cheia(Pilha *f); //verifica se a Pilha está cheia
void empilha(Pilha *f, int v); //insere um elemento no final da Pilha
int desempilha(Pilha *f); //remove um elemento do início da Pilha
void pilha_imprime(Pilha *f); //imprime os elementos da Pilha
Pilha *pilha_cria(); //cria uma Pilha vazia
void pilha_libera(Pilha *f); //libera a Pilha