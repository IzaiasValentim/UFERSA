typedef struct categoria
{
    char nome_categoria[30];
    char username_admin_cadastro[20];
    char retorno_categoria[200];

}Categoria;


void cadastrarCategoria(Usuario userAdmin);
void listarCategorias();
int buscarCategoria(char *busca);
void atualizarCategoria(Usuario userAdmin, char *nomeCategoria, char *retornoFeedback);
void deletarCategoria(char *nomeCategoria);
int numeroCategorias();