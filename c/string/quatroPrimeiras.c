#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char string[20];
    char primeiros[5];
    printf("%s", "INFORME A STRING: ");
    fgets(string,20,stdin);
    string[strlen(string)-1] = 0;
    if(strlen(string) >= 4){
        strncpy(primeiros,string,4);
        printf("4 PRIMEIROS CARACTERES: %s\n", primeiros);
    } else {
        printf("STRING: %s\n", string);
    }

    return 0;
}