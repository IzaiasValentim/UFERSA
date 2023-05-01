#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	int i;
	int dado = 0;
	int tamanho = 8;
	int A[tamanho];
	
	printf("Informe 8 valores para compor o vetor A\n");
	for(i=0;i<tamanho;i++){
		
		printf("informe o %d valor: ",i+1);
		scanf("%d",&dado);
		A[i] = dado;
		
	}
	
	printf("Vetor A na ordem inversa: \n");
	printf("[");
	
	while((i-1)>=0){
		
		printf("%d",A[i-1]);
		i--;
		
		if(i<=0){
			
			printf("]");
			return 0;
		}
		
		printf(",");
	}
	
	
	
	
	return 0;
	
}
