#include <stdio.h>

int fatorial(int n, int f)
{

    if (n == 1)
    {
        return f;
    }
    else
    {
        return fatorial(n - 1, n * f);
    }
}

void main()
{

    int n = 3;
    printf("O fatorial de %d e: %d", n, fatorial(n, 1));
}