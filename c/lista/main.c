#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//programa principal com menu de opções para testar as funções da lista
int main() {
    Lista l;
    cria_lista(&l);
    int opcao;
    do {
        printf("1 - Inserir elemento\n");
        printf("2 - Remover elemento\n");
        printf("3 - Imprimir lista\n");
        printf("4 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Informe o elemento a ser inserido: ");
                int elem;
                scanf("%d", &elem);
                insere_lista(&l, elem);
                break;
            case 2:
                printf("Informe a posicao do elemento a ser removido: ");
                int pos;
                scanf("%d", &pos);
                remove_lista(&l, pos);
                break;
            case 3:
                imprime_lista(&l);
                break;
            case 4:
                break;
            default:
                printf("Opcao invalida\n");
        }
    } while (opcao != 4);
    return 0;
}