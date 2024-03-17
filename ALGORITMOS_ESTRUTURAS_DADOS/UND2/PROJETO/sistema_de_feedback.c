#include <stdio.h>

// windows.h -> para função Sleep.
#include <windows.h>

// para setlocale
#include <locale.h>

#include <string.h>

typedef struct user
{
    char username[20];
    int matricula;
    char email[79];
    char senha[20];
    int usuario_admin;

} Usuario;

typedef struct categoria
{
    char nome_categoria[30];
    char username_admin_cadastro[20];
    char retorno_categoria[200];

} Categoria;

typedef struct feedback
{

    char username_autor[20];
    char texto[200];
    float nota;
    char nome_categoria[30];

} Feedback;

// Protótipos das funções de navegação.
int menuInicialLoginCadastro();
int menuLogin(Usuario *usuario);
int cadastroUsuario();
int menuUserComum(Usuario *usuario);
int menuUserAdmin(Usuario *usuario);
void limpar_sessao_usuario(Usuario *usuario);

// Protótipos de funções auxiliares
int verificaEmail(char *email);

// Protótipos das funções de gerencia da categoria.
void cadastrarCategoria(Usuario userAdmin);
void listarCategorias();
int buscarCategoria(char *busca);
void atualizarCategoria(Usuario userAdmin, char *nomeCategoria, char *retornoFeedback);
void deletarCategoria(char *nomeCategoria);
int numeroCategorias();
int cadastroAdministrador();

// Protótipos das funções de gerência do feedback.
void cadastrarFeedback(Usuario usuarioComum);
void listarFeedback();

void prints_usuarios_teste()
{
    FILE *file = fopen("usuarios.b", "rb");
    Usuario a;
    int cont = 0;
    while (fread(&a, sizeof(Usuario), 1, file))
    {
        printf("%d - %s %s %d %s\n", ++cont, a.username, a.email, a.matricula, a.senha);
    }
    fclose(file);
}

int main(void)
{
    // Variável de controle para o primeiro menu.
    int opcao_navegacao_inicial;

    setlocale(LC_ALL, "portuguese");

    prints_usuarios_teste();

    printf("Bem vindo(a) a plataforma de feedback\n");
    Sleep(1000);
    printf("Realize o seu login para continuar");
    Sleep(1000);

    do
    {
        printf("\n");

        // Exibe e recebe a escolha no Menu inicial.
        opcao_navegacao_inicial = menuInicialLoginCadastro();

        if (opcao_navegacao_inicial == 0)
        {
            break;
        }

        // Area Login
        else if (opcao_navegacao_inicial == 1)
        {
            Usuario sessao_user;
            // sessão_user armazena o usuario aprovado no login.

            int status_login;
            // status_login é a variável de controle para a tela de Login.
            // 0 -> Erro no login;
            // 1 -> Usuario comum/anonimo autorizado;
            // 2 -> Administrador autorizado;

            status_login = menuLogin(&sessao_user);

            if (status_login == 1)
            { // <- Início Área usuario comum/anonimo logado.

                printf("\nBem vindo usuário, a seguir você terá acesso a área de feedback\n");
                Sleep(2000);
                printf("%s\n", sessao_user.username);
                int escolha_comum;

                do
                {

                    escolha_comum = menuUserComum(&sessao_user);
                    // Funções do menuUsuario.
                    if (escolha_comum == 1)
                    {
                        printf("1 - Registro de feedback:\n");
                        cadastrarFeedback(sessao_user);
                    }
                    else if (escolha_comum == 3)
                    {
                        listarCategorias();
                    }

                } while (escolha_comum != 0);
            } //<- Fim da Área do usuário comum/anonimo.

            else if (status_login == 2)
            { //-> Área usuario admin logado.

                printf("\nBem vindo admin, a seguir você terá acesso a área de controle\n");
                printf("%s\n", sessao_user.username);
                Sleep(2000);

                int escolha_admin;
                do
                {
                    escolha_admin = menuUserAdmin(&sessao_user);
                    // Funções do menu Admin;
                    if (escolha_admin == 1)
                    {
                        cadastrarCategoria(sessao_user);
                    }
                    else if (escolha_admin == 2)
                    {
                        listarCategorias();
                    }
                    else if (escolha_admin == 3)
                    {
                        char categoriaBusca[30];

                        printf("Informe o nome da categoria:\n");
                        // Limpa o buffer do stdin
                        int c;
                        while ((c = getchar()) != '\n' && c != EOF)
                            ;

                        if (fgets(categoriaBusca, 30, stdin) == NULL)
                        {
                            printf("\nErro ao ler nome da busca.\n");
                        }

                        atualizarCategoria(sessao_user, categoriaBusca, NULL);
                    }
                    else if (escolha_admin == 4)
                    {
                        char categoriaBusca[30];

                        printf("Informe o nome da categoria:\n");
                        // Limpa o buffer do stdin
                        int c;
                        while ((c = getchar()) != '\n' && c != EOF)
                            ;

                        if (fgets(categoriaBusca, 30, stdin) == NULL)
                        {
                            printf("\nErro ao ler nome da busca.\n");
                        }

                        deletarCategoria(categoriaBusca);
                    }
                    else if (escolha_admin == 5)
                    {
                        listarFeedback();
                    }
                    else if (escolha_admin == 6)
                    {

                        char categoriaBusca[30];
                        char retorno[200];
                        printf("Informe o nome da categoria:\n");
                        // Limpa o buffer do stdin
                        int c;
                        while ((c = getchar()) != '\n' && c != EOF)
                            ;

                        if (fgets(categoriaBusca, 30, stdin) == NULL)
                        {
                            printf("\nErro ao ler nome da busca.\n");
                        }
                        printf("Informe o retorno à categoria:\n");
                        if (fgets(retorno, 200, stdin) == NULL)
                        {
                            printf("\nErro ao ler retorno.\n");
                        }

                        atualizarCategoria(sessao_user, categoriaBusca, retorno);
                    }
                    else if (escolha_admin == 7)
                    {
                        cadastroAdministrador();
                    }
                } while (escolha_admin != 0);
            } // <- fim área usuario admin logado.
            else
            { // <- Login sem sucesso.
                printf("Falha no login");
            }

            limpar_sessao_usuario(&sessao_user);
            // Retoma a execução no menu inicial.
            continue;
        }

        // Cadastro usuario.
        else if (opcao_navegacao_inicial == 2)
        {
            int status_cadastro = cadastroUsuario();
            if (status_cadastro == 0)
            {
                printf("Cadastro realizado com sucesso!\n");

                // Retoma a execução do menu inicial.
                continue;
            }
            else
            {
                printf("falha no cadastro\n");

                // Retoma a execução no menu inicial.
                continue;
            }
        }
        else
        {
            printf("Informe uma opção válida");
        }

    } while (opcao_navegacao_inicial != 0);

    return 0;
}

