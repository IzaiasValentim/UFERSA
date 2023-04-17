#include<stdio.h>
#include<locale.h>

void multiplo(int numero);

int main(){
	setlocale(LC_ALL,"Portuguese");
	int numero;
	printf("Informe um número ");
	scanf("%d",&numero);
	multiplo(numero);
	
	return 0;
}

void multiplo(int numero){
	if(numero%5 == 0){
		
		printf("%d é multiplo de 5", numero);
		
	}else{
		
		printf("%d não é multiplo de 5",numero);
		
	}
}
