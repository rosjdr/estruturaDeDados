#include <stdio.h>
#include <stdlib.h>

//declaração de variáveis globais
int opcao;
float valor1, valor2, resultado;

void mostrar_resultado(char sinal){ //função com um parâmetro do tipo char
    printf("RESULTADO: %.2f %c %.2f = %.2f\n",valor1, sinal, valor2, resultado);
}

void calcular(char operacao){
    printf("DIGITE O VALOR 1: ");
    scanf("%f", &valor1);
    printf("DIGITE O VALOR 2: ");
    scanf("%f", &valor2);
    if(operacao=='+') resultado=valor1+valor2;
    if(operacao=='-') resultado=valor1-valor2;
    if(operacao=='*') resultado=valor1*valor2;
    if(operacao=='/') resultado=valor1/valor2;
    mostrar_resultado(operacao);
}

void exibir_menu(){ //função sem parâmetros
    printf("MENU DE OPCOES\n");
    printf("1. Somar\n");
    printf("2. Subtrair\n");
    printf("3. Multiplicar\n");
    printf("4. Dividir\n");
    printf("5. Sair\n");
    printf("OPCAO: ");
}

int main(){
    do{
        exibir_menu(); //chama a função exibir_menu()
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                calcular('+'); //chama a função calcular passando o sinal como parâmetro
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
    } while (opcao != 5);
    return 0;
}