int verificaEmail(char *email)
{
    // Verifica se o email contém o caractere '@'
    char *arroba = strchr(email, '@');
    if (arroba == NULL)
    {
        printf("E email deve ter o caractere @.\n");
        return 1;
    }

    // Verifica se o comprimento do email é menor que 80 caracteres
    if (strlen(email) >= 80)
    {
        printf("O email deve ser menor que 80 caracteres.\n");
        return 1;
    }

    FILE *arquivo = fopen("usuarios.b", "rb");
    if (arquivo == NULL)
    {
        return 1; // Se o arquivo não puder ser aberto, retorna falso
    }

    Usuario usuario;
    while (fread(&usuario, sizeof(Usuario), 1, arquivo))
    {
        if (strcmp(usuario.email, email) == 0)
        {
            fclose(arquivo);
            printf("Email já cadastrado na base de dados.\n");
            return 1;
        }
    }
    return 0;
}

int menuInicialLoginCadastro()
{
    /*
        - Menu inicial da aplicação.
        - Retorna a escolha do usuário.
    */

    int opc = 0;
    printf("Menu inicial\n");
    printf("1 - Login\n");
    printf("2 - cadastro\n");
    printf("0 - sair\n");
    scanf("%d", &opc);
    return opc;
}

int menuLogin(Usuario *usuario)
{
    FILE *file_usuarios = fopen("usuarios.b", "rb");

    if (file_usuarios == NULL)
    {
        printf("Erro ao acessar a base de dados.\n");
        return 1;
    }

    Usuario usuario_buscado;

    char email[79];
    char senha[20];

    printf("Opcao 1 - Login:\n");
    printf("*Para acesso anonimo informar username: 'anonimo'\n");

    printf("Informe seu email\n");
    if (scanf("%s", email) != 1)
    {
        printf("Erro ao ler o email.\n");
        return 0;
    }

    // Permite o acesso de usuário anônimo.
    if (strcmp(email, "anonimo") == 0)
    {
        strcpy(usuario->username, "Anonimo(a)");
        return 1;
    }

    printf("Informe a senha\n");
    if (scanf("%s", senha) != 1)
    {
        printf("Erro ao ler a senha.\n");
        return 0;
    }

    int estado = 0;

    while (fread(&usuario_buscado, sizeof(Usuario), 1, file_usuarios))
    {
        // Comparação entre email e senhas.
        if (strcmp(usuario_buscado.email, email) == 0 && strcmp(usuario_buscado.senha, senha) == 0)
        {
            if ((usuario_buscado).usuario_admin == 0)
            {
                *usuario = usuario_buscado;
                strcpy(usuario->senha, "");
                estado = 1;
            }
            else
            {
                *usuario = usuario_buscado;
                strcpy(usuario->senha, "");
                estado = 2;
            }
        }
    }

    return estado;

    fclose(file_usuarios);
}

