#include "fila.h"

typedef struct lista{
    float info;
    Lista* prox;
};

struct fila{
    Lista* inicio;
    Lista* fim;
};
//função para criar uma fila.
Fila* fila_cria(void){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if(f == NULL){
        exit(1);
    }
    f -> inicio == NULL;
    f -> fim == NULL;
    return f;
}
//função para inserir um novo elemento nunha fila.
void fila_insere(Fila* f, float elemento){
    Lista* novo_no = (Lista*) malloc(sizeof(Lista));
    if(novo_no == NULL){
        exit(1);
    }
    novo_no -> info = elemento;
    novo_no -> prox = NULL;
    if(f -> fim != NULL){
        f -> fim -> prox = novo_no;
    }
    else{
        f -> inicio = novo_no;
    }
    f -> fim = novo_no;
}
//função para retirar.
float fila_retira(Fila* f){
    if(f -> inicio == NULL){
        printf("Fila vazia!");
        exit(1);
    }
    float elemento = f -> inicio -> info;
    f -> inicio = f -> inicio -> prox;
    if(f -> inicio == NULL){
        f -> fim = NULL;
    }
    return elemento;
}
//função para imprimir a fila.
void fila_imprime(Fila* f){
    Lista* count;
    for(count = f -> inicio; count != NULL; count = count -> prox){
        printf("%.2f \t", count -> info);
    }
}

