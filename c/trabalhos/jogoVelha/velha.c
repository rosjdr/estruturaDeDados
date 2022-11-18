#include <stdio.h>
#include <stdlib.h>
#include "jogoVelhaLib.h"

int main()
{
    Jogo jogo;

    int linha,coluna;   

    inicializaJogo(&jogo);
    while(1){
        jogar(jogo);        
    }
    return 0;
}
