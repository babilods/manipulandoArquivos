//Bibliotecas que serão utilizados
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 //Maximo de alunos que poderão ser cadastrados
// Maximo de notas que podera ser digitada para cada aluno
#define MAX_NOME 50
#define MAX_NOTAS 2

void calcular_situacao_final(float nota1, float nota2, int divisor, float *media, char *situacao) {
    float soma = 0;

    //calculo da media das duas notas de cada aluno
    soma += nota1 + nota2;
    *media = soma / divisor;
    //Verificação se o aluno sera aprovado ou não
    if (*media >= 7.0) {
        strcpy(situacao, "APROVADO");
    } else {
        strcpy(situacao, "REPROVADO");
    }
}

int main() {
    //Arquivo que sera aberto para os dados
    FILE *entrada = fopen("DadosEntrada.csv", "r");
    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }
   // Arquuivo que foi feito para saida de dados ja com a Verificação de aprovação
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
       // entrada  de  dados para o arquivo 
       sscanf(linha, "%[^,],%*[^,],%*[^,],%lf,%lf", nome, &nota1, &nota2);

        divisor = 2; // Definindo o número que será divido, pois são apenas 2 notas
        // como o será a formatação de cada um dos alunos 
        calcular_situacao_final(nota1, nota2, divisor, &media, situacao);
        fprintf(saida, "%s,%.2f,%s\n", nome, media, situacao);
    }
    // printar o sucesso do codigo 
    printf("Arquivo gerado com sucesso.\n");

    fclose(entrada);
    fclose(saida);

    return 0;
}
