#include <stdio.h>
#include <string.h>

// Definindo valores padrões para a quantidade de receitas(N) e
// numero máximo de ingredientes

#define N 1
#define MAX_INGREDIENTES 15

// Definição da struct Ingrediente.
typedef struct Ingediente
{
    char nome[25];
    int quantidade;
} Ingredientes[MAX_INGREDIENTES];

// Definição da struct Receita.
typedef struct Receita
{
    char nome[25];
    int n_ingredientes;
    Ingredientes ingredientes;
} Receitas[N];

int main(void)
{   
    // Declarando as variáveis/struct.
    Receitas r;
    int i;
    int j;

    // Alimentação de cada ocorrência da struct
    for (i = 0; i < N; i++)
    {
        // Este primeiro for atua em cada posição da Receira r.
        int numero_i = 0;
        printf("\nInforme os dados da %d receita :", i + 1);
        printf("\n nome: ");
        fgets(r[i].nome, 25, stdin);

        printf("\n Numero de ingredientes: ");
        scanf("%d", &numero_i);
        // Limpa a entrada.
        fflush(stdin);

        r[i].n_ingredientes = numero_i;

        // Este segundo for recebe cada ingrediente de uma receita r(r.ingredientes).
        for (j = 0; j < numero_i; j++)
        {
        
            printf("\nInforme os dados do %d ingrediente :", j + 1);
            printf("\n nome: ");
            fgets(r[i].ingredientes[j].nome, 25, stdin);
            printf("\n quantidade do ingrediente: ");
            scanf("%d", &r[i].ingredientes[j].quantidade);
            fflush(stdin);
        }
        // Limpa a entrada.
        fflush(stdin);
    }

    // Saída das receitas.
    for (i = 0; i < N; i++)
    {
        printf("\nDados da %d receita:", i + 1);
        printf("\nNome: %s", r[i].nome);
        printf("\nIngredientes: ");

        for (j = 0; j < r[i].n_ingredientes; j++)
        {
            printf("\n Nome ingrediente: %s, quantidade: %d",
                   r[i].ingredientes[j].nome, r[i].ingredientes[j].quantidade);
        }
    }
    return 0;
}
