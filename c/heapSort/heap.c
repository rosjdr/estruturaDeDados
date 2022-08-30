#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TAM 10

void inicializa_vetor(int *vetor, int modo);
void imprime_vetor(int *vetor);
void criaHeap(int *v, int pai, int fim);
void heapSort(int *v, int n);

int main(int argc, char *argv[]){
    int v[TAM];
    int modo, tipoGeracao;

    /*
        argv[1] = modo de Exibição ativado... mostra as trocas realizadas
        argv[2] = tipo de vetor que será gerado (ver função inicializa_vetor)
    */
    if (argc > 1){
        modo = atoi(argv[1]);
        tipoGeracao = atoi(argv[2]);
    }

    srand((unsigned)time(NULL));

    inicializa_vetor(v,tipoGeracao);
    printf("%s","Vetor original: ");
    imprime_vetor(v);
    heapSort(v,TAM-1);
    printf("%s","Vetor ordenado: ");
    imprime_vetor(v);
    return 0;
}

void criaHeap(int *v, int pai, int fim){
    int aux = v[pai];
    int filho = 2 * pai + 1;
    while (filho <= fim){
        if(v[filho] < v[filho +1]) filho++;
        if (aux < v[filho]){
            v[pai] = v[filho];
            pai = filho;
            filho = 2 * pai + 1;
        } else {
            filho = fim + 1;
        }
    }
    v[pai] = aux;
}

void heapSort(int *v, int n){
    int i, aux;
    for(i = (n-1)/2; i >= 0; i--){
        criaHeap(v, i, n-1);
    }
    for(i = n-1; i >= 1; i--){
        aux = v[0];
        v[0]=v[i];
        v[i] = aux;
        criaHeap(v, 0, i-1);
    }
}

void inicializa_vetor(int *vetor, int modo){
    switch (modo) {
        case 1: //inicializa o vetor com elementos em ordem crescente
            for(int i=0; i<TAM; i++) 
                vetor[i] = i+1;
            break; 
        case 2: //inicializa o vetor com elementos em ordem decrescente
            for(int i=0; i<TAM; i++)
                vetor[i] = TAM - i;
            break;
        case 3: //inicializa o vetor com elementos aleatorios de 1 até TAM
            for(int i=0; i<TAM; i++)
                vetor[i] = (rand() % TAM)+1;
            break;
        default:
            break;
    }
    return;
}

void imprime_vetor(int *vetor){
    for(int i=0; i<TAM; i++){
        if(i<TAM-1) printf("%d - ",vetor[i]);
        else printf("%d\n",vetor[i]);
    }
    return;
}

