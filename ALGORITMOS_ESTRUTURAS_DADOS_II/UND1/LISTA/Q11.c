#include <stdio.h>

// Item a)
int fatorial(int n, int acumulador)
{

    if (n == 1)
    {
        // O retorno é feito sem deixar chamdas recursivas pendentes.
        return n * acumulador;
    }
    acumulador *= n;
    return fatorial(n - 1, acumulador);
}

// Item b)
int itemB(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 2;
    }
    int A = 2 * itemB(n - 1);
    int B = 3 * itemB(n - 2);

    return A + B;
}

// Item C
int somatorioK(int k, int limite, int acc)
{
    if (k == limite)
    {
        return k + acc;
    }
    acc += k;

    return somatorioK(k + 1, limite, acc);
}

int main()
{
    int n = 1;
    printf("%d! = %d\n", n, fatorial(n, 1));
    printf("Item b) f(%d) = %d\n", n, itemB(n));
    printf("Item c) f(%d) = %d\n", n, somatorioK(1, n, 0));
    return 0;
}