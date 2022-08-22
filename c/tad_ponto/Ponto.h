typedef struct ponto Ponto;
Ponto* cria_ponto(float x, float y);
void libera_ponto(Ponto *p);
int acessa_ponto(Ponto *p, float *x, float *y);
int atribui_ponto(Ponto *p, float x, float y);
int distancia_ponto(Ponto *p1, Ponto *p2);