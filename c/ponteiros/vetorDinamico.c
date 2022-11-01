#include <stdio.h>
#include <stdlib.h>

int main(){

    int *p, *q = NULL;
    printf("Tamanho P: %ld\n", sizeof(p));
    p = (int *) malloc(sizeof(int));
    printf("Tamanho P: %ld\n", sizeof(p));
    printf("Tamanho Q: %ld\n", sizeof(q));
    // return 0;


    int tam = 0;
    printf("QUANTIDADE DE ELEMNTOS: ");
    scanf("%d", &tam);

    int v[1000];

    int *vetor = (int *) malloc(sizeof(int)*tam);
    printf("Tamanho V[1000]: %ld\n", sizeof v);
    printf("Tamanho Vetor de Ponteiro: %ld\n", (sizeof(int)*tam));

    //faz a leitura utilizando um ponteiro
    int *ptr = vetor;
    for(int i=0;i<tam;i++){
        scanf("%d", ptr++);
    }

    //faz a impressão utilizando o ponteiro
    ptr = vetor;
    for(int i=0;i<tam;i++){
        printf("vetor[%d]: %p -> %d \n", i, ptr, *ptr);
        ptr++;
    }    

    free(vetor);
    int x = 2, y = 5;
    printf("X: %p -> %d\n", &x, x);
    printf("Y: %p -> %d\n", &y, y);
    printf("X<Y: %d\n", &x < &y);

}