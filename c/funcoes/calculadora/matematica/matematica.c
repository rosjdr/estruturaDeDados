#include <stdio.h>
#include "matematica.h"


float calcular(char operacao, float x, float y){
    float resultado; 

    if(operacao=='+') resultado=x+y;
    if(operacao=='-') resultado=x-y;
    if(operacao=='*') resultado=x*y;
    if(operacao=='/') resultado=x/y;

    return resultado;
}

/**
 * Função para apresentar o resultado de qualquer operação
 * 
 * @param sinal     indica qual é o sinal da operação que será apresentado
 * @param x         primeiro termo da operação que será impresso na tela
 * @param y         segundo termo da operação que será impresso na tela
 * @param resultado resultado da operação que será impresso na tela
 * 
 * @return void
 * 
 * @author Rodrigo Carvalho
*/
void mostrar_resultado(char sinal, float x, float y, float resultado){
    printf("RESULTADO: %.2f %c %.2f = %.2f\n",x, sinal, y, resultado);
}