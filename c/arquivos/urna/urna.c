#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define OPCAO_SAIR 5


void exibirMenuCandidatos();

int main(){

    int op;

    do{
        system("cls");
        printf("%s", "=== SISTEMA DE VOTACAO - MENU PRINCIPAL === \n\n");
        printf("%s", "1. Candidatos\n");
        printf("%s", "2. Relatorio de candidatos\n");    
        printf("%s", "3. Iniciar votacao\n");
        printf("%s", "4. Apurar resultado\n");    
        printf("%s", "5. Sair\n\n");    
        printf("%s", "OPCAO: ");  

        scanf("%d", &op);
        switch (op)
        {
        case 1:
            exibirMenuCandidatos();
            break;
        
        default:
            break;
        }  
    } while (op != OPCAO_SAIR);

    
    return 0;
}

void exibirMenuCandidatos(){

}