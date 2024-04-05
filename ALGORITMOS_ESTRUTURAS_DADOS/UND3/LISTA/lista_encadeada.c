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
    printf("2 - Mostrar lista\n");
    printf("0 - sair\n");
}
void InserirNoInicio(Lista_Estudante *lista, Estudante dado)
{
    struct No *novo = (struct No *)malloc(sizeof(struct No));
    novo->dado = dado;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
}

void MostrarLista(Lista_Estudante lista)
{
    printf("-- Dados na lista: --\n");
    struct No *ponteiroCorrente = lista.inicio;
    int cont = 0;
    while (ponteiroCorrente != NULL)
    {
        printf("%d - %s - %d\n", ++cont, ponteiroCorrente->dado.nome, ponteiroCorrente->dado.mat);
        ponteiroCorrente = ponteiroCorrente->proximo;
    }
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
        else if (operacao == 2)
        {
            MostrarLista(lista);
        }
        else
        {
            printf("\nBye");
        }
    } while (operacao != 0);

    return 0;
}