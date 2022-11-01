#include <stdio.h>
#include <stdlib.h>

int main()
{
   int t[3][3] = {0};
   int jogador = 1;
   int linha,coluna;
   int continuar = 1;
   int vencedor = 0;
   for(int i=0;i<3;i++){
       for(int j=0;j<3;j++){
           if(t[i][j]==0)
               printf(" - ");
           else
               printf(" %c ",t[i][j]==1?'X':'O');
       }
       printf("\n");
   }
   while(continuar){
       //lendo a jogada
       printf("JOGADOR %d INFORME A LINHA E A COLUNA: ", jogador);
       scanf("%d %d",&linha,&coluna);
       //validar a jogada
       if(t[linha-1][coluna-1]!=0){
           printf("OPCAO INVALIDA!\n");
           continue;
       }
       //armazenando a jogada
       t[linha-1][coluna-1] = jogador;
       //imprime o tabuleiro
       system("cls");
       for(int i=0;i<3;i++){
           for(int j=0;j<3;j++){
               if(t[i][j]==0)
                   printf(" - ");
               else
                   printf(" %c ",t[i][j]==1?'X':'O');
           }
           printf("\n");
       }
       //verificar vencedor
       for(int i=0;i<3;i++){
           //verifica as linhas
           if(t[i][0]!=0 && t[i][0]==t[i][1] && t[i][1]==t[i][2]){
               vencedor = 1;
               break;
           }
           //verifica as colunas
           if(t[0][i]!=0 && t[0][i]==t[1][i] && t[1][i]==t[2][i]){
               vencedor = 1;
               break;
           }
       }
       //verificar diagonais
       if(t[0][0]!=0 && t[0][0]==t[1][1] && t[1][1]==t[2][2]){
           vencedor = 1;
       }
       if(t[0][2]!=0 && t[0][2]==t[1][1] && t[1][1]==t[2][0]){
           vencedor = 1;
       }
       if(vencedor){
           printf("\nJOGADOR %d VENCEDOR!!!!", jogador);
           break;
       }
       //validar empate
       int cont_zero = 0;
       for(int i=0; i<3;i++)
           for(int j=0;j<3;j++)
               if(t[i][j]==0) cont_zero++;
       if(!cont_zero){
           printf("\nEMPATOU!!!\n");
           break;
       }
       //alternar o jogador
       if(jogador==1) jogador = 2;
       else jogador = 1;
   }
   return 0;
}
