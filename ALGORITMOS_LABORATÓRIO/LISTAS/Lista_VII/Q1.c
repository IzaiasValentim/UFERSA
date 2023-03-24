#include <stdio.h>
#include <locale.h>

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	printf("Contagem de 500 até 0\n");
	int i = 0;
	for(i; i<500; i++){
		printf("%d ",i);
	}
	
	
	return 0;
}
