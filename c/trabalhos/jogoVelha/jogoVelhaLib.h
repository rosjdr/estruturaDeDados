#define QTDE_LINHAS 3
#define QTDE_COLUNAS 3

typedef struct {
    char marca;
} Jogador;

typedef struct {
    int tabuleiro[QTDE_LINHAS][QTDE_COLUNAS];
    Jogador jodador1, jogador2;
    int numeroJogadores;
    int vencedor;
    int jogadorVez;    
} Jogo;

void inicializaJogo(Jogo *j, int numeroJogadores);
void limpaTela();
void desenhaTabuleiro(Jogo jogo);
int verificaVencedor(Jogo j);
int validarEmpate(Jogo jogo);
int leiaJogada(Jogo *jogo);
void alternarJogador(Jogo *jogo);
void jogar(Jogo *jogo);