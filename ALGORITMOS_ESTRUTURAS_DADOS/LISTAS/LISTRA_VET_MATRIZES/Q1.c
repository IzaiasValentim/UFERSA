#include <stdio.h>
#include <stdlib.h>

void entrada(int tamanho, int *v);

int main(void)
{

    int tamanhoVetor;

    // Obtenção do tamanho do vetor.
    printf("Qual o tamanho do vetor que deseja criar? \n");
    scanf("%d", &tamanhoVetor);

    // Alocação de memória para o vetor.
    int *vetor = (int *)malloc(tamanhoVetor * sizeof(int));

    // Verificação se a memoria foi alocada.
    if (vetor == NULL)
    {
        printf("\nErro ao alocar memória para o vetor");
        exit(1);
    }
    // Função que obtem os valores das posições do vetor;
    entrada(tamanhoVetor, vetor);

    // Impressão do vetor na ordem inversa.
    int indice;
    printf("O vetor na ordem inversa: \n");
    for (indice = tamanhoVetor - 1; indice >= 0; indice--)
    {

        printf("[%d] - %d \n", indice + 1, vetor[indice]);
    }

    // Liberar memória que foi alocada para o vetor.
    free(vetor);

    return 0;
}

void entrada(int tamanho, int *v)
{
    printf("Informe os elemtnos para compor o vetor: \n");
    int indice;
    for (indice = 0; indice < tamanho; indice++)
    {
        printf("%d- ", indice + 1);
        scanf("%d", &v[indice]);
    }
}