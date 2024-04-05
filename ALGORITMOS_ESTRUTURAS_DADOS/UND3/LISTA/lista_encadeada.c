#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int mat;
    char nome[100];
} Estudante;

struct No
{
    Estudante dado;
    struct No *proximo;
};

typedef struct
{
    struct No *inicio;
} Lista_Estudante;

void LerEstudante(Estudante *estudante)
{
    scanf("%d %s", &estudante->mat, estudante->nome);
}

void menu()
{
    printf("-- Escolha uma opcao --\n");
    printf("1 - inserir novo estudante\n");
    printf("2 - sair\n");
}
void InserirNoInicio(Lista_Estudante *lista, Estudante dado)
{
    struct No *novo = (struct No *)malloc(sizeof(struct No));
    novo->dado = dado;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
}

int main()
{
    Lista_Estudante lista;
    lista.inicio = NULL;
    int operacao;
    do
    {
        menu();
        scanf("%d", &operacao);
        if (operacao == 1)
        {
            Estudante e;
            LerEstudante(&e);
            InserirNoInicio(&lista, e);
        }
        else
        {
            printf("\nBye");
        }
    } while (operacao != 2);

    return 0;
}