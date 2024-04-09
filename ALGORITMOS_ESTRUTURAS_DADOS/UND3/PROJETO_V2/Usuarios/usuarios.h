typedef struct
{
    char username[20];
    int matricula;
    char email[79];
    char senha[20];
    int usuario_admin;

} Usuario;

int cadastroUsuario();

int verificaEmail(char *);

int menuLogin(Usuario *);

int cadastroAdministrador();

void limpar_sessao_usuario(Usuario *usuario);
