#include <stdio.h>
#include <stdlib.h>

FILE *open_file(char *nome, char *modo)
{
    FILE *arquivo = fopen(nome, modo);
    if (arquivo == NULL)
    {
        printf("cant`t create file.");
        exit(1);
    }
    else
    {
        printf("File open!\n");
    }
    return arquivo;
}
int main(void)
{
    FILE *arquivo_de_entrada, *arquivo_de_saida;
    arquivo_de_entrada = open_file("entrada.txt", "r");
    arquivo_de_saida = open_file("saida.txt", "w");
    float nota1, nota2, nota3, media;
    char nome_aluno[20];
    while (!feof(arquivo_de_entrada))
    {
        fscanf(arquivo_de_entrada, "%20[^\t]\t%f\t%f\t%f\n", nome_aluno, &nota1, &nota2, &nota3);
        media = (nota1 + nota2 + nota3) / 3;
        if (media >= 7)
        {
            fprintf(arquivo_de_saida, "%s\t%.1f\tAprovado\n", nome_aluno, media);
        }
        else
        {
            fprintf(arquivo_de_saida, "%s\t%.1f\tReprovado\n", nome_aluno, media);
        }
    }
    return 0;
}