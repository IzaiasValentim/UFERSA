#include <stdio.h>

int fatorialRecursivo(int n)
{
    // Passo base/âncora
    if (n == 0)
    {
        return 1;
    }
    else
    {
        // Passo indutivo de construção.
        return n * fatorialRecursivo(n - 1);
    }
}

int main()
{
    int n = 6;

    // Saída   
    printf("O fatorial de %d e %d", n, fatorialRecursivo(n));
    return 0;
}