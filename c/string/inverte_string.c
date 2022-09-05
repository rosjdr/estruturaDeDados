#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char leitura[200];
    int cont = 0;

    printf("%s", "INFORME A STRING: ");
    fgets(leitura,200,stdin);
    leitura[strlen(leitura)-1]=0;

    for(int i=strlen(leitura)-1; i>=0; i--){
        printf("%c", leitura[i]);
    }
    printf("\n");
    

    return 0;
}