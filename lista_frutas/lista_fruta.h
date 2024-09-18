#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fruta Fruta;
typedef struct no No;
No * criaNo(char * nome_para_fruta, float valor_por_kg );
No * inserirNoInicio(No * lista, char * nome_para_fruta, float valor_por_kg);
void exibirListaDeFrutas(No * lista);