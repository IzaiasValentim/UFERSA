#include<stdio.h>
#include<locale.h>

void par_impar(int numero);

int main(){
	setlocale(LC_ALL,"Portuguese");
	int numero;
	printf("Informe um n�mero ");
	scanf("%i",&numero);
	par_impar(numero);
	return 0;
}

void par_impar(int numero){
	
	if(numero%2 == 0){
	
		printf("%i numero � par",numero);
	
	}else{
		
		printf("%i numero � �mpar",numero);
		
	}
	
}
