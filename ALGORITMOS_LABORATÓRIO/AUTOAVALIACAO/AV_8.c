#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	int n,somatorio =0,controle;
	int total[n];
	
	printf("Quantos valores inteiros deseja armazenar? ");
	scanf("%d",&n);
	
	printf("\n Informe os %d valores: ",n);
	for(controle =0; controle<n;controle++){
		
		printf("Informe o %dº valor ", (controle+1));
		scanf("%d",&total[controle]);
		
		if((total[controle]%2) != 0){
			
			somatorio += total[controle];
			
		}
		
	}
	
	printf("\n O somatório dos valores ímpares é: %d", somatorio);
	
	return 0;
}
