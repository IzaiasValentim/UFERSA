#include <stdio.h>

// windows.h -> para fun��o Sleep.
#include <windows.h>

// para setlocale
#include <locale.h>

// Para opera��es com cadeias de caracteres.
#include <string.h>

#include "Usuarios/usuarios.h"

#include "Categorias/categorias.h"

#include "Feedbacks/feedbacks.h"

// Prot�tipos das fun��es de navega��o.
int menuInicialLoginCadastro();
int menuUserComum(Usuario *usuario);
int menuUserAdmin(Usuario *usuario);


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
    // Vari�vel de controle para o primeiro menu.
    int opcao_navegacao_inicial;
	carregarListaFeedbacks();
    setlocale(LC_ALL, "portuguese");

    // Essa fun��o � apenas demonstrativa em desenvolvimento e teste. Em produ��o ela n�o existiria:
    // prints_usuarios_teste();

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
            // sess�o_user armazena o usuario aprovado no login.

            int status_login;
            // status_login � a vari�vel de controle para a tela de Login.
            // 0 -> Erro no login;
            // 1 -> Usuario comum/anonimo autorizado;
            // 2 -> Administrador autorizado;

            status_login = menuLogin(&sessao_user);

            if (status_login == 1)
            { // <- In�cio �rea usuario comum/anonimo logado.

                printf("\nBem vindo usuario, a seguir voce tera acesso a area de feedback\n");
                Sleep(2000);
                printf("%s\n", sessao_user.username);
                int escolha_comum;

                do
                {

                    escolha_comum = menuUserComum(&sessao_user);
                    // Fun��es do menuUsuario.
                    if (escolha_comum == 1)
                    {
                        printf("1 - Registro de feedback:\n");
                        cadastrarFeedback(sessao_user);
                    }
                    else if (escolha_comum == 2)
                    {
                        calculoSatisfacao();
                    }
                    else if (escolha_comum == 3)
                    {
                        listarCategorias();
                    }

                } while (escolha_comum != 0);
            } //<- Fim da �rea do usu�rio comum/anonimo.

            else if (status_login == 2)
            { //-> �rea usuario admin logado.

                printf("\nBem vindo admin, a seguir voce tera acesso a area de controle\n");
                printf("%s\n", sessao_user.username);
                Sleep(2000);

                int escolha_admin;
                do
                {
                    escolha_admin = menuUserAdmin(&sessao_user);
                    // Fun��es do menu Admin;
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
                    }else if(escolha_admin == 6){
						ordenarFeedbackPorNota();
					}
                    else if (escolha_admin == 7)
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
                        printf("Informe o retorno da categoria:\n");
                        if (fgets(retorno, 200, stdin) == NULL)
                        {
                            printf("\nErro ao ler retorno.\n");
                        }

                        atualizarCategoria(sessao_user, categoriaBusca, retorno);
                    }
                    else if (escolha_admin == 8)
                    {
                        cadastroAdministrador();
                    }
                } while (escolha_admin != 0);
            } // <- fim �rea usuario admin logado.
            else
            { // <- Login sem sucesso.
                printf("Falha no login");
            }

            limpar_sessao_usuario(&sessao_user);
            // Retoma a execu��o no menu inicial.
            continue;
        }

        // Cadastro usuario.
        else if (opcao_navegacao_inicial == 2)
        {
            int status_cadastro = cadastroUsuario();
            if (status_cadastro == 0)
            {
                printf("Cadastro realizado com sucesso!\n");

                // Retoma a execu��o do menu inicial.
                continue;
            }
            else
            {
                printf("falha no cadastro\n");

                // Retoma a execu��o no menu inicial.
                continue;
            }
        }
        else
        {
            printf("Informe uma opcao valida");
        }

    } while (opcao_navegacao_inicial != 0);

    return 0;
}

int menuInicialLoginCadastro()
{
    /*
        - Menu inicial da aplica��o.
        - Retorna a escolha do usu�rio.
    */
    int opc = 0;
    printf("Menu inicial\n");
    printf("1 - Login\n");
    printf("2 - cadastro\n");
    printf("0 - sair\n");
    scanf("%d", &opc);
    return opc;
}

int menuUserComum(Usuario *usuario)
{
    int opc = 0;
    printf("Menu usuario - sessao: %s\n", usuario->username);
    printf("1 - Registrar feedback.\n");
    printf("2 - Consulta de satisfacao.\n");
    printf("3 - Consultar categorias.\n");
    printf("0 - Sair.\n");
    scanf("%d", &opc);
    return opc;
}

int menuUserAdmin(Usuario *usuario)
{
    int opc = 0;
    printf("Menu administrador - sessao: %s\n", usuario->username);
    printf("1 - Criar categoria.\n");
    printf("2 - Vizualizar categorias.\n");
    printf("3 - Atualizar categoria.\n");
    printf("4 - Deletar categoria.\n");
    printf("5 - Vizualizar feedback por categoria\n");
    printf("6 - Ordenar feedbacks(M -> m)\n");
    printf("7 - Cadastrar retorno.\n");
    printf("8 - Cadastrar admnistrador.\n");
    printf("0 - Sair.\n");

    scanf("%d", &opc);
    return opc;
}

