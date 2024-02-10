#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Declaração das variáveis utilizadas.
    int *vetor, tamanho, i;

    // Entrada do tamanho do vetor.
    printf("Infore o tamanho do vetor: ");
    scanf("%d", &tamanho);

    // Alocação dinâmica da memória com malloc.
    vetor = (int *)malloc(tamanho * sizeof(int));
    // Valida a alocação.
    if (vetor == NULL)
    {
        printf("Erro ao alocar memoria");
        return 1;
    }

    // Armazena os valores em cada indíce e exibe o vetor.
    printf("\nVetor: ");
    for (i = 0; i < tamanho; i++)
    {
        *(vetor + i) = i;
        printf("%d", vetor[i]);
    }

    // Dois primeiros e dois últimos.
    printf("\nDois primeiros e Dois ultimos elementos: ");
    for (i = 0; i < tamanho; i++)
    {
        if (i <= 1)
        {
            printf("%d", *(vetor + i));
        }
        else if (i >= (tamanho - 2))
        {
            printf("%d", *(vetor + i));
        }
    }

    // Limpando a memória alocada para o ponteiro.
    free(vetor);
    return 0;
}