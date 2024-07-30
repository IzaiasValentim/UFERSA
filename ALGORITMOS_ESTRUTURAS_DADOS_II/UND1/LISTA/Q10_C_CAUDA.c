#include <stdio.h>

int recursaoCauda(int x, int n, int resultado)
{
    if (n == 0)
    {
        // Ultimo retorno.
        return x * resultado;
    }
    resultado *= (x - n);
    // Quando está chamada é feita não deixa outras funções pendentes.
    return recursaoCauda(x, n - 1, resultado);
}

int main()
{
    printf("%d", recursaoCauda(5, 3, 1));

    return 0;
}
