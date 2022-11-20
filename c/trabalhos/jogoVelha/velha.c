#include <stdio.h>
#include <stdlib.h>
#include "jogoVelhaLib.h"

int main()
{
    Jogo jogo;

    inicializaJogo(&jogo, 1);
    jogar(&jogo);

    return 0;
}
