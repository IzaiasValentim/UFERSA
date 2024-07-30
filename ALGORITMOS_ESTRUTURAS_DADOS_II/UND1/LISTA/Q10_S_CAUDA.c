#include <stdio.h>

int recursaoCauda(int x, int n)
{
    if (n == 0)
    {
        return x;
    }
    // Não é a ultima operação realizada, pois irão haver outras camadas da recursão antes do retorno.
    return (x - n) * recursaoCauda(x, n - 1);
}

int main()
{
    printf("%d", recursaoCauda(5, 3));

    return 0;
}
