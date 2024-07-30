#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int main(void){
    Aluno*aluno=aloca_aluno();
    preenche(aluno);
    imprime(aluno);
    free(aluno);
    return 0;
}