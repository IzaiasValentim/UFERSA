#include <stdio.h>
#include <locale.h>

int main(){
	int i, soma = 0;
	
	for(i=1;i<=500;i++){
		if(i%2 == 0){
		
			soma = soma + i;
			
		}
	}
	
	printf("A soma dos n�meros pares entre [1,500] �: %d",soma);
	
	return 0;
}
