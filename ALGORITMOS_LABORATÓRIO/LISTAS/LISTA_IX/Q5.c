#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	float vetorA[5],vetorB[5];
	int i,c;
	
	printf("Informe cinco valores reais para o vetor A \n");
	
	for(i=0;i<5;i++){
		
		printf("informe o %dº valor de A ",(i+1));
	
		scanf("%f",&vetorA[i]);
		
		if(i == 0){
			
			vetorB[i] = vetorA[i];
			
		}else if(i%2 == 0){
			
			vetorB[i] = vetorA[i]*5;
			
		}else{
			
			vetorB[i] = vetorA[i]+5;
			
		}
		
	}
	
	printf("Vetor A = ");
	for(c =0;c<5;c++){
		
		printf(" %f ",vetorA[c]);
		
	}
	
	
	printf("\nVetor B = ");
	for(c =0;c<5;c++){
		
		printf("%f ",vetorB[c]);
		
	}
	
	return 0;
}
