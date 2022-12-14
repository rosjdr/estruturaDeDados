#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void inicializa_vetor(int *vetor, int modo);
void imprime_vetor(int *vetor);
void selectionSort(int *vetor, int modoExibicao);

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
    selectionSort(v,modo);
    printf("%s","Vetor ordenado: ");
    imprime_vetor(v);
    return 0;
}

void selectionSort(int *vetor, int modoExibicao){
    int ultimaPosicao = TAM-1;
    int iteracoes = 0, trocas = 0;
    for(int i=0; i<TAM-1;i++){
        int menor = i;
        for(int j=i+1; j<TAM; j++){
            if(vetor[j] < vetor[menor]){
                menor = j;
            }
            iteracoes++;
        }
        if(menor != i){
            int aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
            if (modoExibicao){
                printf("PASSAGEM: %d [%d<->%d] -> ", i, i, menor);
                imprime_vetor(vetor);
            }
            trocas++;
        }
    }
    if (modoExibicao){
        printf("\nITERACOES: %d\n", iteracoes);
        printf("TROCAS   : %d\n", trocas);
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

