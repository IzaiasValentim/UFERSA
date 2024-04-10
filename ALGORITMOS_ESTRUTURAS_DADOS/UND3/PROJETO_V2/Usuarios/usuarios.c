#include "usuarios.h"
#include <stdio.h>
#include <string.h>

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

void limpar_sessao_usuario(Usuario *usuario)
{
    strcpy(usuario->email, "");
    usuario->matricula = 0;
    strcpy(usuario->username, "");
    usuario->usuario_admin = 0;
}

