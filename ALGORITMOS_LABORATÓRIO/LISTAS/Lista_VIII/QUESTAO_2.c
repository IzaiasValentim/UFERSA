#include<stdio.h>
#include<locale.h>

void verifica(int numero);

int main(){
	int n;
	setlocale(LC_ALL,"Portuguese");
	printf("Informe um n�mero \n");
	scanf("%d",&n);
	verifica(n);
	
	return 0;
}

void verifica(int numero){
	
	if(numero>0){
		
		printf("%d � positivo",numero);
	
	}else if(numero <0 ){
		
		printf("%d � negativo", numero);
		
	}else{
		
		printf("O n�mero � neutro");
		
	}
	
	
}
