#include <stdio.h>

typedef struct Pessoa
{
  char nome[30];
  int idade;
  char endereco[50];

  /* data */
} P;

int main(void)
{

  P eu;
  printf("Informe os seus dados:\n");
  printf("Seu nome:\n");
  fgets(eu.nome, 30, stdin);
  printf("Seu endereco:\n");
  fgets(eu.endereco, 50, stdin);
  printf("Sua idade:\n");
  scanf("%d", &eu.idade);

  printf("Ocorrencia: Nome:%s, Idade: %d, Endereco: %s", eu.nome, eu.idade, eu.endereco);

  return 0;
}