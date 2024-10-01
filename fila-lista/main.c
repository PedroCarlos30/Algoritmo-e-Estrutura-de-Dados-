#include "fila.c"

int main(void){
    Fila* f = fila_cria();
    fila_insere(f, 4.5);
    fila_insere(f, 6.4);
    fila_insere(f, 3.1);
    fila_imprime(f);
    return 0;
}