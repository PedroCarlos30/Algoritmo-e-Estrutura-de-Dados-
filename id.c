#include<stdio.h>
union tipos{
    int inteiro;
    float real;
    char letra;
};
typedef union tipos Tipos;
int main(void){
    Tipos variavel;
    variavel.inteiro = 2;
    printf("\n%d, %d, %d", variavel.inteiro, variavel.real, variavel.letra);
    variavel.real = 2.5;
    printf("\n%d, %f, %c", variavel.inteiro, variavel.real, variavel.letra);
    variavel.letra = 's';
    printf("\n%d, %f, %c", variavel.inteiro, variavel.real, variavel.letra);
    return 0;
}