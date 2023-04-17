#include<stdio.h>
#include<locale.h>

void verifica(int numero);

int main(){
	int n;
	setlocale(LC_ALL,"Portuguese");
	printf("Informe um número \n");
	scanf("%d",&n);
	verifica(n);
	
	return 0;
}

void verifica(int numero){
	
	if(numero>0){
		
		printf("%d é positivo",numero);
	
	}else if(numero <0 ){
		
		printf("%d é negativo", numero);
		
	}else{
		
		printf("O número é neutro");
		
	}
	
	
}
