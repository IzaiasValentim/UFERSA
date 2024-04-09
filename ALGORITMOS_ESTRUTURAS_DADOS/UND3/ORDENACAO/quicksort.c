#include <stdio.h>

int particao(int inicio, int fim, int v[])
{
    int pivo = v[fim];
    int j = inicio - 1;
    int i;
    for (i = inicio; i < fim; i++)
    {
        if (v[i] <= pivo)
        {
            j++;
            int temp = v[j];
            v[j] = v[i];
            v[i] = temp;
        }
    }
    int temp = v[j + 1];
    v[j + 1] = v[fim];
    v[fim] = temp;
    return j + 1;
}

void quicksort(int i, int f, int v[])
{
    if (i < f)
    {
        int p = particao(i, f, v);
        quicksort(i, p - 1, v);
        quicksort(p + 1, f, v);
    }
}

int main(void)
{
    int n;
    printf("Informe a quantidade de valores do vetor: ");
    scanf("%d", &n);

    int v[n];
    printf("\nInforme os elementos: ");
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    printf("\nVetor nao ordenado: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }

    quicksort(0, n - 1, v);

    printf("\nVetor ordenado: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    return 0;
}