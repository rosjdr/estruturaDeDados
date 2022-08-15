#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

//programa principal com menu de opções para as operações de fila
int main(){
    Fila *f = fila_cria();
    int opcao, v;
    do{
        printf("1 - Enfileirar\n");
        printf("2 - Desenfileirar\n");
        printf("3 - Imprimir\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Valor: ");
                scanf("%d", &v);
                fila_enfileira(f, v);
                break;
            case 2:
                v = fila_desenfileira(f);
                printf("%d\n", v);
                break;
            case 3:
                fila_imprime(f);
                break;
            case 0:
                break;
            default:
                printf("Opção inválida!\n");
        }
    }while(opcao != 0);
    fila_libera(f);
    return 0;
}