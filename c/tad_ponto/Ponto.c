#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Ponto.h"

struct ponto {
    float x;
    float y;
};

Ponto* cria_ponto(float x, float y){
    Ponto *p = (Ponto*) malloc(sizeof(Ponto));
    if(p!=NULL){
        p->x = x;
        p->y = y;
    }
    return p;
}

void libera_ponto(Ponto *p){
    free(p);
}

int acessa_ponto(Ponto *p, float *x, float *y){
    if (p == NULL) return 0;
    *x = p->x;
    *y = p->y;
    return 1;
}

int atribui_ponto(Ponto *p, float x, float y){
    if (p == NULL) return 0;
    p->x = x;
    p->y = y;
    return 1;
}

int distancia_ponto(Ponto *p1, Ponto *p2){
    if (p1 == NULL || p2 == NULL) return -1;
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    return sqrt(dx*dx + dy*dy);
}