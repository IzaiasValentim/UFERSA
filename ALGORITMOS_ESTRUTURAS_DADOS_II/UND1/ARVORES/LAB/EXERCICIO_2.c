#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Info
{
    char nome[100];
    int mat;
    int turma;
    float nota;
};

struct Node
{
    struct Info info;
    struct Node *esq;
    struct Node *dir;
};

struct Info criarInfo(char *nome, int mat, int turma, float nota);
struct Node *criarNode(struct Info info);
int comparar(struct Info a, struct Info b);
struct Node *inserir(struct Node *raiz, struct Info info);
void imprimirArvorePreOrdem(struct Node *raiz);
struct Node *buscarComPai(struct Node *raiz, char *nome, struct Node **pai);
void inserirAlunos(struct Node **raiz);
void buscarInformacoes(struct Node *raiz, char *nome);

int main()
{
    struct Node *raiz = NULL;

    inserirAlunos(&raiz);

    // printf("Árvore em pré-ordem:\n");
    // imprimirArvorePreOrdem(raiz);

    // Exemplo de busca por informações de um nó específico

    buscarInformacoes(raiz, "LUIS IZAÍAS VALENTIM DE AQUINO");

    return 0;
}

struct Info criarInfo(char *nome, int mat, int turma, float nota)
{
    struct Info res;
    strcpy(res.nome, nome);
    res.mat = mat;
    res.turma = turma;
    res.nota = nota;
    return res;
}

struct Node *criarNode(struct Info info)
{
    struct Node *res = (struct Node *)malloc(sizeof(struct Node));
    if (res == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    res->info = info;
    res->dir = NULL;
    res->esq = NULL;
    return res;
}

int comparar(struct Info a, struct Info b)
{
    return strcmp(a.nome, b.nome);
}

struct Node *inserir(struct Node *raiz, struct Info info)
{
    if (raiz == NULL)
    {
        return criarNode(info);
    }
    int x = comparar(raiz->info, info);
    if (x < 0)
    {
        raiz->dir = inserir(raiz->dir, info);
    }
    else if (x > 0)
    {
        raiz->esq = inserir(raiz->esq, info);
    }
    return raiz;
}

void imprimirArvorePreOrdem(struct Node *raiz)
{
    if (raiz != NULL)
    {
        printf("Nome: %s, Matricula: %d, Turma: %d, Nota: %.2f\n", raiz->info.nome, raiz->info.mat, raiz->info.turma, raiz->info.nota); // Visita o nó atual
        imprimirArvorePreOrdem(raiz->esq);                                                                                              // Visita a subárvore esquerda
        imprimirArvorePreOrdem(raiz->dir);                                                                                              // Visita a subárvore direita
    }
}

struct Node *buscarComPai(struct Node *raiz, char *nome, struct Node **pai)
{
    struct Node *atual = raiz;
    *pai = NULL;

