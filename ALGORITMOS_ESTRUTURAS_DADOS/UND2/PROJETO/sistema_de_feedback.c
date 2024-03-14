#include <stdio.h>

// windows.h -> para função Sleep.
#include <windows.h>

// para setlocale
#include <locale.h>

typedef struct user{

    char username[20];
    int matricula;
    char email[79];
    char senha[20];
    int usuario_admin;
    
} Usuario;

int menuInicialLoginCadastro();
int menuLogin();
int cadastroUsuario();
int menuUserComum();
int menuUserAdmin();

int main(void)
{
    // Variável de controle para o primeiro menu.
    int opcao_navegacao_inicial;
    setlocale(LC_ALL, "portuguese");

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

            // Variável de controle para a tela de Login.
            int status_login;
            status_login = menuLogin();

            if (status_login == 1)
            {
                printf("\nBem vindo usuário, a seguir você terá acesso a área de feedback\n");
                Sleep(2000);

                int escolha_comum;

                do
                {

                    escolha_comum = menuUserComum();
                    // Funções do menuUsuario.
                } while (escolha_comum != 0);
            }

            else if (status_login == 2)
            {
                printf("\nBem vindo admin, a seguir você terá acesso a área de controle\n");
                Sleep(2000);

                int escolha_admin;

                do
                {
                    escolha_admin = menuUserAdmin();
                    // Funções do menu Admin;
                } while (escolha_admin != 0);
            }

            else
            {
                printf("Falha no login");
            }

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

int menuLogin()
{

    printf("Opcao 1 - Login:\n");
    printf("Informe seu username\n");
    printf("Informe sua senha\n");
    printf("*Para acesso anonimo informar username: 'anonimo'\n");

    return 2;
}
int cadastroUsuario()
{
    printf("Opcao 2 - Cadastro:\n");
    printf("Informe seu username\n");
    printf("Informe sua matricula\n");
    printf("informe seu email\n");
    printf("informe a senha\n");
    return 0;
}
int menuUserComum()
{
    int opc = 0;
    printf("Menu usuário:\n");
    printf("1 - Registrar feedback.\n");
    printf("2 - Consulta de satisfação.\n");
    printf("3 - Consultar categorias.\n");
    printf("0 - Sair.\n");
    scanf("%d", &opc);
    return opc;
}
int menuUserAdmin()
{
    int opc = 0;
    printf("Menu administrador:\n");
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