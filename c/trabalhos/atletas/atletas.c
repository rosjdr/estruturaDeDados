/*
    Crie um programa que armazene os dados de atletas.
    Cada atleta é representado por seu: nome, esporte, idade e altura.
    O programa deve ler os dados de 5 atletas.
    O programa deve exibir um menu com as opções:
      1. Exibir nome do atleta mais velho
      2. Exibir nome do atleta mais alto
      3. Exibir o nome e a idade de todos os atletas
         por ordem de idade (do mais velho ara o mais
         novo)
      4. Sair
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define QUANTIDADE_ATLETAS 5

typedef struct{
    int idade;
    char nome[50];
    char esporte[50];
    float altura;
} atleta;

atleta criarAtleta(){
    atleta a;
    a.idade = rand()%50 + 18;
    sprintf(a.nome, "%s%d", "Atleta", rand());
    sprintf(a.esporte, "%s%d", "Esporte", rand());
    a.altura = 1.1 + ((float)rand()/(float)(RAND_MAX)) * 1.0;
    return a;
}

void imprimirLista(atleta *lista){
    printf("LISTA COMPLETA\n");
    for(int i=0; i<QUANTIDADE_ATLETAS; i++){
        printf("NOME: %s\nESPORTE: %s\nIDADE: %d\nALTURA: %.2f\n",
               lista[i].nome,
               lista[i].esporte,
               lista[i].idade,
               lista[i].altura);
    }
}

void fazerLeitura(atleta *lista){
    for(int i=0; i<QUANTIDADE_ATLETAS; i++)
        lista[i] = criarAtleta();
}


void imprimirAtletaMaisVelho(atleta *lista){
    int idadeDoMaisVelho = 0;
    int posicaoDoMaisVelho;
    for(int i = 0; i < QUANTIDADE_ATLETAS; i++){
        if(lista[i].idade > idadeDoMaisVelho){
            idadeDoMaisVelho = lista[i].idade;
            posicaoDoMaisVelho = i;
        }
    }
    printf("ATLETA MAIS VELHO\n");
    printf("NOME: %s\nESPORTE: %s\nIDADE: %d\nALTURA: %.2f\n",
               lista[posicaoDoMaisVelho].nome,
               lista[posicaoDoMaisVelho].esporte,
               lista[posicaoDoMaisVelho].idade,
               lista[posicaoDoMaisVelho].altura);

}

int main()
{
    srand(time(NULL));
    atleta lista[QUANTIDADE_ATLETAS];
    fazerLeitura(lista);
    imprimirLista(lista);
    imprimirAtletaMaisVelho(lista);

    return 0;
}
