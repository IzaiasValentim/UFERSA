#include <stdio.h>
#include <string.h>
// a
int produtoRecursivo(int a, int b, int cont, int som)
{
    if (cont == b)
    {
        return a + som;
    }
    som += a;
    return produtoRecursivo(a, b, ++cont, som);
}

// b
int divisaoRecursiva(int a, int b, int div)
{
    if (a == 0)
    {
        return div;
    }
    else if (a < 0)
    {
        printf("[A divisao não é inteira]\n");
        return 0;
    }

    ++div;
    return divisaoRecursiva(a - b, b, div);
}

// d
void inverterString(char *str, int inicio, int fim)
{
    if (inicio >= fim)
    {
        return;
    }

    char temp = str[inicio];
    str[inicio] = str[fim];
    str[fim] = temp;

    inverterString(str, inicio + 1, fim - 1);
}

int main()
{
    // a)
    int a = 2, b = 3;
    printf("%d x %d = %d\n", a, b, produtoRecursivo(a, b, 1, 0));

    // b)
    a = 168, b = 2;
    printf("%d / %d = %d\n", a, b, divisaoRecursiva(a, b, 0));

    // Item c ??

    // Item d
    char str[100] = "Oieeee";
    char cpy[100];

    strcpy(cpy, str);
    int tamanho = strlen(str);

    inverterString(str, 0, tamanho - 1);

    printf("A string [%s] invertida: %s\n", cpy, str);

    // Item e ??
    return 0;
}