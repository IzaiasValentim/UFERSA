#include<stdio.h>
#include<locale.h>

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	int numero = 0;
	
	printf("Informe um n�mero...\n");
	scanf("%d",&numero);
	
	printf("O antecessor de %d �: %d\n",numero,numero-1);
	printf("O sucessor de %d �: %d\n",numero,numero+1);
	
	return 0;
}