    while (atual != NULL)
    {
        int cmp = strcmp(nome, atual->info.nome);
        if (cmp == 0)
        {
            return atual;
        }
        *pai = atual;
        if (cmp < 0)
        {
            atual = atual->esq;
        }
        else
        {
            atual = atual->dir;
        }
    }
    return NULL;
}

void buscarInformacoes(struct Node *raiz, char *nome)
{
    struct Node *pai = NULL;
    struct Node *no = buscarComPai(raiz, nome, &pai);

    if (no != NULL)
    {
        printf("\nInformações do nó com o nome %s:\n", nome);
        printf("Nó encontrado: Nome: %s, Matricula: %d, Turma: %d, Nota: %.2f\n", no->info.nome, no->info.mat, no->info.turma, no->info.nota);

        if (pai != NULL)
        {
            printf("Pai: Nome: %s, Matricula: %d, Turma: %d, Nota: %.2f, END: %p\n", pai->info.nome, pai->info.mat, pai->info.turma, pai->info.nota, (void *)pai);
        }
        else
        {
            printf("O nó encontrado é a raiz da árvore e não possui pai.\n");
        }

        if (no->esq != NULL)
        {
            printf("Filho esquerdo: Nome: %s, Matricula: %d, Turma: %d, Nota: %.2f, END: %p\n", no->esq->info.nome, no->esq->info.mat, no->esq->info.turma, no->esq->info.nota, (void *)no->esq);
        }
        else
        {
            printf("Não possui filho esquerdo.\n");
        }

        if (no->dir != NULL)
        {
            printf("Filho direito: Nome: %s, Matricula: %d, Turma: %d, Nota: %.2f, END: %p\n", no->dir->info.nome, no->dir->info.mat, no->dir->info.turma, no->dir->info.nota, (void *)no->dir);
        }
        else
        {
            printf("Não possui filho direito.\n");
        }
    }
    else
    {
        printf("\nNó com o nome %s não encontrado.\n", nome);
    }
}
void inserirAlunos(struct Node **raiz)
{
    struct Info alunos[] = {
        // Turma 01
        criarInfo("ALEX BRUNO DUARTE", 1, 1, rand() % 10),
        criarInfo("AMANDA DE QUEIROZ SANTIAGO", 2, 1, rand() % 10),
        criarInfo("ANAILTON ARTUR FERNANDES", 3, 1, rand() % 10),
        criarInfo("ANTHONY MATHEUS NASCIMENTO FREITAS", 4, 1, rand() % 10),
        criarInfo("DIEGO NASCIMENTO DE OLIVEIRA", 5, 1, rand() % 10),
        criarInfo("FABRICIO ANDREY LEANDRO DAMIAO", 6, 1, rand() % 10),
        criarInfo("FERNANDO UMBILINO ALVES", 7, 1, rand() % 10),
        criarInfo("FRANCISCO RYAM FEITOSA DINIZ", 8, 1, rand() % 10),
        criarInfo("GUILHERME DE FRANCA VASCONCELOS", 9, 1, rand() % 10),
        criarInfo("HARLEY LUCAS DE SOUZA BATISTA", 10, 1, rand() % 10),
        criarInfo("JOSE FERREIRA SOUSA NETO", 11, 1, rand() % 10),
        criarInfo("JOSE VERISSIMO DE OLIVEIRA QUEIROZ", 12, 1, rand() % 10),
        criarInfo("LUIS IZAÍAS VALENTIM DE AQUINO", 13, 1, rand() % 10),
        criarInfo("MEL CAMILY MONTENEGRO CARDOSO", 14, 1, rand() % 10),
        criarInfo("PABLO GERALDO LINHARES DO NASCIMENTO LEITE", 15, 1, rand() % 10),
        criarInfo("STHEFFANY DA CÂMARA GUILHERMINO", 16, 1, rand() % 10),
        criarInfo("THALLYS ARAUJO DE MORAIS", 17, 1, rand() % 10),
        criarInfo("TÚLIO GOMES DE ARAÚJO FEITOSA", 18, 1, rand() % 10),
        criarInfo("VICENTE BENTO DA SILVA NETO", 19, 1, rand() % 10),
        // Turma 02
        criarInfo("ANTONIO ERICK DA SILVEIRA FARIAS OLIVEIRA", 1, 2, rand() % 10),
        criarInfo("ANTONIO NOGUEIRA DA SILVA NETO", 2, 2, rand() % 10),
        criarInfo("DANIEL NERES VIEIRA", 3, 2, rand() % 10),
        criarInfo("EDUARDO PEREIRA ABRANTES", 4, 2, rand() % 10),
        criarInfo("EVERSON ALISSON QUEIROZ SILVA", 5, 2, rand() % 10),
        criarInfo("GUSTAVO KESLEY DE FONTES NUNES", 6, 2, rand() % 10),
        criarInfo("JEAN RICHARDSON GONCALVES MARCOS", 7, 2, rand() % 10),
        criarInfo("JOAO GUSTAVO SOUZA LIMA", 8, 2, rand() % 10),
        criarInfo("JOSE MATHEUS GOMES SILVA", 9, 2, rand() % 10),
        criarInfo("LEANDRO CARLOS MARTINS DE CARVALHO", 10, 2, rand() % 10),
        criarInfo("NATTAN FERREIRA LOPES", 11, 2, rand() % 10),
        criarInfo("PEDRO LUCAS DE SOUSA FERREIRA", 12, 2, rand() % 10),
        criarInfo("RUBENS ALEXANDRE DE SOUSA FERREIRA", 13, 2, rand() % 10),
        criarInfo("SAMUEL DE ALMEIDA SATURNO", 14, 2, rand() % 10),
        criarInfo("WESLLEY EMANOEL SILVA SOARES", 15, 2, rand() % 10),
        // Turma 03
        criarInfo("ALLAN GABRIEL SILVA DE FREITAS", 1, 3, rand() % 10),
        criarInfo("ALLYSON DA SILVA FELIX", 2, 3, rand() % 10),
        criarInfo("ANA BEATRIZ ALMEIDA DA SILVA", 3, 3, rand() % 10),
        criarInfo("ANTONIO JOAQUIM DE LIRA NETO", 4, 3, rand() % 10),
        criarInfo("ANTONIO VINICIUS OLIVEIRA LIMA", 5, 3, rand() % 10),
        criarInfo("ARTUR CARVALHO GAMA", 6, 3, rand() % 10),
        criarInfo("CARLOS HENRIQUE DUARTE ABRANTES", 7, 3, rand() % 10),
        criarInfo("DINARTE RODRIGUES DE OLIVEIRA FILHO", 8, 3, rand() % 10),
        criarInfo("ERIK THADEU SALES PRAXEDES", 9, 3, rand() % 10),
        criarInfo("EVELYN CRISTINA DE OLIVEIRA GOMES", 10, 3, rand() % 10),
        criarInfo("FABIO QUEIROZ VIEIRA", 11, 3, rand() % 10),
        criarInfo("FRANCIER EDUARDO DA SILVA LUZ", 12, 3, rand() % 10),
        criarInfo("FRANCISCO ADRIAN VINICIUS CHAVES SAMPAIO", 13, 3, rand() % 10),
        criarInfo("FRANCISCO LAILSON DE ALMEIDA", 14, 3, rand() % 10),
        criarInfo("GUSTAVO RODRIGUES DOS REIS", 15, 3, rand() % 10),
        criarInfo("HILLARY DINIZ SALDANHA", 16, 3, rand() % 10),
        criarInfo("JOSE KAYQUE LIMA LOPES", 17, 3, rand() % 10),
        criarInfo("JUANNY THAYSSA GUEDES DE FREITAS", 18, 3, rand() % 10),
        criarInfo("KAUE VALENTIM DE CARVALHO", 19, 3, rand() % 10),
        criarInfo("LEONARDO AUGUSTO SILVA DE SOUSA", 20, 3, rand() % 10),
        criarInfo("LETICIA MARIA GONCALVES DE MORAIS", 21, 3, rand() % 10),
        criarInfo("LETICIA VIEIRA GONCALVES", 22, 3, rand() % 10),
        criarInfo("LEVITICO RIMON PEREZ ANDRADE ALVES", 23, 3, rand() % 10),
        criarInfo("LUIZ EDUARDO DE ALMEIDA RODRIGUES", 24, 3, rand() % 10),
        criarInfo("MARCELO AUGUSTO DA SILVA FERNANDES", 25, 3, rand() % 10),
        criarInfo("MARCELO HENRIQUE MESSIAS CAVALCANTE", 26, 3, rand() % 10),
        criarInfo("MARIA CLARA SARAIVA LEAL", 27, 3, rand() % 10),
        criarInfo("MARIA EDUARDA DA SILVA SOUZA", 28, 3, rand() % 10),
        criarInfo("MARIA EDUARDA RODRIGUES BEZERRA", 29, 3, rand() % 10),
        criarInfo("MARIA ISABELLY LIMA DE SOUSA", 30, 3, rand() % 10),
        criarInfo("PEDRO HENRIQUE ANDRADE DA CONCEICAO", 31, 3, rand() % 10),
        criarInfo("SAMUEL IAGO DE FARIAS CABRAL", 32, 3, rand() % 10),
        criarInfo("SHAMYRA DE FATIMA SARAIVA CARVALHO", 33, 3, rand() % 10),
        criarInfo("THYAGO FABRICIO MELO COSTA", 34, 3, rand() % 10),
        criarInfo("TOBIAS FERNANDES FIGUEIREDO", 35, 3, rand() % 10)};

    int numAlunos = sizeof(alunos) / sizeof(alunos[0]);
    for (int i = 0; i < numAlunos; i++)
    {
        *raiz = inserir(*raiz, alunos[i]);
    }
}
