#include <stdio.h>

int main(void)
{
	/*declarei minhas variaveil "tamanho", que posteriormente vai ser dado pelo usuario.*/
	int tamanho;
	/*aqui estou pedindo ao usuario que digite o tamanho, e atribuindo esse tamanho a minha variavel "tamanho"*/
	printf("Digite o tamanho do vetor. ex: 5:\t");
	scanf("%d", &tamanho);
	/*aqui estou alocando memoria ao meu vetor "vet".*/
	int*vet = (int*)malloc(tamanho*sizeof(int));
		if(vet == NULL){
			printf("Erro, memoria nao alocada.");
			exit(1);
			}
	/*aqui estou pedindo que o ususario informe os elementos do vetor, e savando em vet.*/
	for(int count = 0; count<tamanho; count++){
		printf("Digite o %dº elemento do vetor:\t", count+1);
		scanf("%d", &vet[count]);
		}
		/*aqui estou imprimindo os elementos na ordem inversa.*/
		printf("Vetor na ordem inversa:\n");
		for(int count = tamanho-1; count>=0; count--){
			printf("%d\n", vet[count]);
			}
		free(vet);
		return 0;
}