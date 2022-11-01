#define QTDE_LINHAS 3
#define QTDE_COLUNAS 3

typedef struct{
    int t[QTDE_LINHAS][QTDE_COLUNAS];
} Tabuleiro;

typedef struct {
    char marca;
} Jogador;

typedef struct {
    Tabuleiro tabuleiro;
    Jogador jodador1, jogador2;
    int vencedor;
} Jogo;