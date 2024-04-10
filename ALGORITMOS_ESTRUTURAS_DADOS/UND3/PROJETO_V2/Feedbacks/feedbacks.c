#include "../Usuarios/usuarios.h"
#include "../Categorias/categorias.h"
#include "feedbacks.h"
#include <stdio.h>
#include <string.h>

void cadastrarFeedback(Usuario usuarioComum)
{
    listarCategorias();
    char busca[30];

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("\nInforme o nome da categoria:\n");

    if (fgets(busca, 30, stdin) == NULL)
    {
        printf("Erro ao ler nome da categoria.\n");
        return;
    }
    if (buscarCategoria(busca) != 1)
    {
        return;
    }

    FILE *file_feedbacks = fopen("feedbacks.b", "ab");

    if (file_feedbacks == NULL)
    {
        printf("Erro ao abrir o arquivo de usu?rios.\n");
        return;
    }

    Feedback cadastro_feedback;

    strcpy(cadastro_feedback.username_autor, usuarioComum.username);
    strcpy(cadastro_feedback.nome_categoria, busca);

    printf("Informe o seu feedback\n");
    if (fgets(cadastro_feedback.texto, 200, stdin) == NULL)
    {
        printf("Erro ao coletar feedback.\n");
        fclose(file_feedbacks);
        return;
    }

    printf("Informe a nota para a categoria:\n");
    if (scanf("%f", &cadastro_feedback.nota) != 1)
    {
        printf("Erro ao ler nota.\n");
        fclose(file_feedbacks);
    }

    if (fwrite(&cadastro_feedback, sizeof(Feedback), 1, file_feedbacks) != 1)
    {
        printf("Erro ao escrever no arquivo de usu?rios.\n");
        fclose(file_feedbacks);
    }
    printf("Obrigado, salvo com sucesso!\n");
    fclose(file_feedbacks);
}

void listarFeedback()
{

    listarCategorias();
    char busca[30];

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("\nInforme o nome da categoria:\n");

    if (fgets(busca, 30, stdin) == NULL)
    {
        printf("Erro ao ler nome da categoria.\n");
        return;
    }
    if (buscarCategoria(busca) != 1)
    {
        return;
    }

    FILE *file_categorias = fopen("feedbacks.b", "rb");
    if (file_categorias == NULL)
    {
        printf("Erro ao acessar base de dados de feedbacks.\n");
    }

    Feedback mock_feedback;

    int cont = 0;
    while (fread(&mock_feedback, sizeof(Feedback), 1, file_categorias))
    {
        if (strcmp(mock_feedback.nome_categoria, busca) == 0)
        {
            printf("%d %s %s %.2f;\n", ++cont, mock_feedback.texto, mock_feedback.username_autor, mock_feedback.nota);
        }
    }

    fclose(file_categorias);
}

void calculoSatisfacao()
{

    listarCategorias();
    char busca[30];

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("\nInforme o nome da categoria:\n");

    if (fgets(busca, 30, stdin) == NULL)
    {
        printf("Erro ao ler nome da categoria.\n");
        return;
    }
    if (buscarCategoria(busca) != 1)
    {
        return;
    }

    FILE *file_categorias = fopen("feedbacks.b", "rb");
    if (file_categorias == NULL)
    {
        printf("Erro ao acessar base de dados de feedbacks.\n");
    }

    Feedback mock_feedback;

    int cont = 0;
    float soma = 0.0;

    while (fread(&mock_feedback, sizeof(Feedback), 1, file_categorias))
    {
        if (strcmp(mock_feedback.nome_categoria, busca) == 0)
        {
            soma += mock_feedback.nota;
            cont++;
        }
    }
    if (cont > 0)
    {
        printf("Satisfa??o m?dia do(a) %s ? %.1f pontos\n", busca, soma / cont);
    }
    else
    {
        printf("Ainda n?o foram registrados feedbacks para %s\n", busca);
    }

    fclose(file_categorias);
}
