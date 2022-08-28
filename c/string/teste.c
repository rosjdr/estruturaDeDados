#include <stdio.h>
#include <string.h>

int main(){
    char str1[20], str2[20], str3[40];

    strcpy(str1, "Primeira string"); //atribuição por cópia
    printf("[str1]: %s\n", str1);

    printf("Tamanho de str1: %ld\n", strlen(str1)); //tamanho de uma string

    strcpy(str2, str1); //copia o conteúdo de str1 na str2
    printf("[str2] copiada: %s\n", str2);

    //compara str1 com str2
    if (strcmp(str1,str2) == 0) printf("[str1]: %s == [str2]: %s\n", str1, str2);
    else printf("[str1]: %s != [str2]: %s\n", str1, str2);

    sprintf(str2, "Segunda string"); //atribuição por impressão formatada
    printf("[str2]: %s\n", str2);

    //compara str1 com str2
    if (strcmp(str1,str2) == 0) printf("[str1]: %s == [str2]: %s\n", str1, str2);
    else printf("[str1]: %s != [str2]: %s\n", str1, str2);

    printf("[str3]: %s\n", str3); //pode imprimir um lixo de memória porque não foi inicializada
    strcpy(str3,""); //inicializa a str3 vazia
    printf("[str3]: %s\n", str3); //imprime a linha vazia
    strcat(str3,str1); //concatena a str1 no final de str3
    printf("[str3] <- [str1]: %s\n", str3);
    strcat(str3,str2); //concatena a str2 no final de str3
    printf("[str3] <- [str2]: %s\n", str3);  


    return 0;
}