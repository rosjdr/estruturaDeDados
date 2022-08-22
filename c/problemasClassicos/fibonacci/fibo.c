#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
    Seq: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...
    Exceto os dois primeiros termos da sequência, os outros são a soma dos dois anteriores
*/

//implementação da memoização em C
typedef struct memo
{
    int n;
    int resultado;
} Memo;


//calcula fibonacci de maneira recursiva
int fib_rec(int n, int *cont){
    printf("Chamada: %d: ", ++(*cont));
    if (n < 2) {
        printf("fib(%d) -> %d\n", n, n);
        return n;
    } else {
        printf("fib(%d) -> fib(%d) + fib(%d)\n", n, n-1, n-2);
        return fib_rec(n-1,cont) + fib_rec(n-2,cont);
    }
}

//calcula fibonacci de maneira iterativa
int fib_it(int n){
    int atual = 1, anterior = 0;
    int cont =0;
    if (n < 2) {
        return 1;
    } else {
        for(int i = 3;i<=n;i++){
            int aux = atual;
            atual+=anterior;
            anterior=aux;
        }
        return anterior+atual;
    }
}

int main() {
    int n = 0;
    int cont = 0;
    double tempo_gasto = 0.0;


    printf("%s", "INFORME O VALOR DE N: ");
    scanf("%d", &n);

    clock_t inicio = clock();
    printf("FIBONACCI %d = %d", n, fib_rec(n, &cont));
    clock_t fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %fs", tempo_gasto);
    printf("\n============ITERATIVO================\n");
    inicio = clock();
    printf("FIBONACCI %d = %d", n, fib_it(n));
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %fs", tempo_gasto);

}