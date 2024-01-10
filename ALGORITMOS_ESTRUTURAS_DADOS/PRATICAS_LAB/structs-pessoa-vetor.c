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
	int indice;
	Pessoa cadastro_pessoa[2];
	
	for(indice= 0; indice < 2; indice++){
		
		printf("\n%d - PESSOA: ",indice+1);
		
		printf("Informe o nome da pessoa: \n");
		scanf(" %[^\n]", cadastro_pessoa[indice].nome);
		
		printf("Informe a idade da pessoa: \n");
		scanf("%d", &cadastro_pessoa[indice].idade);
		
		printf("Informe o rg da pessoa: \n");
		scanf("%d", &cadastro_pessoa[indice].rg);
		
		printf("Informe a altura da pessoa: \n");
		scanf("%f", &cadastro_pessoa[indice].altura);
	
		printf("\nDados da %dª pessoa:\nNome: %s\tIdade: %d\tRg: %d\tAltura: %.2f\n", indice+1, cadastro_pessoa[indice].nome, cadastro_pessoa[indice].idade, cadastro_pessoa[indice].rg, cadastro_pessoa[indice].altura);
	}
	
	
	
	return 0;
}
