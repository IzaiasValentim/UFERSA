#include<stdio.h>
#include<locale.h>

int calc_fatorial(int numero);

int main(){
	setlocale(LC_ALL,"Portuguese");
	int n,fatorial;
	printf("--C�lculo do fatorial--\n");
	
	do{
		printf("--Informe o n�mero--");
		scanf("%d",&n);	
		
	}while(n<0);
	
	fatorial =calc_fatorial(n);
	
	printf("%d! �: %d ",n,fatorial);
	return 0;
}

int calc_fatorial(int numero){
	int fatorial = 1,i=1;
	
	for(i;i<=numero;i++){
		
		fatorial *= i;
		
	}
	return fatorial;
	
}
