#include <stdio.h>
#include <stdlib.h>

// Protótipos.
void entrada_matriz(int linhas, int colunas, int **matriz);

void saida_original(int linhas, int colunas, int **matriz);

void saida_transposta(int linhas, int colunas, int **matriz);

int main(void)
{

    int linhas, colunas;
    int indice;
    int linha, coluna;
    printf("Informe as dimensões da Matriz A[l,c]\n");

    printf("Linhas: \n");
    scanf("%d", &linhas);

    printf("Colunas: \n");
    scanf("%d", &colunas);

    // Alocando o vetor de ponteiros
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    // Verificando alocação.
    if (matriz == NULL)
    {
        printf("Erro ao alocar matriz");
        exit(1);
    }
    // Alocando vetores de cada linha;
    for (indice = 0; indice < colunas; indice++)
    {
        matriz[indice] = (int *)malloc(colunas * sizeof(int));
        if (matriz[indice] == NULL)
        {
            printf("Erro ao alocar coluna");
            exit(1);
        }
    }

    system("clear");
    // Alimentando a matriz;
    entrada_matriz(linhas, colunas, matriz);

    system("clear");
    // Impressão da matriz original:
    saida_original(linhas, colunas, matriz);

    // Impressão da matriz transposta:
    saida_transposta(linhas, colunas, matriz);

    // Liberação de memória da matriz:
    for (linha = 0; linha < linhas; linha++)
    {
        // Free em cada vetor de linha;
        free(matriz[linha]);
    }
    // Free para o vetor de endereços:
    free(matriz);
    printf("FIM!\n");
    return 0;
}

void entrada_matriz(int linhas, int colunas, int **matriz)
{
    int linha, coluna;
    printf("Informe os elementos da matriz:");

    for (linha = 0; linha < linhas; linha++)
    {
        for (coluna = 0; coluna < colunas; coluna++)
        {
            printf("\nA[%d,%d] -", linha + 1, coluna + 1);
            scanf("%d", &matriz[linha][coluna]);
        }
    }
}

void saida_original(int linhas, int colunas, int **matriz)
{
    int linha, coluna;
    printf("Matriz original:");

    for (linha = 0; linha < linhas; linha++)
    {
        printf("\n[ ");
        for (coluna = 0; coluna < colunas; coluna++)
        {

            printf(" %d ", matriz[linha][coluna]);
        }
        printf("]\n");
    }
}

void saida_transposta(int linhas, int colunas, int **matriz)
{
    int linha, coluna;
    printf("\nMatriz transposta:");

    for (coluna = 0; coluna < colunas; coluna++)
    {
        printf("\n[ ");
        for (linha = 0; linha < linhas; linha++)
        {

            printf(" %d ", matriz[linha][coluna]);
        }
        printf("]\n");
    }
}