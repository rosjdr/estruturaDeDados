#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME_ARQUIVO "filmes.txt"

typedef struct{
    int id;
    char nome[100];
    int ano;
} Filme;

typedef struct {
    Filme filmes[200];
    int total_filmes;
} Banco;

typedef enum {LEITURA, ESCRITA} modo;

FILE *abrir_arquivo(char nome[], modo modo);
void fechar_arquivo(FILE *a);
void carregar_filmes(Banco *banco, FILE *arquivo);
void mostra_filmes(Banco *bd);

int main(){

    FILE *arquivo;  
    Banco bd;
    int op;  
    char nome[100];
    int ano;    

    do {
        printf("\n\n====MENU DE OPCOES====\n");
        printf("1. Mostrar filmes em ordem de cadastro\n");
        printf("2. Cadastrar novo filme\n");
        printf("5. Sair\n");
        printf("OPCAO: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            arquivo = abrir_arquivo(NOME_ARQUIVO, LEITURA); 
            carregar_filmes(&bd, arquivo);
            mostra_filmes(&bd);
            fechar_arquivo(arquivo);
            break;
        case 2:   
            setbuf(stdin, NULL);          
            printf("NOME DO FILME: ");
            fgets(nome, 100, stdin);
            setbuf(stdin, NULL);
            nome[strlen(nome)-1] = 0; //remover o \n do final
            printf("ANO DO FILME: ");
            scanf("%d", &ano);
            arquivo = abrir_arquivo(NOME_ARQUIVO, ESCRITA);
            fprintf(arquivo, "\n%s(%d)", nome, ano);
            fechar_arquivo(arquivo);
            break;        
        default:
            break;
        }


    } while (op != 5);

    

    return 0;
}

FILE *abrir_arquivo(char nome[], modo modo){
    FILE *p; 
    switch (modo)
    {
        case LEITURA:
            p = fopen(nome, "r");
            break;
        case ESCRITA:
            p = fopen(nome, "a+");
            break;
        default:
            break;
    }
    if(modo == LEITURA && p == NULL){ 
        printf("Arquivo não encontrado");
        exit(1); 
    }
    return p;
}

void carregar_filmes(Banco *banco, FILE *arquivo){
    char linha[200];
    Filme novo;
    
    banco->total_filmes = 0;
    while(!feof(arquivo)){
        char ano_filme[5] = "";
        char nome_filme[200] = "";
        fgets(linha, 200, arquivo);
        novo.id = banco->total_filmes+1;
        if(linha[strlen(linha)-1] == '\n')
            linha[strlen(linha)-1] = 0;
        strncpy(ano_filme, linha+strlen(linha)-5, 4);
        novo.ano = atoi(ano_filme);
        strncpy(nome_filme, linha, strlen(linha)-6);
        strcpy(novo.nome, nome_filme);
        banco->filmes[banco->total_filmes++] = novo;
    }
}

void mostra_filmes(Banco *bd){
    printf("===== LISTA DE FILMES =====\n\n");
    for(int i=0; i < bd->total_filmes; i++){
        printf("%d - %s - %d\n", bd->filmes[i].id, bd->filmes[i].nome, bd->filmes[i].ano);
    }
}

void fechar_arquivo(FILE *a){
    fclose(a);
}