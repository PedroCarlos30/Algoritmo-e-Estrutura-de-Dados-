#include "pilha.h"

struct pilha{
    int cap;
    int topo;
    float* dados;
};

Pilha* pilha_cria(void){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = 0;
    p->cap = 10;
    p->dados = (float*)malloc(p->cap * sizeof(float)); 
    return p;
}

void pilha_push(Pilha* p, float v){
    if(p->topo == p->cap){
        p->dados = (float*)realloc(p->dados, p->cap * sizeof(float));
        if(p->dados == NULL){
            printf("Sem topo!");
            exit(1);
        }
    }
    p->dados[p->topo] = v;
    p->topo++;
}

int pilha_vazia(Pilha* p){
    return (p->topo == 0);
}

float pilha_pop(Pilha* p){
    float v;
    if(pilha_vazia(p)){
        printf("Pilha vazia.\n");
        exit(1);
    }
    v = p->topo-1;
    p->topo--;
    return v;
}

void pilha_libera(Pilha* p){
    free(p);
}

int main(void){
    Pilha* pilha = pilha_cria();
    int i;
    for(i = 0; i < 25; i++){
        pilha_push(pilha, i+0.0);
    }
    while(!pilha_vazia(pilha)){
        printf("%.1f\t", pilha_pop(pilha));
    }
    printf("\n");
    pilha_libera(pilha);
    return 0;
}