int cadastroUsuario()
{
    FILE *file_usuario = fopen("usuarios.b", "ab");

    if (file_usuario == NULL)
    {
        printf("Erro ao abrir o arquivo de usuários.\n");
        return 1;
    }

    Usuario usuario;

    printf("Informe seu username\n");
    if (scanf("%s", usuario.username) != 1)
    {
        printf("Erro ao ler o username.\n");
        fclose(file_usuario);
        return 1;
    }

    printf("Informe sua matricula\n");
    if (scanf("%d", &usuario.matricula) != 1)
    {
        printf("Erro ao ler a matrícula.\n");
        fclose(file_usuario);
        return 1;
    }

    printf("Informe seu email\n");
    if (scanf("%s", usuario.email) != 1)
    {
        printf("Erro ao ler o email.\n");
        fclose(file_usuario);
        return 1;
    }
    if (verificaEmail(usuario.email) == 1)
    {
        return 1;
    }
    printf("Informe a senha\n");
    if (scanf("%s", usuario.senha) != 1)
    {
        printf("Erro ao ler a senha.\n");
        fclose(file_usuario);
        return 1;
    }
    usuario.usuario_admin = 0;
    if (fwrite(&usuario, sizeof(Usuario), 1, file_usuario) != 1)
    {
        printf("Erro ao escrever no arquivo de usuários.\n");
        fclose(file_usuario);
        return 1;
    }

    fclose(file_usuario);
    return 0;
}

int menuUserComum(Usuario *usuario)
{
    int opc = 0;
    printf("Menu usuário - sessão: %s\n", usuario->username);
    printf("1 - Registrar feedback.\n");     // ok
    printf("2 - Consulta de satisfação.\n"); // a fazer.
    printf("3 - Consultar categorias.\n");   // ok
    printf("0 - Sair.\n");
    scanf("%d", &opc);
    return opc;
}

int menuUserAdmin(Usuario *usuario)
{
    int opc = 0;
    printf("Menu administrador - sessão: %s\n", usuario->username);
    printf("1 - Criar categoria.\n");                  // ok
    printf("2 - Vizualizar categorias.\n");            // ok
    printf("3 - Atualizar categoria.\n");              // ok
    printf("4 - Deletar categoria.\n");                // ok
    printf("5 - Vizualizar feedback por categoria\n"); // ok
    printf("6 - Cadastrar retorno.\n");                // ok
    printf("7 - Cadastrar admnistrador.\n");           // ok
    printf("0 - Sair.\n");                             // ok

    scanf("%d", &opc);
    return opc;
}

void limpar_sessao_usuario(Usuario *usuario)
{
    strcpy(usuario->email, "");
    usuario->matricula = 0;
    strcpy(usuario->username, "");
    usuario->usuario_admin = 0;
}

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

int cadastroAdministrador()
{
    FILE *file_usuario = fopen("usuarios.b", "ab");

    if (file_usuario == NULL)
    {
        printf("Erro ao abrir o arquivo de usuários.\n");
        return 1;
    }

    Usuario usuario;

    printf("Informe o username do adm\n");
    if (scanf("%s", usuario.username) != 1)
    {
        printf("Erro ao ler o username.\n");
        fclose(file_usuario);
        return 1;
    }

    printf("Informe a matricula do adm\n");
    if (scanf("%d", &usuario.matricula) != 1)
    {
        printf("Erro ao ler a matrícula.\n");
        fclose(file_usuario);
        return 1;
    }

    printf("Informe o email do adm\n");
    if (scanf("%s", usuario.email) != 1)
    {
        printf("Erro ao ler o email.\n");
        fclose(file_usuario);
        return 1;
    }

    if (verificaEmail(usuario.email) == 1)
    {
        return 1;
    }

    printf("Informe a senha do adm\n");
    if (scanf("%s", usuario.senha) != 1)
    {
        printf("Erro ao ler a senha.\n");
        fclose(file_usuario);
        return 1;
    }
    usuario.usuario_admin = 1;
    if (fwrite(&usuario, sizeof(Usuario), 1, file_usuario) != 1)
    {
        printf("Erro ao escrever no arquivo de usuários.\n");
        fclose(file_usuario);
        return 1;
    }

    fclose(file_usuario);
    return 0;
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
        printf("Erro ao abrir o arquivo de usuários.\n");
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
        printf("Erro ao escrever no arquivo de usuários.\n");
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
