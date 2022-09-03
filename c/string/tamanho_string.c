#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char leitura[200];
    int cont = 0;

    printf("%s", "INFORME A STRING: ");
    fgets(leitura,200,stdin);
    leitura[strlen(leitura)-1]=0;

    while(leitura[cont] != '\0'){
        cont++;
    }
    
    printf("\"%s\" TEM %d %s!\n", leitura, cont, cont > 1 ? "CARACTERES" : "CARACTER");

    return 0;
}