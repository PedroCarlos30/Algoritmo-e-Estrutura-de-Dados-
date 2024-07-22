//aula sobre union 22/07/2000
#include <stdio.h>
#include <stdlib.h>
//na estrutura union so permite armarzena uma variavel por vez.
typedef union nome{
    char nome[20];
    Documentos doc;

}Nome;
typedef union documentos{
    char cpf[11];
    char rg[11];
}Documentos;
int main(void){
    return 0;
}