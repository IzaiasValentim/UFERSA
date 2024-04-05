#include <stdio.h>

void inserction_sort(int v[], int n);

int main(void)
{
    int n;
    printf("Informe a quantidade de elementos do vetor: ");
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

    inserction_sort(v, n);

    printf("\nVetor ordenado:");
    for (i = 0; i < n; i++)
    {
        printf(" %d", v[i]);
    }
    
    return 0;
}

void inserction_sort(int v[], int n)
{
    int i, j;
    // Começa em 1 por o indice 0 por definição já está ordenado.
    for (i = 1; i < n; i++)
    {
        int x = v[i];
        for (j = i - 1; j >= 0 && x < v[j]; j--)
        {
            v[j + 1] = v[j];
        }
        v[j + 1] = x;
    }
}