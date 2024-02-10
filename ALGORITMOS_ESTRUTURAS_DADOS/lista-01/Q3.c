#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 2

typedef struct Agenda
{
    char nome[30];
    char enderedo[50];
    char telefone[15];

}Lista[N];

int compararPorNome(const void *a, const void *b) {
    return strcmp(((struct Agenda*)a)->nome, ((struct Agenda*)b)->nome);
}

int main(void){
    Lista l;

    int i;
    for(i=0; i<N; i++){
        printf("\nInforme os dados do %d contato:",i+1);
        printf("\n nome: ");
        fgets(l[i].nome,30,stdin);
        printf("\n endereco: ");
        fgets(l[i].enderedo,50,stdin);
        printf("\n telefone: ");
        fgets(l[i].telefone,15,stdin);
        fflush(stdin);
    }
        qsort(l, N,sizeof(struct Agenda),compararPorNome);

        printf("\n Lista de contatos ordenada: ");
        for (i = 0; i < N; i++) {
        printf("\n Nome: %s, Endereco: %s, Telefone: %s", l[i].nome, l[i].enderedo, l[i].telefone);
        }
    return 0;
}