#include <stdio.h>

void selection_sort(int v[], int n);

int main(void)
{
    int n;
    printf("Informe o tamanho do vetor");
    scanf("%d", &n);

    int v[n];
    int i;

    printf("\nInforme os elementos do vetor: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    printf("\nVetor não ordenado:");
    for (i = 0; i < n; i++)
    {
        printf(" %d", v[i]);
    }
    
    // Ordena o vetor.
    selection_sort(v,n);

    printf("\nVetor ordenado:");
     for (i = 0; i < n; i++)
    {
        printf(" %d", v[i]);
    }
    return 0;
}

void selection_sort(int v[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        // Considerado este indice como o do menor elemento.
        int imenor = i;
        for (j = i + 1; j < n; j++)
        {
            // Neste laço compara os valores do indice anterior com o dos elemtos restantes.
            if (v[j] < v[i])
            {
                // Caso haja um menor, este sera o novo valor do indice.
                imenor = j;
            }
        }

        // Troca
        int temp = v[i];
        v[i] = v[imenor];
        v[imenor] = temp;
    }
}
