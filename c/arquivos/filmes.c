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
void mostra_filmes_por_ano(banco_de_dados *bd);

int main(){
    FILE *arquivo; 
    banco_de_dados bd;

    int op;

    arquivo = abrir_arquivo("./filmes.txt", "a+"); 
    bd.total_filmes = 0;
    carregar_filmes(&bd, arquivo);

    do {
        printf("\n\n====MENU DE OPCOES====\n");
        printf("1. Mostrar filmes em ordem de cadastro\n");
        printf("2. Mostrar filmes em ordem cronologica\n");
        printf("3. Pesquisar filmes por ano\n");
        printf("4. Pesquisar filme por titulo\n");
        printf("5. Sair\n");
        printf("OPCAO: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            mostra_filmes(&bd);
            break;
        case 3:
            mostra_filmes_por_ano(&bd);
            break;
        
        default:
            break;
        }


    } while (op != 5);

    fclose(arquivo);
    return 0;
}

void mostra_filmes_por_ano(banco_de_dados *bd){
    int ano_busca;
    int filme_encontrado = 0;
    printf("%s", "INFORME O ANO DE BUSCA: ");
    scanf("%d", &ano_busca);
    for(int i=0; i<bd->total_filmes; i++)
        if(bd->filmes[i].ano == ano_busca){
            filme_encontrado++;
            break;
        }
    if(filme_encontrado){
        printf("===== LISTA DE FILMES POR ANO =====\n\n");
        for(int i=0; i < bd->total_filmes; i++){
            if(bd->filmes[i].ano == ano_busca)
                printf("%d - %s - %d\n", bd->filmes[i].id, bd->filmes[i].nome, bd->filmes[i].ano);
        }
    } else {
        printf("NAO FORAM ENCONTRADOS FILMES PARA ESTE ANO!\n\n");
    }

}

void mostra_filmes(banco_de_dados *bd){
    printf("===== LISTA DE FILMES =====\n\n");
    for(int i=0; i < bd->total_filmes; i++){
        printf("%d - %s - %d\n", bd->filmes[i].id, bd->filmes[i].nome, bd->filmes[i].ano);
    }
}

void carregar_filmes(banco_de_dados *banco, FILE *arquivo){
    char linha[200];
    filme novo;
    
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

FILE *abrir_arquivo(char nome[], char modo[]){
    FILE *p; 
    p = fopen("./filmes.txt", "a+"); 
    if(p == NULL){ 
        printf("Arquivo não encontrado");
        exit(1); 
    }
    return p;
}