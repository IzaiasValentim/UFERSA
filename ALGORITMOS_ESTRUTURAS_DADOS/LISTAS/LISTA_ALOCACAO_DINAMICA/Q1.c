#include <stdio.h>
#include <stdlib.h>

void coletaRespostas(int tamanho, char *respS, int *respO);

void exibirDados(int tamanho, char *respS, int *respO);

void feedbackQuestionario(int tamanho, char *respS, int *respO, char opcSexo, int opcOpiniao);

int main(void)
{
    // Declaração de variáveis:
    int quantidadeEntrev = 0;
    char *respSexo;
    int *respOpiniao;

    printf("-- ENTREVISTA DE SATISFAÇÃO --\n");
    printf("Informe a quantidade de entrevistados: \n");
    scanf("%d", &quantidadeEntrev);

    respSexo = (char *)malloc(quantidadeEntrev * sizeof(char));
    if (respSexo == NULL)
    {
        printf("Houve um problema na execução do programa :c\n");
        exit(1);
    }

    respOpiniao = (int *)malloc(quantidadeEntrev * sizeof(int));
    if (respOpiniao == NULL)
    {
        printf("Houve um problema na execução do programa :c\n");
        exit(1);
    }
    system("clear");

    coletaRespostas(quantidadeEntrev, respSexo, respOpiniao);

    exibirDados(quantidadeEntrev, respSexo, respOpiniao);

    feedbackQuestionario(quantidadeEntrev, respSexo, respOpiniao, 'F', 1);

    feedbackQuestionario(quantidadeEntrev, respSexo, respOpiniao, 'M', 0);

    return 0;
}

void coletaRespostas(int tamanho, char *respS, int *respO)
{
    int controle;

    for (controle = 0; controle < tamanho; controle++)
    {
        int validador = 0;
        char sTeste;
        int oTeste = 0;

        while (validador == 0)
        {

            printf("%d - candidato, informe o seu sexo: \n", controle + 1);
            printf("M - Masculinoo | F - Feminino: ");
            scanf("\t%c", &sTeste);

            if (sTeste == 'M' || sTeste == 'F')
            {
                validador = 1;
            }
        }

        validador = 0;

        while (validador == 0)
        {

            printf("\n%d - candidato, informe a sua opinião a respeito do produto:\n", controle + 1);
            printf("1 - Gostou | 0 - Não gostou:");
            scanf(" %d", &oTeste);
            if (oTeste == 0 || oTeste == 1)
            {
                validador = 1;
            }
        }
        system("clear");
        respS[controle] = sTeste;
        respO[controle] = oTeste;
    }
}

void exibirDados(int tamanho, char *respS, int *respO)
{
    int posResposta = 0;

    for (posResposta = 0; posResposta < tamanho; posResposta++)
    {

        printf("- Sexo do %d candidato = %c - R - %d\n", posResposta + 1, respS[posResposta], respO[posResposta]);
    }
}

void feedbackQuestionario(int tamanho, char *respS, int *respO, char opcSexo, int opcOpiniao)
{

    int controle;
    int contadorOcorrencia = 0;
    int contadorGrupo = 0;
    float porcentagem = 0.0;

    for (controle = 0; controle < tamanho; controle++)
    {

        if (respS[controle] == opcSexo)
        {
            contadorGrupo++;
            if (respO[controle] == opcOpiniao)
            {
                contadorOcorrencia++;
            }
        }
    }
    if(contadorGrupo>0){
        porcentagem = ((float)contadorOcorrencia / (float)contadorGrupo) * 100;
    }
    

    if (opcOpiniao == 1)
    {

        switch (opcSexo)
        {
        case 'F':

            printf("%.2f das mulheres gostaram do produto\n", porcentagem);
            break;

        case 'M':
            printf("%.2f dos homens gostaram do produto\n", porcentagem);
            break;
        }
    }
    else
    {
        switch (opcSexo)
        {
        case 'F':

            printf("%.2f das mulheres não gostaram do produto\n", porcentagem);
            break;

        case 'M':
            printf("%.2f dos homens não gostaram do produto\n", porcentagem);
            break;
        }
    }
}