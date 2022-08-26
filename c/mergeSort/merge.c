#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TAM 10

void inicializa_vetor(int *vetor, int modo);
void imprime_vetor(int *vetor);
void mergeSort (int *vetor, int inicio, int fim);
void merge(int *vetor, int inicio, int meio, int fim);

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
    mergeSort(v,0,TAM-1);
    printf("%s","Vetor ordenado: ");
    imprime_vetor(v);
    return 0;
}

void mergeSort (int *vetor, int inicio, int fim){
    int meio;
    if (inicio < fim){
        meio = floor((inicio+fim)/2);
        mergeSort(vetor,inicio,meio);
        mergeSort(vetor,meio+1,fim);
        merge(vetor,inicio,meio,fim);
    }
}

void merge(int *vetor, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio+1;
    p1 = inicio;
    p2 = meio+1;
    temp = (int *) malloc(tamanho*sizeof(int));
    if(temp != NULL){
        for(int i=0;i<tamanho;i++){
            if(!fim1 && !fim2){
                if(vetor[p1] < vetor[p2])
                    temp[i]=vetor[p1++];
                else
                    temp[i]=vetor[p2++];
                
                if(p1>meio)
                    fim1=1;
                if(p2>fim)
                    fim2=1;
            } else {
                if(!fim1)
                    temp[i] = vetor[p1++];
                else
                    temp[i] = vetor[p2++];
            }
        }
        for(int j=0, k=inicio; j<tamanho; j++, k++)
            vetor[k]=temp[j];
    }
    free(temp);
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

