#include <stdio.h>
#include <stdlib.h>

int main(){

    float x, y, resultado;
    int opcao;

    do{
        printf("MENU DE OPCOES\n");
        printf("1. Somar\n");
        printf("2. Subtrair\n");
        printf("3. Multiplicar\n");
        printf("4. Dividir\n");
        printf("5. Sair\n");
        printf("OPCAO: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("DIGITE O VALOR 1: ");
                scanf("%f", &x);
                printf("DIGITE O VALOR 2: ");
                scanf("%f", &y);
                resultado = x + y;
                printf("RESULTADO: %.2f + %.2f = %.2f\n",x, y, resultado);
                break;
            case 2:
                printf("DIGITE O VALOR 1: ");
                scanf("%f", &x);
                printf("DIGITE O VALOR 2: ");
                scanf("%f", &y);
                resultado = x - y;
                printf("RESULTADO: %.2f - %.2f = %.2f\n",x, y, resultado);
                break;
            case 3:
                printf("DIGITE O VALOR 1: ");
                scanf("%f", &x);
                printf("DIGITE O VALOR 2: ");
                scanf("%f", &y);
                resultado = x * y;
                printf("RESULTADO: %.2f * %.2f = %.2f\n",x, y, resultado);
                break;
            case 4:
                printf("DIGITE O VALOR 1: ");
                scanf("%f", &x);
                printf("DIGITE O VALOR 2: ");
                scanf("%f", &y);
                resultado = x / y;
                printf("RESULTADO: %.2f / %.2f = %.2f\n",x, y, resultado);
                break;
        }
    } while (opcao != 5);
    return 0;
}