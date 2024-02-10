#include <stdio.h>

// Definindo valor padrão para a quantidade de alunos;
#define N 5

// Struct Aluno.
typedef struct Aluno
{
    char matricula[12];
    char nome[30];
    float p1;
    float p2;
    float p3;
} Alunos[N];

// Protótipos das funções utilizadas.
void MaiorNota(Alunos alunos);

void MaiorMedia(Alunos alunos);

int main(void)
{

    // Declaração do contador e struct
    int i;
    Alunos aluno;

    //  Entrada dos dados dos alunos.
    for (i = 0; i < N; i++)
    {

        printf("Informe os dados do aluno: %d\n", i + 1);
        printf("Nome: ");
        fgets(aluno[i].nome, 30, stdin);
        printf("Matricula: ");
        fgets(aluno[i].matricula, 12, stdin);

        printf("Primeira nota:");
        scanf("%f", &aluno[i].p1);

        printf("Segunda nota:");
        scanf("%f", &aluno[i].p2);

        printf("Terceira nota:");
        scanf("%f", &aluno[i].p3);
        // Limpa a entrada
        fflush(stdin);
        printf("\n");
    }

    // Chamando as funções.
    MaiorNota(aluno);
    MaiorMedia(aluno);

    return 0;
}
void MaiorNota(Alunos alunos)
{
    int i;
    float p1_maior = 0;
    int indice_und;
    // For para determinar o indice da maior nota na primeira unidade.
    for (i = 0; i < N; i++)
    {
        if (alunos[i].p1 >= p1_maior)
        {
            p1_maior = alunos[i].p1;
            indice_und = i;
        }
    }
    printf("Maior nota na primeira unidade: Aluno: %s - Nota: %.1f\n", alunos[indice_und].nome, p1_maior);
    fflush(stdin);
}
void MaiorMedia(Alunos alunos)
{
    // Criação de um vetor exclusivo para salva as médias.
    float medias[N];

    // Variáveis auxiliares para o cálculo da maior e menor média.
    float maior_media = 0;
    int indice_maior;
    float menor_media = 10;
    int indice_menor;

    // For calcula e verifica a maior e menor media entre todas e salva o indíce de cada ocorrência.
    for (int i = 0; i < N; i++)
    {

        medias[i] = (alunos[i].p1 + alunos[i].p2 + alunos[i].p3) / (float)3;

        if (medias[i] >= maior_media)
        {
            maior_media = medias[i];
            indice_maior = i;
        }

        if (medias[i] <= menor_media)
        {
            menor_media = medias[i];
            indice_menor = i;
        }
    }
    printf("\nResultados:");

    // Saida do aluno com maior e menor média.
    printf("\nAluno com maior media: %s - media: %.1f", alunos[indice_maior].nome, medias[indice_maior]);
    printf("\nAluno com a menor media: %s - media: %.1f", alunos[indice_menor].nome, medias[indice_menor]);

    // Resultado geral de cada aluno.
    for (int i = 0; i < N; i++)
    {
        if (medias[i] >= 6)
        {
            printf("\nAluno: %s - media: %.1f aprovado", alunos[i].nome, medias[i]);
        }
        else
        {
            printf("\nAluno: %s - media: %.1f reprovado", alunos[i].nome, medias[i]);
        }
    }
    fflush(stdin);
}