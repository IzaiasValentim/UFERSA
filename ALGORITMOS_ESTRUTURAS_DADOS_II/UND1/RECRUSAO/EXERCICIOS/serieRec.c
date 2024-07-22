#include <stdio.h>

// Escreva uma funçao recursiva para adicionar os primeiros n termos da série: 1 + 1/2 -1/3 + 1/4 - 1/5...

float serie(int n)
{
    if (n == 1)
    {
        return 1.0;
    }
    else
    {
        if (n % 2 == 0)
        {
            return serie(n - 1) + 1.0 / n;
        }
        else
        {
            return serie(n - 1) - 1.0 / n;
        }
    }
}

int main()
{
    printf("%f", serie(5));
    return 0;
}