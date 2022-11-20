#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define QTDE_CARGOS 5
#define TAMANHO_NOME 50
#define OPCAO_SAIR 2
 
typedef struct {
    int   codigo;
    char  nome[TAMANHO_NOME];
    float salario;
} cargo;
 
void alimentaTabelaSalario(cargo *tab){
    tab[0].codigo = 1;
    strcpy(tab[0].nome, "Analista de Salarios");
    tab[0].salario = 9.0;
 
    tab[1].codigo = 2;
    strcpy(tab[1].nome, "Auxiliar de contabilidade");
    tab[1].salario = 6.25;
 
    tab[2].codigo = 3;
    strcpy(tab[2].nome, "Chefe de Cobranca");
    tab[2].salario = 8.04;
 
    tab[3].codigo = 4;
    strcpy(tab[3].nome, "Chefe de Expedicao");
    tab[3].salario = 8.58;
 
    tab[4].codigo = 5;
    strcpy(tab[4].nome, "Contador");
    tab[4].salario = 15.6;
}
 
void imprimirMenu(){
    printf("MENU\n");
    printf("1. Consultar Cargos\n");
    printf("%d. Sair\n", OPCAO_SAIR);
}
 
int lerInteiro(){
    int op;
    scanf("%d", &op);
    return op;
}
 
void imprimirTabela(cargo *tab){
    printf("=== TABELA===\nCargo\tSalario\n");
    for(int i=0; i < QTDE_CARGOS; i++){
        printf("%d\t%s\n",
           tab[i].codigo,
           tab[i].nome);
    }
}
 
void imprimeCargo(int cod, cargo *tab){
    if(cod<=QTDE_CARGOS){
        printf("Codigo: %d\nCargo: %s\nSalario:%.2f\n",
           tab[cod-1].codigo,
           tab[cod-1].nome,
           tab[cod-1].salario);
    } else {
        printf("Codigo inexistente\n\n");
    }
}
 
void tratarOpcao(int op, cargo *tab){
    int cod;
 
    switch(op){
        case 1:
            imprimirTabela(tab);
            printf("INFORME O CODIGO: ");
            cod = lerInteiro();
            imprimeCargo(cod, tab);
            break;
        case OPCAO_SAIR:
            break;
        default:
            printf("Opcao invalida!\n");
    }
 
}
 
int main()
{
    cargo tabela[QTDE_CARGOS];
    int opcao;
 
    alimentaTabelaSalario(tabela);
    do{
        imprimirMenu();
        opcao = lerInteiro();
        tratarOpcao(opcao, tabela);
    } while(opcao != OPCAO_SAIR);
    return 0;
}
