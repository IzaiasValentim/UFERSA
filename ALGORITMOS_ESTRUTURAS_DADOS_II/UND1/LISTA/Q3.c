#include <stdio.h>

// Contador para armazenar a ocorrência.
int contador = 0;
int termoCalculado = 0;
int fibonacci(int n)
{
    // Se fibonacci(termoCalculado) for chamada, o contador é incrementado.
    if (n == termoCalculado)
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
    // Obtem quantos termos da sequencia irão ser calculados no total.
    int termosTotaisFibo = 0;
    printf("Informe um número de termos a ser calculado(>4).");
    scanf("%d", &termosTotaisFibo);
    
    // Obtém o termo que deseja verificar a ocorrencia. Com a condição termosTotaisFibo > termoCalculado.
    do
    {
        printf("Qual o termo que deseja saber quantas vezes foi calculado?(termo < %d)", termosTotaisFibo);
        scanf("%d", &termoCalculado);

    } while (termoCalculado >= termosTotaisFibo);

    int res = fibonacci(termosTotaisFibo);
    
    // Saída.
    printf("fibonacci(%d): %d- fibonacci(%d) foi calculados %d vezes.",
         termosTotaisFibo, res, termoCalculado, contador);
    return 0;
}