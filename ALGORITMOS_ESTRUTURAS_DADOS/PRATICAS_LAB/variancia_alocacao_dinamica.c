#include <stdio.h>
#include <stdlib.h>

void entrada(int toal, float * valores);

void calc_media(int total, float * valores, float * media);

void calc_variancia (int total, float * valores,float media,float * resVariancia);


int main(void){

    int total = 0, contador;
    float media,resVariancia;

    printf("Informe a quantidade de dados: \n");
    scanf("%d",&total);

    float * dados = (float*) malloc(total * sizeof(float)); 
    
    if(dados == NULL){
        exit(1);
    }

    entrada(total,dados);
    calc_media(total,dados,&media);
    calc_variancia(total,dados,media,&resVariancia);

    free(dados);

    printf("A variância do conjunto de dados é : %.2f",resVariancia);

    return 0;
}


void entrada(int total, float * valores){
    /*
        Função responsável por obter o valor do usuário e armazenar nos endereços referentes
        ao ponteiro valores.

        total -> valor do tipo int, total da amostra.
        valores -> ponteiro do tipo float, armazenará os valores amostrais.
    */


    int contador;
    printf("Digite os valores: \n");
    for(contador = 0; contador < total; contador++){
        scanf("%f",&valores[contador]);
    }
}


void calc_media(int total, float * valores, float * media){
    /*
        Função do tipo void, resultará o valor da média no endereço referente ao ponteiro 
        media.
        total -> variavel do tipo inteiro, total de valores para o calculo da media.
        valores -> ponteiro do tipo real, armazena os valores amostrais.
    */

   
    float soma = 0.0;
    int controle;
    for(controle =0; controle < total; controle++){

        soma = soma + valores[controle];

    }
    *media = soma/(float)total;
}


void calc_variancia (int total, float * valores,float media, float * resVariancia){
     /*
        Função do tipo void, resultará o valor da variancia no endereço referente ao ponteiro.
        total -> variavel do tipo inteiro, total de valores para o calculo da media.
        valores -> ponteiro do real float, armazena os valores amostrais.
        media -> variavel do tipo real que armazena o valor da media amostral.
    */


    int controle;
    float soma = 0.0;
    
    for (controle = 0; controle < total;controle++)
    {
        soma = soma + ((valores[controle] - media) * (valores[controle] - media)); 
    }
    *resVariancia = (soma/(float)(total-1)); 
}
