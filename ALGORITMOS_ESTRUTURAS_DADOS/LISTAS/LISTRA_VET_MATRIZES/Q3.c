#include <stdio.h>
#include <stdlib.h>

void preencher_matriz(int ordem, int **matriz);

void vizualizar_matriz(int ordem, int **matriz);

int main(void)
{

    int ordem;
    printf("Informe a ordem da Matriz quadrada(até 10): \n");

    do
    {
        scanf("%d", &ordem);
        if (ordem > 10)
        {
            printf("Informe uma ordem de até 10\n");
        }

    } while (ordem > 10);
    int linhas = ordem, colunas = ordem, indice;

    int **matriz = (int **)malloc(linhas * sizeof(int *));
    if (matriz == NULL)
    {
        printf("Erro ao alocar matriz\n");
        exit(1);
    }
    for (indice = 0; indice < linhas; indice++)
    {

        matriz[indice] = (int *)malloc(colunas * sizeof(int));

        if (matriz[indice] == NULL)
        {
            printf("Erro ao alocar matriz\n");
            exit(1);
        }
    }

    preencher_matriz(ordem, matriz);

    printf("Resultado da matriz M%dx%d", ordem, ordem);

    vizualizar_matriz(ordem, matriz);

    // Liberando memória alocada para a matriz.
    for (indice = 0; indice < ordem; indice++)
    {
        free(matriz[indice]);
    }

    free(matriz);
    printf("\nFim!\n\n");
    return 0;
}

void preencher_matriz(int ordem, int **matriz)
{
    int linha, coluna;
    int numero;
    for (linha = 0; linha < ordem; linha++)
    {
        for (coluna = 0; coluna < ordem; coluna++)
        {
            matriz[linha][coluna] = 1 + (rand() % 100);
        }
    }
}

void vizualizar_matriz(int ordem, int **matriz)
{
    int linha, coluna;

    for (linha = 0; linha < ordem; linha++)
    {
        printf("\n[");
        for (coluna = 0; coluna < ordem; coluna++)
        {
            printf(" %d ", matriz[linha][coluna]);
        }
        printf("]");
    }
}
