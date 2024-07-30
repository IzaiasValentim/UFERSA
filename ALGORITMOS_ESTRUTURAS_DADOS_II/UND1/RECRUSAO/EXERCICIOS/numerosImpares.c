#include <stdio.h>

void ordemCrescente(int n)
{
    if (n >= 1)
    {
        ordemCrescente(n - 1);
        if (n % 2 != 0)
        {
            printf("%d ", n);
        }
    }
}

void ordemDecrescente(int n)
{
    if (n >= 1)
    {
        if (n % 2 != 0)
        {
            printf("%d ", n);
        }
        return ordemDecrescente(n - 1);
    }
}

void main()
{
    int n = 5;
    printf("Impares na Ordem 1 -> %d: ", n);
    ordemCrescente(n);
    printf("\n");
    printf("Impares na Ordem %d -> 1: ", n);
    ordemDecrescente(n);
}