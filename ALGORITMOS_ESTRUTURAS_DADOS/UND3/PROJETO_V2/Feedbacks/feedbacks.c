#include "../Usuarios/usuarios.h"
#include "../Categorias/categorias.h"
#include "feedbacks.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Feedback *inicio_lista_feedbacks = NULL;

void carregarListaFeedbacks() {
    FILE *file_feedbacks = fopen("feedbacks.b", "rb");
    if (file_feedbacks == NULL) {
        printf("Arquivo de feedbacks nao encontrado ou vazio.\n");
        return;
    }

    Feedback novo_feedback;
    while (fread(&novo_feedback, sizeof(Feedback), 1, file_feedbacks)) {
        Feedback *novo_no = (Feedback *)malloc(sizeof(Feedback));
        if (novo_no == NULL) {
            printf("Erro ao alocar memoria para feedback.\n");
            fclose(file_feedbacks);
            return;
        }
		memcpy(novo_no, &novo_feedback, sizeof(Feedback));
        novo_no->prox = inicio_lista_feedbacks;
        inicio_lista_feedbacks = novo_no;
    }
    fclose(file_feedbacks);
}

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
	
	Feedback *novo_feedback = (Feedback*) malloc(sizeof(Feedback));
 	
 	if (novo_feedback == NULL)
    {
        printf("Erro ao alocar memoria para o feedback.\n");
        return;
    }
 	
    FILE *file_feedbacks = fopen("feedbacks.b", "ab");

    if (file_feedbacks == NULL)
    {
        printf("Erro ao abrir o arquivo de usuarios.\n");
        return;
    }

    
    strcpy(novo_feedback->username_autor, usuarioComum.username);
    strcpy(novo_feedback->nome_categoria, busca);

    printf("Informe o seu feedback\n");
    if (fgets(novo_feedback->texto, 200, stdin) == NULL)
    {
        printf("Erro ao coletar feedback.\n");
        fclose(file_feedbacks);
        return;
    }

    printf("Informe a nota para a categoria:\n");
    if (scanf("%f", &novo_feedback->nota) != 1)
    {
        printf("Erro ao ler nota.\n");
        fclose(file_feedbacks);
    }
    
    novo_feedback->prox = inicio_lista_feedbacks;
    inicio_lista_feedbacks = novo_feedback;

    if (fwrite(novo_feedback, sizeof(Feedback), 1, file_feedbacks) != 1)
    {
        printf("Erro ao escrever no arquivo de usuarios.\n");
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

int numeroFeedbacksCadastrados() {
    int contador = 0;
    Feedback *atual = inicio_lista_feedbacks;

    while (atual != NULL) {
        contador++; 
        atual = atual->prox; 
    }

    return contador;
}

void ordenarFeedbackPorNota() {
    FILE *file_feedbacks = fopen("feedbacks.b", "rb+");
    if (file_feedbacks == NULL) {
        printf("Erro ao abrir o arquivo de feedbacks para ordenacao.\n");
        return;
    }
	
	int num_feedbacks = numeroFeedbacksCadastrados();
    
	Feedback feedbacks[num_feedbacks];
    fread(feedbacks, sizeof(Feedback), num_feedbacks, file_feedbacks);
    
	if (num_feedbacks == 0) {
        printf("Nao ha feedbacks para ordenar.\n");
        fclose(file_feedbacks);
        return;
    }
	int i,j;
    // Algoritmo de ordena??o - Bubble Sort
    for (i = 0; i < num_feedbacks - 1; i++) {
        for (j = 0; j < num_feedbacks - i - 1; j++) {
            if (feedbacks[j].nota < feedbacks[j + 1].nota) {
                
                Feedback temp = feedbacks[j];
                feedbacks[j] = feedbacks[j + 1];
                feedbacks[j + 1] = temp;
            
			}
        }
    }

    // Escreve os feedbacks ordenados de volta no arquivo
    rewind(file_feedbacks);
    fwrite(feedbacks, sizeof(Feedback), num_feedbacks, file_feedbacks);

    fclose(file_feedbacks);
    printf("Feedbacks ordenados com sucesso.\n");
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

    FILE *file_feedbacks = fopen("feedbacks.b", "rb");
    if (file_feedbacks == NULL)
    {
        printf("Erro ao acessar base de dados de feedbacks.\n");
    }

    Feedback mock_feedback;

    int cont = 0;
    float soma = 0.0;

    while (fread(&mock_feedback, sizeof(Feedback), 1, file_feedbacks))
    {
        if (strcmp(mock_feedback.nome_categoria, busca) == 0)
        {
            soma += mock_feedback.nota;
            cont++;
        }
    }
    if (cont > 0)
    {
        printf("Satisfaco media do(a) %s e %.1f pontos\n", busca, soma / cont);
    }
    else
    {
        printf("Ainda nao foram registrados feedbacks para %s\n", busca);
    }

    fclose(file_feedbacks);
}
