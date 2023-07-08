#include <stdio.h>
#include <stdlib.h>

char * gabarito(int * tamanho);
int correcao_prova(int quantidadeQ, char * gabarito);

int main (void){

    int tamanho_prova;
    char * gabaritoTotal;
    int quantidade_alunos = 1;
    float media = 0.0;
    gabaritoTotal = gabarito(&tamanho_prova);
    media = correcao_prova(tamanho_prova,gabaritoTotal);
    printf("%f", media);    

 
    

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
        printf("Forneça o gabarito da %dª questão:",questao+1);
        scanf(" %c",&gabarito[questao]);
    }
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

        printf("Resposta da %d questão:",contador_resposta);
        scanf(" %c",&respostas_aluno[contador_resposta]);
        if(gabarito[contador_resposta] == respostas_aluno[contador_resposta]){
            media += valorQ;
        }
    }
    return media;
}
