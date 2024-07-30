#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void num_aleatorio(int num, int **matriz){
    for(int l=0; l<num; l++){
        for(int c=0; c<num; c++){
            matriz[l][c] = rand() % 100 + 1;
        }
    }
}
void imprime(int num, int **matriz){
    printf("Matriz de ordem %d x %d:\n", num, num);
    for(int l=0; l<num; l++){
        for(int c=0; c<num; c++){
            printf("%d ", matriz[l][c]);
        }
        printf("\n"); 
    }
    
}
int main(void){
srand(time(NULL));
int ordem = (rand()%100)+1;


int num = 0;
printf("Digite um numero: ");
scanf("%d", &num);
if(num % 2 == 0 && num > 0){
    printf("\n");
}
else{
    printf("Erro, o numero nao e inteiro positivo.");
}
int **matriz = (int**)malloc(num*sizeof(int));
for(int i=0; i<num; i++){
    matriz[i] = (int*)malloc(num*sizeof(int));
}
num_aleatorio(num, matriz);
imprime(num, matriz);
for(int i=0; i<num; i++){
    free(matriz[i]);
}
free(matriz);
return 0;
}