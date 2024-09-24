#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
typedef struct pilha Pilha;
Pilha* pilha_cria(void);
void pilha_push(Pilha* p, float v);
float pilha_pop(Pilha* p);
int pilha_vazia(Pilha* p);
void libera_pilha(Pilha* p);
void imprime(Pilha* l);

