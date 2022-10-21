#include <stdio.h>
#include <string.h>

typedef struct t{
    int codigo;
    char cargo[50];
    double salario;
} tabela;

int main(){
    int opcao, codigo;

    tabela lista[5];
    lista[0].codigo = 1;
    strcpy(lista[0].cargo,"Analista de Salarios");
    lista[0].salario = 9.0;
    lista[1].codigo = 2;
    strcpy(lista[1].cargo,"Auxiliar de Contabilidade");
    lista[1].salario = 6.25;
    lista[2].codigo = 3;
    strcpy(lista[2].cargo,"Chefe de Cobranca");
    lista[2].salario = 8.04;
    lista[3].codigo = 4;
    strcpy(lista[3].cargo,"Chefe de Expedicao");
    lista[3].salario = 8.58;
    lista[4].codigo = 5;
    strcpy(lista[4].cargo,"Contador");
    lista[4].salario = 15.6;

    do{
        printf("\n=== MENU ===\n");
        printf("1. Consultar salario\n");
        printf("2. Sair\n\n");
        printf("OPCAO: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:            
            printf("INFORME O CODIGO: ");
            scanf("%d", &codigo);
            if (codigo >= 1 && codigo <= 5){
                printf("%d \t %s - %.2f\n",lista[codigo-1].codigo,lista[codigo-1].cargo,lista[codigo-1].salario);
            } else {
                printf("Cargo inexistente\n");
            }
        case 2:
            break;
        
        default:
            printf("ERRO: OPCAO INVALIDA!\n");
        }
    } while (opcao != 2);

    return 0;
}