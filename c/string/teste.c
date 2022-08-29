#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

    char *ptr;
    ptr = strchr(str1, 'i'); //pegando o ponteiro para a posição do caractere
    if (ptr) printf("[str1]: %s - 'i' encontrado na posicao: %ld\n", str1, ptr - str1);
    
    int pos;
    pos = strchr(str1, 'i') - str1; //pegando o índice para a posição do caractere
    printf("[str1]: %s - 'i' encontrado na posicao: %d\n", str1, pos);
    pos = strchr(str1, 'x') - str1;
    printf("[str1]: %s - 'x' encontrado na posicao: %d\n", str1, pos);

    ptr = strrchr(str1, 'i');
    if (ptr) printf("[str1]: %s - 'i' ultima posicao: %ld\n", str1, ptr - str1);

    printf("Os 2 primeiros caracteres de ABCD = ABEF: %d\n", strncmp("ABCD","ABEF",2));
    printf("Os 3 primeiros caracteres de ABCD = ABEF: %d\n", strncmp("ABCD","ABEF",3));

    printf("Convertendo 3.45 para ponto flutuante: %f\n", atof("3.45"));
    printf("Convertendo 3 para ponto inteiro: %d\n", atoi("3"));
    printf("Convertendo 3 para ponto inteiro longo: %ld\n", atol("3"));

    printf("mei dentro de [str1]: %s\n", strstr(str1, "mei") ? "Encontrado" : "Nao Encontrado");
    printf("xyz dentro de [str1]: %s\n", strstr(str1, "xyz") ? "Encontrado" : "Nao Encontrado");
    printf("indice de mei dentro de [str1]: %ld\n", strstr(str1, "mei") - str1);

    


    return 0;
}