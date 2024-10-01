#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct fila Fila;
Fila* fila_cria(void);
void fila_insere(Fila* f, float elemento);
float fila_retira(Fila* f);
void fila_imprime(Fila* f);