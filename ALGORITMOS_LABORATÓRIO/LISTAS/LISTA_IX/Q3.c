#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	int numeros[5], soma, i,s;
	int numero;
	printf("Informe cinco valores inteiros \n");
	
	for(i =0;i<5;i++){
		
		printf("Informe o %d valor ",(i+1));
		scanf("%d",&numero);
		numeros[i] = numero;
		
	}
	
	printf("A soma entre os valores: ");
	
	for(s = 0; s<i;s++){
		
		printf("%d ",numeros[s]);
		soma += numeros[s];
	}
	printf("é %d: ",soma);
	
	return 0;
}
