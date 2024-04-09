#include "../Usuarios/usuarios.h"
#include "categorias.h"
#include <stdio.h>
#include <string.h>

void cadastrarCategoria(Usuario userAdmin)
{
    FILE *file_categorias = fopen("categorias.b", "ab");

    if (file_categorias == NULL)
    {
        printf("Erro ao acessar base de dados das categorias.\n");
        return;
    }

    Categoria cadastro_categoria;
    if (userAdmin.username != NULL)
    {
        strcpy(cadastro_categoria.username_admin_cadastro, userAdmin.username);
    }
    else
    {
        printf("Erro na indentificação do administrador da categoria");
        return;
    }

    printf("1 - Criar categoria.\n");
    printf("Informe o nome da categoria:\n");

    // Limpa o buffer do stdin
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    if (fgets(cadastro_categoria.nome_categoria, 30, stdin) == NULL)
    {
        printf("Erro ao ler nome da categoria.\n");
        fclose(file_categorias);
        return;
    }

    strcpy(cadastro_categoria.retorno_categoria, "");

    if (fwrite(&cadastro_categoria, sizeof(Categoria), 1, file_categorias) != 1)
    {
        printf("Erro ao escrever na base de dados das categorias.\n");
        fclose(file_categorias);
        return;
    }

    fclose(file_categorias);
    printf("Categoria cadastrada com sucesso!");
    return;
}

void listarCategorias()
{
    FILE *file_categorias = fopen("categorias.b", "rb");
    if (file_categorias == NULL)
    {
        printf("Erro ao acessar base de dados das categorias.\n");
    }
    Categoria mock_categoria;

    int cont = 0;
    printf("2 - Vizualizar categorias:\n");
    while (fread(&mock_categoria, sizeof(Categoria), 1, file_categorias))
    {
        printf("\t%d-Nome: %s - R: %s;\n",
               ++cont, mock_categoria.nome_categoria, mock_categoria.retorno_categoria);
    }

    fclose(file_categorias);
}

int buscarCategoria(char *busca)
{

    FILE *file_categorias = fopen("categorias.b", "rb");
    if (file_categorias == NULL)
    {
        printf("Erro ao acessar base de dados das categorias.\n");
    }
    Categoria mock_categoria;

    printf("2 - Vizualizar categorias:\n");
    while (fread(&mock_categoria, sizeof(Categoria), 1, file_categorias))
    {
        if (strcmp(busca, mock_categoria.nome_categoria) == 0)
        {
            strcpy(busca, mock_categoria.nome_categoria);
            return 1;
        }
    }

    fclose(file_categorias);
    return 0;
}

void atualizarCategoria(Usuario userAdmin, char *nomeCategoria, char *retornoFeedback)
{
    int numero = numeroCategorias();
    Categoria cats[numero];

    FILE *file_categorias = fopen("categorias.b", "rb");

    int i = 0;
    while (fread(&cats[i], sizeof(Categoria), 1, file_categorias))
    {
        i++;
    }
    fclose(file_categorias);

    file_categorias = fopen("categorias.b", "wb");
    for (i = 0; i < numero; i++)
    {

        if (strcmp(cats[i].nome_categoria, nomeCategoria) == 0)
        {

            if (retornoFeedback == NULL)
            {
                // Neste caso o nome da categoria é atualizado.
                char novoNome[30];
                printf("Informe o novo nome da categoria:\n");

                if (fgets(novoNome, 30, stdin) == NULL)
                {
                    printf("Erro ao ler nome da categoria.\n");
                    fclose(file_categorias);
                    return;
                }
                strcpy(cats[i].nome_categoria, novoNome);
                strcpy(cats[i].username_admin_cadastro, userAdmin.username);
            }
            else
            {
                // Neste caso é cadastrado um retono para a categoria.
                strcpy(cats[i].retorno_categoria, retornoFeedback);
            }
        }

        fwrite(&cats[i], sizeof(Categoria), 1, file_categorias);
    }
    fclose(file_categorias);
    printf("Processo de alteração finalizado!");
    return;
}

void deletarCategoria(char *nomeCategoria)
{
    int numero = numeroCategorias();
    Categoria cats[numero];

    FILE *file_categorias = fopen("categorias.b", "rb");

    int i = 0;
    while (fread(&cats[i], sizeof(Categoria), 1, file_categorias))
    {
        i++;
    }
    fclose(file_categorias);

    file_categorias = fopen("categorias.b", "wb");
    for (i = 0; i < numero; i++)
    {
        if (strcmp(cats[i].nome_categoria, nomeCategoria) == 0)
        {
            fwrite(&cats[i], sizeof(Categoria), 1, file_categorias);
        }
    }
    fclose(file_categorias);
    printf("Processo de exclusão finalizado!");
    return;
}

int numeroCategorias()
{
    FILE *file_categorias = fopen("categorias.b", "rb");
    if (file_categorias == NULL)
    {
        printf("Erro ao acessar base de dados das categorias.\n");
    }
    Categoria mock_categoria;

    int numero = 0;

    while (fread(&mock_categoria, sizeof(Categoria), 1, file_categorias))
    {
        numero++;
    }
    fclose(file_categorias);
    return numero;
}

