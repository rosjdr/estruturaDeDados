#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fstruct
{
    int id;
    char nome[100];
    int ano;
};

typedef struct fstruct filme;

struct lista_filmes {
    filme filmes[200];
    int total_filmes;
};

typedef struct lista_filmes banco_de_dados;


FILE *abrir_arquivo(char nome[], char modo[]);
void carregar_filmes(banco_de_dados *banco, FILE *arquivo);
void mostra_filmes(banco_de_dados *bd);

int main(){
    FILE *arquivo; 
    banco_de_dados bd;

    int op;

    arquivo = abrir_arquivo("./filmes.txt", "a+"); 
    bd.total_filmes = 0;
    carregar_filmes(&bd, arquivo);



    do {
        printf("\n\n====MENU DE OPCOES====\n");
        printf("1. Mostrar filmes em ordem alfabetica\n");
        printf("2. Mostrar filmes em ordem cronologica\n");
        printf("3. Mostrar filmes por ano\n");
        printf("4. Localizar filme por titulo\n");
        printf("5. Sair\n");
        printf("OPCAO: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            mostra_filmes(&bd);
            break;
        
        default:
            break;
        }


    } while (op != 5);

    fclose(arquivo);
    return 0;
}

void mostra_filmes(banco_de_dados *bd){
    printf("===== LISTA DE FILMES =====\n\n");
    for(int i=0; i < bd->total_filmes; i++){
        printf("%d - %s\n", bd->filmes[i].id, bd->filmes[i].nome);
    }
}

void carregar_filmes(banco_de_dados *banco, FILE *arquivo){
    char linha[200];
    filme novo;
    
    while(!feof(arquivo)){
        fgets(linha, 200, arquivo);
        novo.id = banco->total_filmes+1;
        strcpy(novo.nome,linha);
        novo.nome[strlen(novo.nome)-1] = 0;
        banco->filmes[banco->total_filmes++] = novo;
    }
}

FILE *abrir_arquivo(char nome[], char modo[]){
    FILE *p; 
    p = fopen("./filmes.txt", "a+"); 
    if(p == NULL){ 
        printf("Arquivo não encontrado");
        exit(1); 
    }
    return p;
}