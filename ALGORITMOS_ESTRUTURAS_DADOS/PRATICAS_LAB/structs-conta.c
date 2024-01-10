/*
	PROGRAMA QUE RECEBE DADOS DE 5 CONTAS BANCÁRIAS:
		DADOS:
			*ADENCIA;
			*NUM CONTA;
			*SENHA;
			*SALDO, E
			*NOME.
*/
#include <stdio.h>

typedef struct conta{
	
	int agencia;
	int num_conta;
	char senha[20];
	float saldo;
	char nome[20];
}Conta;

int main(void){
	Conta dados_contas[2];
	int indice;
	
	for(indice= 0; indice < 2; indice++){
		
		printf("\n%d - CONTA: ",indice+1);
		
		printf("Informe a agencia: \n");
		scanf("%d", &dados_contas[indice].agencia);
		
		printf("Informe o numero da conta: \n");
		scanf("%d", &dados_contas[indice].num_conta);
		
		printf("Informe a senha(até 20 digitos): \n");
		scanf(" %[^\n]", &dados_contas[indice].senha);
		
		printf("Informe o saldo da conta: \n");
		scanf("%f", &dados_contas[indice].saldo);
		
		printf("Informe o nome do titular: \n");
		scanf(" %[^\n]", &dados_contas[indice].nome);
		
		printf("\nDados da %dª conta:\nNome: %s\tAgencia: %d\tNum. Conta: %d\tSenha: %s\tSaldo: %f\tNome: %s", indice+1, dados_contas[indice].nome, dados_contas[indice].agencia, dados_contas[indice].num_conta, dados_contas[indice].senha, dados_contas[indice].saldo);
	}
	
	
	
	
	return 0;
}
