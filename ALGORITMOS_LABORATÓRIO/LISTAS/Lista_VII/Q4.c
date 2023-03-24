#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	int controle,operacao,total;
	
	controle = 10;
	total = 0;
	
	while(controle <=50){
	
		if(controle%2 == 0){
	
			printf("%d é divisível por 2\n",controle);
			total = total+1;
		}
	
	controle = controle+1;
	
	}
	
	printf("Entre [10,50] tem %d numeros divisiveis por 2",total);
	return 0;
}
