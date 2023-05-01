#include<stdio.h>
#include<locale.h>
#include<string.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	char nome[64];
	int controle;
	
	printf("Informe seu nome completo: ");
	gets(nome);
	
	for(controle = 0; controle<64;controle++){
		
		if(nome[controle] == '\0'){
		
			printf("O quantidade do nome é : %d", (controle));
		
			return;
		}
		
	}
	
	return 0;
}
