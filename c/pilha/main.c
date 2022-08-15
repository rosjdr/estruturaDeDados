#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

//programa principal com menu de opções para testar as funções da pilha
int main(){
    Pilha *p = pilha_cria();
    int opcao;
    do{
        printf("\n1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Imprimir\n");
        printf("4 - Sair\n");
        printf("Digite uma opção: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Digite um valor: ");
                int v;
                scanf("%d", &v);
                empilha(p, v);
                break;
            case 2:
                printf("Valor desempilhado: %d\n", desempilha(p));
                break;
            case 3:
                pilha_imprime(p);
                break;
            case 4:
                break;
            default:
                printf("Opção inválida!\n");
        }
    }while(opcao != 4);
    pilha_libera(p);
    return 0;
}