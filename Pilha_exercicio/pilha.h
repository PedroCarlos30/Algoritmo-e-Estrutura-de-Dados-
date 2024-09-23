#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct pilha Pilha;
Pilha* pilha_cria(void);
void pilha_push(Pilha* p);
int pilha_vazia(Pilha* p);
float pilha_pop(Pilha* p);
void pilha_libera(Pilha* p);