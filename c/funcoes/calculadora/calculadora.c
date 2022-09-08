#include <stdio.h>
#include <stdlib.h>

#define OPCAO_SAIR 5

//declaração de variáveis globais que pode ser acessada em todas as funções
int opcao; 
float valor1, valor2, resultado;

void mostrar_resultado(char sinal){
    printf("RESULTADO: %.2f %c %.2f = %.2f\n",valor1, sinal, valor2, resultado);
}

void ler_valores(){
    printf("DIGITE O VALOR 1: ");
    scanf("%f", &valor1);
    printf("DIGITE O VALOR 2: ");
    scanf("%f", &valor2);
}

void calcular(char operacao){
    if(operacao=='+') resultado=valor1+valor2;
    if(operacao=='-') resultado=valor1-valor2;
    if(operacao=='*') resultado=valor1*valor2;
    if(operacao=='/') resultado=valor1/valor2;
    mostrar_resultado(operacao);
}

void exibir_menu(){
    printf("MENU DE OPCOES\n");
    printf("1. Somar\n");
    printf("2. Subtrair\n");
    printf("3. Multiplicar\n");
    printf("4. Dividir\n");
    printf("5. Sair\n");
    printf("OPCAO: ");
}

int main()
{
    do{
        exibir_menu();
        scanf("%d", &opcao);
        if (opcao != OPCAO_SAIR) 
            ler_valores();
        switch(opcao){
            case 1:
                calcular('+');
                break;
            case 2:
                calcular('-');
                break;
            case 3:
                calcular('*');
                break;
            case 4:
                calcular('/');
                break;
        }
    } while (opcao != OPCAO_SAIR);
    return 0;
}