#include <stdio.h>
#include <stdlib.h>

int main(){
    int v1 = 1, v2 = 2;
    int *ptr;

    printf("Endereco de v1: %p - valor de v1: %d\n", &v1, v1);
    printf("Endereco de v2: %p - valor de v2: %d\n", &v2, v2);

    ptr = &v1;
    printf("Endereco de ptr: %p - valor no endereco de ptr: %d\n", ptr, *ptr);

    *ptr = 10; //altera o valor que está armazenado onde ptr aponta (1 <-> 10)
    printf("Endereco de ptr: %p - valor no endereco de ptr: %d\n", ptr, *ptr);
    printf("Endereco de v1: %p - valor de v1: %d\n", &v1, v1);
    
    //aritmética com ponteiros (muito útil para trabalhar com vetores)
    int vetor_comum[5];
    int *ptr_vetor;

    ptr_vetor = vetor_comum;
    for(int i = 0; i<5;i++){ //leitura do vetor utilizando apenas o ponteiro
        *(ptr_vetor+i) = i;
    }

    //imprimir o vetor utilizando um ponteiro para a primeira posição
    ptr_vetor = vetor_comum;
    for(int i = 0; i<5;i++){
        printf("%p : %d\n",ptr_vetor+i, *(ptr_vetor+i));
    }

    //imprimir o vetor de trás para frente utilizando um ponteiro para a última posição
    ptr_vetor = &vetor_comum[4];
    for(int i = 0; i<5;i++){
        printf("%p : %d\n", ptr_vetor-i, *(ptr_vetor-i));
    }

    //alocar ponteiro dinamicamente
    int *ptr_x = (int *) malloc(sizeof(int));
    *ptr_x = 8;
    printf("%p : %d\n", ptr_x, *(ptr_x));

    //alocar um vetor para 5 inteiros dinamicamente
    int *ptr_v = (int *) malloc(sizeof(int)*5); //o tamanho pode ser determinado por uma variável
    ptr_v[0] = 98; //depois de alocado pode acessar normalmente pelo nome da variável
    printf("%p : %d\n", ptr_v, *(ptr_v));



    return 0;
}