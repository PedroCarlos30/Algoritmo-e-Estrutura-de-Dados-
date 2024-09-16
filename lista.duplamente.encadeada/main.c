#include "lista2.c"

int main(void){
    Lista2* lista = NULL;
    Lista2* remove;
    lista = lst2_insere(lista, 10);
    lista = lst2_insere(lista, 1);
    lista = lst2_insere(lista, 100);
    lista = lst2_insere(lista, 106);
    lista = lst2_insere(lista, 13);
    remove = lst2_retira(lista, 10);
    imprime(lista);
}