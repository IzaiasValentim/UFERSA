typedef struct feedback
{
    char username_autor[20];
    char texto[200];
    float nota;
    char nome_categoria[30];
	struct feedback *prox;
} Feedback;

void carregarListaFeedbacks();
void cadastrarFeedback(Usuario usuarioComum);
void listarFeedback();
void calculoSatisfacao();