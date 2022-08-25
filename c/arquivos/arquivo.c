#include <stdio.h>
#include <stdlib.h>

/*programa para demonstrar as funcionalidades básicos de trabalhar com arquivos texto no C*/

int main(){
    FILE *p; //declara um ponteiro para trabalhar com o arquivo
    p = fopen("./carros.csv", "r"); //abre o arquivo carros .csv em modo de leitura... a localização do arquivo é referente ao local onde o programa é chamado
    if(p == NULL){ //se o arquivo não existir
        printf("Arquivo não encontrado");
        exit(1); //encerra o programa
    }
    //faz a leitura de cada linha do arquivo
    // char linha[100]; //declara uma variável para armazenar a linha do arquivo
    // while(fgets(linha, 100, p) != NULL){ //enquanto não chegar ao final do arquivo //fgets lê uma linha até que encontre o \n
    //     printf("%s", linha); //imprime a linha
    // }

    //fazer a leitura caractere por caractere
    char c; //declara uma variável para armazenar o caractere lido
    printf("Posição atual no arquivo %ld\n", ftell(p)); //imprime a posição atual no arquivo
    c = fgetc(p); //lê o primeiro caractere do arquivo
    printf("Primeiro caractere: %c\n", c); //imprime o caractere lido
    c = fgetc(p); //lê o segundo caractere do arquivo
    printf("Segundo caractere: %c\n", c); //imprime o caractere lido
    int x; //declara uma variável para armazenar o valor lido
    //fread(&x,sizeof(char),1,p);//lê o valor inteiro armazenado no ponteiro x
    fscanf(p,"%d",&x); //lê o valor inteiro armazenado na variável x
    printf("Terceiro como inteiro: %d\n", x); //imprime o número lido na primeira linha 
    printf("Posição atual no arquivo %ld\n", ftell(p)); //imprime a posição atual no arquivo

    //movendo dentro do arquivo
    fseek(p, 0, SEEK_SET); //movimenta o ponteiro para o início do arquivo
    printf("Posição atual no arquivo %ld\n", ftell(p)); //imprime a posição atual no arquivo
    fseek(p, 3, SEEK_SET); //movimenta o ponteiro para a posição 3 novamente
    printf("Posição atual no arquivo %ld\n", ftell(p)); //imprime a posição atual no arquivo
    rewind(p); //movimenta o ponteiro para o início do arquivo

    while(!feof(p)){ //enquanto não chegar ao final do arquivo usando a função feof
        c = fgetc(p); //lê o próximo caractere do arquivo
        printf("%c", c); //imprime o caractere
    }
    printf("Posição atual no arquivo %ld\n", ftell(p)); //imprime a posição atual no arquivo
    fclose(p);

    //abrir novamente o arquivo para escrita de algumas string em linhas no arquivo
    p = fopen("./carros.csv", "a"); //abre o arquivo carros.csv em modo de escrita...
    if(p == NULL){ //se o arquivo não existir
        printf("Arquivo não encontrado");
        exit(1); //encerra o programa
    }
    fputs("Pode ser assim\n", p); //escreve uma string no arquivo
    char outraString[100]; //declara uma variável para armazenar a outra string
    //atribuir valor para a variável outraString
    sprintf(outraString, "Outra string");
    fputs(outraString, p); //escreve a outra string no arquivo
    //gravando dados formatados no arquivo
    for(int i = 0; i < 10; i++){
        fprintf(p, "Gerado: %d\n", i); //escreve o número i na próxima linha do arquivo - retorna o número de caracteres escritos
    }

    //A única diferença dos protótipos de fprintf() e fscanf() para os protótipos de printf() e 
    //scanf(), respectivamente, é a especificação do arquivo destino através do ponteiro FILE.

    fclose(p); //fecha o arquivo

    //removendo o arquivo do disco
    //remove("./carros.csv"); //remove o arquivo carros.csv do disco

    return 0;
}