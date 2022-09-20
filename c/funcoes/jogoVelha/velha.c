#include <stdio.h>
#include <stdlib.h>

int main() {
    int t[3][3] = {0};
    int jogador = 1;
    int vencedor = 0;

    while(!vencedor){
        int l,c;
        printf("Jogador %d, digite a linha e a coluna: ",jogador);
        scanf("%d %d",&l,&c);

        if(t[l-1][c-1]!=0){
            printf("\nJOGADA INVALIDA!!!\n");
            continue;
        }

        t[l-1][c-1] = jogador;

        //mostra tabuleiro
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(t[i][j]==0)
                    printf(" - ");
                else
                    printf(" %c ",t[i][j]==1?'X':'O');
            }
            printf("\n");
        }

        //conferir se alguem venceu
        for(int i=0;i<3;i++){
            if(t[i][0] != 0 &&
               t[i][0] == t[i][1] &&
               t[i][1] == t[i][2]) vencedor = 1;
            if(t[0][i] != 0 &&
               t[0][i] == t[1][i] &&
               t[1][i] == t[2][i]) vencedor = 1;
        }

        if(t[0][0] != 0 &&
           t[0][0] == t[1][1] &&
           t[1][1] == t[2][2]) vencedor = 1;
        if(t[0][2] != 0 &&
           t[0][2] == t[1][1] &&
           t[1][1] == t[2][0]) vencedor = 1;

        //imprime o vencedor
        if(vencedor){
          printf("\nJogador %d venceu!!!",jogador);
        }

        jogador = jogador==1?2:1;
    }
}

