/*
	CRIAR PROGRAMA QUE RECEBE DADOS DE UMA PESSOA.
	
		DADOS:
			*NOME;
			*IDADE;
			*RG, e
			*ALTURA.
*/ 
#include <stdio.h>

struct pessoa{
	char nome [20];
	int idade;
	int rg;
	float altura;
};

//Alterando a declaração de 'struct pessoa nome-struct;' para apenas 'Pessoa nome-struct;'; 
typedef struct pessoa Pessoa;

int main(void){
	
	Pessoa cadastro_pessoa;
	
	printf("Informe o nome da pessoa: \n");
	scanf("%[^\n]", cadastro_pessoa.nome);
	
	printf("Informe a idade da pessoa: \n");
	scanf("%d", &cadastro_pessoa.idade);
	
	printf("Informe o rg da pessoa: \n");
	scanf("%d", &cadastro_pessoa.rg);
	
	printf("Informe a altura da pessoa: \n");
	scanf("%f", &cadastro_pessoa.altura);
	
	
	printf("Dados da pessoa:\nNome: %s\tIdade: %d\tRg: %d\tAltura: %.2f", cadastro_pessoa.nome, cadastro_pessoa.idade, cadastro_pessoa.rg, cadastro_pessoa.altura);
	
	return 0;
}
