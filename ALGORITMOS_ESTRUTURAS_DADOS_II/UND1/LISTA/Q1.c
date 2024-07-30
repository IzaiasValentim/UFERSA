#include <stdio.h>

// Contador para armazenar a ocorrência.
int contador = 0;

int fibonacci(int n)
{
    // Se fibonacci(4) for chamada, o contador é incrementado.
    if (n == 4)
    {
        contador++;
    }

    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    fibonacci(8);
    printf("fibonacci(4) foi calculados %d vezes.", contador);
    return 0;
}