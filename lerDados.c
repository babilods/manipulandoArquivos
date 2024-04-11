#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_NOTAS 2

void calcular_situacao_final(float nota1, float nota2, int divisor, float *media, char *situacao) {
    float soma = 0;

    soma += nota1 + nota2;
    *media = soma / divisor;

    if (*media >= 7.0) {
        strcpy(situacao, "APROVADO");
    } else {
        strcpy(situacao, "REPROVADO");
    }
}

int main() {
    FILE *entrada = fopen("DadosEntrada.csv", "r");
    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    FILE *saida = fopen("SituacaoFinal.csv", "w");
    if (saida == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        fclose(entrada);
        return 1;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), entrada)) {
        //Aluno aluno;
        char nome[MAX_NOME];
        double  nota1;
        double  nota2;
        int divisor;
        float media;
        char situacao[10];

       sscanf(linha, "%[^,],%*[^,],%*[^,],%lf,%lf", nome, &nota1, &nota2);

        divisor = 2; // Definindo o número que será divido, pois são apenas 2 notas

        calcular_situacao_final(nota1, nota2, divisor, &media, situacao);
        fprintf(saida, "%s,%.2f,%s\n", nome, media, situacao);
    }

    printf("Arquivo gerado com sucesso.\n");

    fclose(entrada);
    fclose(saida);

    return 0;
}
