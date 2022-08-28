#include <stdio.h>
#include <string.h>

struct pessoa {
    char nome[30];
    int idade;
    double peso;
    char sexo;
    struct endereco {
        char rua[50];
        char bairro[50];
        char cidade[50];

    } endereco;
};

int main(){

    struct pessoa p;

    printf("NOME: ");
    fgets(p.nome, 30, stdin); //vai gravar na string 4 caracteres úteis mais o \0
    setbuf(stdin, NULL); //se não limpar o buffer nesse ponto a próxima leitura é pulada
    p.nome[strlen(p.nome)-1] = 0;

    printf("IDADE: ");
    scanf("%d", &p.idade);
    setbuf(stdin, NULL); //se depois disso for ler um caractere não precisa de setbuf... só colocar o " %c"
    
    printf("SEXO: "); //com a leitura do sexo depois da leitura do endereço o programa funciona normalmente, mas se inverter não funciona pq o \n é colocado no endereço
    scanf(" %c", &p.sexo);
    getchar(); //esse getchar() descarta o \n que foi lido junto com o caractere do sexo
    
    setbuf(stdin, NULL);
    printf("RUA: ");
    fgets(p.endereco.rua, 50, stdin);
    p.endereco.rua[strlen(p.endereco.rua)-1] = 0;

    setbuf(stdin, NULL);
    printf("BAIRRO: ");
    fgets(p.endereco.bairro, 50, stdin);
    p.endereco.bairro[strlen(p.endereco.bairro)-1] = 0;

    setbuf(stdin, NULL);
    printf("CIDADE: ");
    fgets(p.endereco.cidade, 50, stdin);
    p.endereco.cidade[strlen(p.endereco.cidade)-1] = 0;

    setbuf(stdin, NULL); 
    printf("PESO: ");
    scanf("%lf", &p.peso);

    printf("O tamanho do buffer é: %d\n", BUFSIZ);

    printf("A pessoa %s, do sexo %c, tem %d anos, pesa %lfkg e mora na rua %s, bairro %s da cidade %s\n", p.nome,p.sexo,p.idade,p.peso, p.endereco.rua, p.endereco.bairro, p.endereco.cidade);
    
    return 0;
}