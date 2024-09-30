#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct fila Fila;

Fila* fila_cria(void);
void fila_insere(Fila* f, int v);
int fila_remove(Fila* f);
int fila_vazia(Fila* f);
int fila_cheia(Fila* f);
void fila_libera(Fila* f);
void fila_imprime(Fila* f);
int incrementa(int i);