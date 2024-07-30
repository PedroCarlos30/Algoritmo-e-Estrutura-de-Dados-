#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void){
    int n_pessoas=0;
    int maxtamanho = 100;  
    int idade=0;  
    printf("Digite o numero de pessoas: ");    
    scanf("%d", &n_pessoas);
    char **matriz = (char**)malloc(n_pessoas*sizeof(char*));
    if(matriz == NULL){
        printf("Erro, memoria nao alocada.");
        exit(1);
    }
    for(int i=0; i<n_pessoas; i++){
        matriz[i] = (char*)malloc(maxtamanho*sizeof(char));
        if(matriz == NULL){
            printf("Erro, memoria nao alocada.");
            exit(1);
        }
        printf("Digite o %d° nome: ", i+1);
        scanf(" %[^\n]", matriz[i]);   
    }
    int *vetor = (int*)malloc(idade*sizeof(int*));
    if(matriz == NULL){
        printf("Erro, memoria nao alocada.");
        exit(1);
    }    
    for(int i=0; i<n_pessoas; i++){
        printf("Digite a %d° idade: ", i+1);
        scanf("%d", &vetor[i]);   
    }
    for(int i=0; i<n_pessoas; i++){
        printf("Nome: %s, Idade: %d\n", matriz[i], vetor[i]);
    }
    for(int i=0; i<n_pessoas; i++){
        free(matriz[i]);
    }
    free(matriz);
    free(vetor);    
    return 0;
} 