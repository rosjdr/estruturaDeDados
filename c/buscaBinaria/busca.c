#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void inicializa_vetor(int *vetor, int modo);
void imprime_vetor(int *vetor);
void isertionSort(int *vetor, int modoExibicao);
int buscaBinaria(int *vetor, int tamanho, int elemento);

int main(int argc, char *argv[]){
    int v[TAM];
    int modo, tipoGeracao;
    int e = 0;

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
    isertionSort(v,modo);
    printf("%s","Vetor ordenado: ");
    imprime_vetor(v);
    e = (rand() % TAM)+1;
    printf("Procurado: %d - Encontrado na posicao: %d\n", e, buscaBinaria(v,TAM,e));
    return 0;
}

int buscaBinaria(int *vetor, int tamanho, int elemento){
    int meio, inicio = 0, final = tamanho -1;
    while(inicio <= final){
        meio = (inicio + final) / 2;
        if (elemento < vetor[meio]){
            final = meio -1;
        } else {
            if(elemento > vetor[meio]){
                inicio = meio + 1;
            } else {
                return meio;
            }
        }
    }
    return -1;
}

void isertionSort(int *vetor, int modoExibicao){
    int iteracoes = 0, trocas = 0;
    for(int i=1; i<TAM;i++){ //tem que começar da segunda posição
        int atual = vetor[i];
        int j;
        for(j = i; j>0 && atual < vetor[j-1]; j--){
            vetor[j] = vetor[j-1];
            trocas++;
        }
        vetor[j] = atual;        
        if (modoExibicao && i!=j){
            printf("PASSAGEM: %d [%d->%d] -> ", i, i, j);
            imprime_vetor(vetor);
        }
        iteracoes++;
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

