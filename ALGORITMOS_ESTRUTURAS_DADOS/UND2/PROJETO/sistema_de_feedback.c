#include <stdio.h>

// windows.h -> para função Sleep.
#include <windows.h>

// para setlocale
#include <locale.h>

int menuInicialLoginCadastro();
int menuLogin();
int cadastroUsuario();
int menuUserComum();
int menuUserAdmin();

int main(void)
{
    setlocale(LC_ALL, "portuguese");
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