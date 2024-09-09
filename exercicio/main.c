#include "aluno.h"

int main(void){
    No *lista = NULL;
    lista = adiona_aluno(lista, 100, "Pedro", 7.3);
    lista = adiona_aluno(lista, 104, "Lucas", 8.3);
    lista = adiona_aluno(lista, 100, "Matheus", 6.3);
    lista = adiona_aluno(lista, 100, "Anabel", 5.3);
    lista = adiona_aluno(lista, 100, "Maria", 1.3);
    imprime_aluno(lista);
    printf("\n\n\nOrdenado.");
    lista = adiciona_aluno_ordenado(lista, 100, "Pedro", 7.3);
    lista = adiciona_aluno_ordenado(lista, 104, "Lucas", 8.3);
    lista = adiciona_aluno_ordenado(lista, 100, "Matheus", 6.3);
    lista = adiciona_aluno_ordenado(lista, 100, "Anabel", 5.3);
    lista = adiciona_aluno_ordenado(lista, 100, "Maria", 1.3);
    imprime_aluno(lista);
    libera_lista(lista);
    return 0;
}