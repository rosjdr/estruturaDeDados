#include <stdio.h>
#include <string.h>

struct pessoa {
    char nome[30];
    int idade;
    char sexo;
    char endereco[50];
};

int main(){

    struct pessoa p;

    printf("NOME: ");
    fgets(p.nome, 30, stdin); //vai gravar na string 4 caracteres úteis mais o \0
    setbuf(stdin, NULL); //se não limpar o buffer nesse ponto a próxima leitura é pulada
    p.nome[strcspn(p.nome, "\n")] = 0;

    printf("IDADE: ");
    scanf("%d", &p.idade);
    setbuf(stdin, NULL);
    
    printf("ENDERECO: ");
    fgets(p.endereco, 50, stdin);
    setbuf(stdin, NULL);

    printf("SEXO: "); //com a leitura do sexo depois da leitura do endereço o programa funciona normalmente, mas se inverter não funciona pq o \n é colocado no endereço
    scanf(" %c", &p.sexo);
    setbuf(stdin, NULL);
    

    printf("A pessoa %s, do sexo %c, tem %d anos e mora em %s", p.nome,p.sexo,p.idade,p.endereco);
    setbuf(stdout, NULL);

    return 0;
}