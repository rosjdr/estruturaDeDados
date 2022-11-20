#include <stdio.h>
#include <stdlib.h>
#include "jogoVelhaLib.h"

#ifdef __unix__         
    #include <unistd.h>
#elif defined(_WIN32) || defined(WIN32) 
   #define OS_Windows
   #include <windows.h>
#endif

int isJogadaValida(Jogo jogo, int linha, int coluna){
    return jogo.tabuleiro[linha-1][coluna-1] == 0;
}

void alternarJogador(Jogo *jogo){
    if(jogo->jogadorVez == 1) 
        jogo->jogadorVez = 2;
    else 
        jogo->jogadorVez = 1;
}

int leiaJogada(Jogo *jogo){
    int linha, coluna;

    printf("JOGADOR %d INFORME A LINHA E A COLUNA: ", jogo->jogadorVez);       
    scanf("%d %d",&linha,&coluna);
    //validar a jogada
    if(!isJogadaValida(*jogo, linha, coluna)){
        return 1;
    }
    //armazenando a jogada
    jogo->tabuleiro[linha-1][coluna-1] = jogo->jogadorVez;
    return 0;
}

int validarEmpate(Jogo jogo){
    //validar empate
    int cont_zero = 0;
    for(int i=0; i<QTDE_LINHAS;i++)
        for(int j=0;j<QTDE_COLUNAS;j++)
            if(jogo.tabuleiro[i][j]==0) cont_zero++;
    if(!cont_zero){
        return 1;
    }
    return 0;
}

int verificaVencedor(Jogo j){
    //verificar vencedor
    for(int i=0;i<QTDE_LINHAS;i++){
        //verifica as linhas
        if(j.tabuleiro[i][0]!=0 && j.tabuleiro[i][0]==j.tabuleiro[i][1] && j.tabuleiro[i][1]==j.tabuleiro[i][2]){
            return 1;
            break;
        }
        //verifica as colunas
        if(j.tabuleiro[0][i]!=0 && j.tabuleiro[0][i]==j.tabuleiro[1][i] && j.tabuleiro[1][i]==j.tabuleiro[2][i]){
            return 1;
            break;
        }
    }
    //verificar diagonais
    if(j.tabuleiro[0][0]!=0 && j.tabuleiro[0][0]==j.tabuleiro[1][1] && j.tabuleiro[1][1]==j.tabuleiro[2][2]){
        return 1;
    }
    if(j.tabuleiro[0][2]!=0 && j.tabuleiro[0][2]==j.tabuleiro[1][1] && j.tabuleiro[1][1]==j.tabuleiro[2][0]){
        return 1;
    }   
    return 0; 
}

void limpaTabuleiro(int t[][QTDE_COLUNAS]){
   for(int i=0;i<QTDE_LINHAS;i++)
       for(int j=0;j<QTDE_COLUNAS;j++)
           t[i][j] = 0;
}

void inicializaJogo(Jogo *j, int numeroJogadores){
    j->vencedor = 0;
    j->jogadorVez = 1;
    j->numeroJogadores = numeroJogadores;

    limpaTabuleiro(j->tabuleiro);
    desenhaTabuleiro(*j);
}

void desenhaTabuleiro(Jogo jogo){
   limpaTela();
   for(int i=0;i<QTDE_LINHAS;i++){
       for(int j=0;j<QTDE_COLUNAS;j++){
           if(jogo.tabuleiro[i][j]==0)
               printf(" - ");
           else
               printf(" %c ",jogo.tabuleiro[i][j]==1?'X':'O');
       }
       printf("\n");
   }
}

void limpaTela(){
    #ifdef OS_Windows
    /* Codigo Windows */
        system("cls");
    #else
    /* Codigo GNU/Linux */
        system("clear");
    #endif  
}

void jogador2(Jogo *jogo){
    int linha = 1, coluna = 1;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            if(isJogadaValida(*jogo, i, j)){
                linha = i;
                coluna = j;
                break;
            }
        }
        if(isJogadaValida(*jogo, linha, coluna))
            break;
    }
    jogo->tabuleiro[linha-1][coluna-1] = jogo->jogadorVez;
}

void jogar(Jogo *jogo){

    while(1){
        //lendo a jogada
        if(jogo->numeroJogadores==2 ||
          (jogo->numeroJogadores == 1 && jogo->jogadorVez == 1)){
            while(leiaJogada(jogo)!=0){
                printf("\nJOGADA INVALIDA!\n");
            }
        } else {
            jogador2(jogo);
        }

        //imprime o tabuleiro       
        desenhaTabuleiro(*jogo);              

        if(verificaVencedor(*jogo)){
            printf("\nJOGADOR %d VENCEDOR!!!!", jogo->jogadorVez);
            break;
        }
        //validar empate
        if(validarEmpate(*jogo)){
            printf("\nEMPATOU!!!\n");
            break;
        }
        alternarJogador(jogo);
    }
}