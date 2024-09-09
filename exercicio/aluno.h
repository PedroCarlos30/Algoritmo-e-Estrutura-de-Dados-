#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;
typedef struct no No;
No* adiona_aluno(No* lista, int matricula, char nome, float media);
void imprime_aluno(No* lista);