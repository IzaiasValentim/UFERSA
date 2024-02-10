#include <stdio.h>
#include <stdlib.h>

struct Aluno
{
    char nome[40];
    float media;
    int faltas;
};

int main(void)
{
    // Declaração dos ponteiros do tipo struct Aluno e demais variáveis.
    struct Aluno *alunos;
    struct Aluno *temp;
    int numero_alunos, i, j;

    printf("Informe a quantidade de alunos: ");
    scanf("%d", &numero_alunos);

    // Alocação dinâmica da lista de alunos de acordo com a quantidade solicitada.
    alunos = (struct Aluno *)malloc(numero_alunos * sizeof(struct Aluno));

    // Alocação dinâmica do ponteiro de posição temporária.
    temp = (struct Aluno *)malloc(1 * sizeof(struct Aluno));

    // Validação das alocações.
    if (alunos == NULL || temp == NULL)
    {
        printf("Erro ao alocar memoria");
        return 1;
    }

    // Alimentação da lista.
    for (i = 0; i < numero_alunos; i++)
    {
        printf("\nInforme os dados do %d aluno:", i + 1);
        printf("\nNome:");
        scanf("%s", alunos[i].nome);
        printf("\nMedia:");
        scanf("%f", &alunos[i].media);
        printf("\nFaltas:");
        scanf("%d", &alunos[i].faltas);
    }

    // Algoritmo bubble sort para ordenação da lista com base nas notas.
    for (i = 0; i < numero_alunos - 1; i++)
    {
        for (j = 0; j < (numero_alunos - i - 1); j++)
        {
            if (alunos[j + 1].media > alunos[j].media)
            {
                *temp = *(alunos + j);
                *(alunos + j) = *(alunos + j + 1);
                *(alunos + j + 1) = *temp;
            }
        }
    }

    // Retorno da lista ordenada.
    printf("\nLista ordenada por nota de alunos:");
    for (i = 0; i < numero_alunos; i++)
    {
        printf("\naluno[%d]: %s - media: %.1f - faltas: %d", i + 1, alunos[i].nome, alunos[i].media, alunos[i].faltas);
    }
    
    // Liberação da memória.
    free(alunos);
    free(temp);

    return 0;
}