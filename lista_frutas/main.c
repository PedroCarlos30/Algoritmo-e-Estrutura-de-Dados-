#include "lista_fruta.c"

int main(void){
    No * lista_de_frutas = NULL;
    int opcao;
    char nome_para_fruta[50];
    float valor_por_kg;
    //cria menu
    do{
        printf("1. cadastrar fruta\n");
        printf("2. Exibir lista de frutas\n");
        printf("3. Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite o nome da fruta: ");
            scanf(" %[^\n]", nome_para_fruta);
            printf("Digite o valor em (Kg): ");
            scanf("%f", &valor_por_kg);
            lista_de_frutas = inserirNoInicio(lista_de_frutas, nome_para_fruta, valor_por_kg);
            break;
        case 2:
            exibirListaDeFrutas(lista_de_frutas);
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }    
    }while(opcao != 3);
    return 0;
}