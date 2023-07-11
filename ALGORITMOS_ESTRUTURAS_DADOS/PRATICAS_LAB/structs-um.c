//---> Programa que manipula uma struct aluno.


#include <stdio.h>

//DEFINI��O DA STRUCT.
struct aluno {
	char nome[20];
	int idade;
	int matricula;
};

//Permite renomear o comando de defini��o da struct.
typedef struct aluno Aluno;

int main(void){
	// DECLARA��O DE UM ELEMENTO DA STRUCT.
	// OS ELEMENTOS DA STRUCT PODEM SER ACESSADOS PELO '.' -> NOME-STRUCT.VAR;
	
	Aluno var_aluno;
	
	printf("Informe o nome do aluno:  \n");
	scanf("%[^\n]", var_aluno.nome);
	//ou gets(var_aluno.nome);
	
	printf("Informe a idade do aluno:  \n");
	scanf("%d", &var_aluno.idade);
	
	printf("Informe a matricula do aluno:  \n");
	scanf("%d", &var_aluno.matricula);	
	
	printf("\nOs dados informados:\nNome: %s\tIdade: %d\tMatricula: %d", var_aluno.nome, var_aluno.idade, var_aluno.matricula);
	
	
	return 0;
}
