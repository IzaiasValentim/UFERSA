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

} Categoria;

// Protótipos das funções de navegação.
int menuInicialLoginCadastro();
int menuLogin(Usuario *usuario);
int cadastroUsuario();
int menuUserComum(Usuario *usuario);
int menuUserAdmin(Usuario *usuario);
void limpar_sessao_usuario(Usuario *usuario);

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
            // status_login é a variável de controle para a tela de Login.
            // 0 -> Erro no login;
            // 1 -> Usuario comum/anonimo autorizado;
            // 2 -> Administrador autorizado;

            int status_login;
            status_login = menuLogin(&sessao_user);

            if (status_login == 1)
            {
                printf("\nBem vindo usuário, a seguir você terá acesso a área de feedback\n");
                Sleep(2000);
                printf("%s\n", sessao_user.username);
                int escolha_comum;

                do
                {

                    escolha_comum = menuUserComum(&sessao_user);
                    // Funções do menuUsuario.
                } while (escolha_comum != 0);
            }

            else if (status_login == 2)
            {

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
                } while (escolha_admin != 0);
            }

            else
            {
                printf("Falha no login");
            }
            limpar_sessao_usuario(&sessao_user);
            printf("User logado: %s\n", sessao_user.username);
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

    printf("Informe a senha\n");
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
int menuUserComum(Usuario *usuario)
{
    int opc = 0;
    printf("Menu usuário - sessão: %s\n", usuario->username);
    printf("1 - Registrar feedback.\n");
    printf("2 - Consulta de satisfação.\n");
    printf("3 - Consultar categorias.\n");
    printf("0 - Sair.\n");
    scanf("%d", &opc);
    return opc;
}
int menuUserAdmin(Usuario *usuario)
{
    int opc = 0;
    printf("Menu administrador - sessão: %s\n", usuario->username);
    printf("1 - Criar categoria.\n");
    printf("2 - Vizualizar categorias.\n");
    printf("3 - Atualizar categoria.\n");
    printf("4 - Deletar categoria.\n");
    printf("5 - Cadastrar retorno.\n");
    printf("6 - Cadastrar admnistrador.\n");
    printf("7 - Excluir admnistrador.\n");
    printf("0 - Sair.\n");

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

