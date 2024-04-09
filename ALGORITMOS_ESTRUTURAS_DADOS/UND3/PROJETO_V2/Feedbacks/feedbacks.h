typedef struct feedback
{
    char username_autor[20];
    char texto[200];
    float nota;
    char nome_categoria[30];

} Feedback;

void cadastrarFeedback(Usuario usuarioComum);
void listarFeedback();
void calculoSatisfacao();