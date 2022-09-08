#include <stdio.h>
#include <stdlib.h>
#include "matematica/matematica.h"

#define OPCAO_SAIR 5

void ler_valores(float *x, float *y){
    printf("DIGITE O VALOR 1: ");
    scanf("%f", x);
    printf("DIGITE O VALOR 2: ");
    scanf("%f", y);
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
    int opcao; 
    float valor1, valor2, resultado;
    char sinal;
    do{
        exibir_menu();
        scanf("%d", &opcao);
        if (opcao != OPCAO_SAIR) 
            ler_valores(&valor1, &valor2);
        switch(opcao){
            case 1:
                sinal = '+';                
                break;
            case 2:
                sinal = '-';
                break;
            case 3:
                sinal = '*';
                break;
            case 4:
                sinal = '/';
                break;
        }
        if (opcao != OPCAO_SAIR) {
            resultado = calcular(sinal, valor1, valor2);
            mostrar_resultado(sinal, valor1, valor2, resultado);
        }
    } while (opcao != OPCAO_SAIR);
    return 0;
}