#include <stdio.h>
#include <stdlib.h>

char * gabarito(int * tamanho);

int correcao_prova(int quantidadeQ, char * gabarito);

void calcula_medias(int alunos_total, float * medias, int quantidadeQ, char * gabarito);

void imprime_medias(int alunos_total, float * medias);

void procentagem_aprovacao(int alunos_total, float * medias);

int main (void){

    printf("## Bem vindo ao sistema corretor de provas ## \n --pressione enter para continuar...");
    getchar();
    system("clear");

    int tamanho_prova;
    char * gabaritoTotal;
    int quantidade_alunos = 3;

    gabaritoTotal = gabarito(&tamanho_prova);

    float * medias = (float*) malloc(quantidade_alunos * sizeof(float));
    if(medias == NULL){
        printf("\n! Erro no armazenamento das médias !");
        exit(1);
    }

    calcula_medias(quantidade_alunos, medias, tamanho_prova, gabaritoTotal);
    imprime_medias(quantidade_alunos, medias);
    procentagem_aprovacao(quantidade_alunos, medias);
    
    free(gabaritoTotal);
    free(medias);

    return 0;
}

char * gabarito(int * tamanho){
    int questao;
    printf("Informe a quantidade de questões da prova: \n");
    scanf("%d",tamanho);

    char * gabarito = (char *) malloc(*tamanho * sizeof(char));
    if(gabarito == NULL){
        printf("Erro em alocar memória para o gabarito");
        exit(1);
    }

    for(questao =0; questao<*tamanho;questao++){
        
        system("clear");

        printf("Forneça o gabarito da %dª questão:",questao+1);
        scanf(" %c",&gabarito[questao]);
    }
    system("clear");
    return gabarito;
}


int correcao_prova(int quantidadeQ, char * gabarito){
    char * respostas_aluno = (char *) malloc(quantidadeQ * sizeof(char));
    int contador_resposta;
    float valorQ = 10.0/quantidadeQ;
    float media = 0.0;
    if(respostas_aluno == NULL){
        printf("Erro ao armazenar respostas do aluno");
        exit(1);
    }

    for(contador_resposta = 0; contador_resposta < quantidadeQ; contador_resposta++){

        printf("Resposta da %d questão: \n",contador_resposta+1);
        scanf(" %c",&respostas_aluno[contador_resposta]);
        if(gabarito[contador_resposta] == respostas_aluno[contador_resposta]){
            media += valorQ;
        }
    }
    free(respostas_aluno);
    return media;
}


void calcula_medias(int alunos_total, float * medias, int quantidadeQ, char * gabarito){
    int aluno;
    for(aluno = 0; aluno < alunos_total; aluno++){
        system("clear");
        printf("Informe as respostas do %dº aluno \n", aluno+1);
        medias[aluno] = correcao_prova(quantidadeQ, gabarito);

    }

}

void imprime_medias(int alunos_total, float * medias){
    system("clear");
    int aluno;
    for(aluno =0; aluno<alunos_total; aluno++){

        printf("A média do %d aluno é: %.1f \n",aluno+1,medias[aluno]);

    }
}


void procentagem_aprovacao(int alunos_total, float * medias){

    int aprovados = 0;
    int aluno;
    float aprovacao;
    for(aluno =0; aluno<alunos_total; aluno++){

        if(medias[aluno] >= 6.0){
            aprovados++;
        }
    }
    aprovacao = ((float)aprovados/(float)alunos_total) * 100.0;
    printf("\nA turma obteve um total de %.0f de aprovação", aprovacao);
}

