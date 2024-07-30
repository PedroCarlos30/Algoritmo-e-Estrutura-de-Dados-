#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int linhas, colunas, i=1;
	printf("Digite a quantidade de linhas e colunas da matriz: ");
	scanf("%d %d", &linhas, &colunas);
	int **matriz = (int **)malloc(linhas * sizeof(int*));
	for(int i=0; i<linhas; i++){
		matriz[i] = (int *)malloc(colunas * sizeof(int));
		}
	for(int l=0; l<linhas; l++){
		for(int c=0; c<colunas; c++){
			printf("Digite o %dº elemento da matriz: ", i++);
			scanf("%d", &matriz[l][c]);
			}
		}
    printf("Matriz original:\n");
    for(int l=0; l<linhas; l++){
        for(int c=0; c<colunas; c++){
            printf("%d ", matriz[l][c]);
        }
        printf("\n");
    }    
   int **transposta = (int**)malloc(linhas*sizeof(int*));
   for(int i=0; i<linhas; i++){
       transposta[i] = (int*)malloc(colunas*sizeof(int));
       }
   for(int l=0; l<linhas; l++){
       for(int c=0; c<colunas; c++){
           transposta[c][l]=matriz[l][c];
       }
   } 
   printf("Matriz transposta:\n");
   for(int l=0; l<linhas; l++){
       for(int c=0; c<colunas; c++){
           printf("%d ", transposta[l][c]);
       }
       printf("\n");
   }
   for(int i=0; i<linhas; i++){
       free(matriz[i]);
   }
   free(matriz);
   for(int i=0; i<colunas; i++){
       free(transposta[i]);
   }
   free(transposta);
	return 0;
}