#include<stdio.h>
#include<locale.h>

void verifica_idade(int idade);

int main(){
	setlocale(LC_ALL,"Portuguese");
	int idade;
	printf("Informe a sua idade ");
	scanf("%d",&idade);
	verifica_idade(idade);
	
	return 0;
}

void verifica_idade(int idade){
	if(idade >= 18){
		
		printf("Com %d anos você é maior de idade",idade);
		
	}else{
		
		printf("Com %d anos você é menor de idade",idade);
		
	}
}
