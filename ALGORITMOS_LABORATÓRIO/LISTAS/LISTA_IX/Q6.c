#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	int v1[5],v2[5];
	int cont1,cont2,fatorial;
	
	printf("Informe cinco números inteiros: \n");
	
	for(cont1 =0;cont1<5;cont1++){
		
		printf("Informe o %dº número: ",(cont1+1));
		scanf("%d",&v1[cont1]);
		
		cont2 = v1[cont1];
		fatorial = 1;
		
		while(cont2>1){
			
		fatorial = fatorial*cont2; 	
		cont2--;
		
		}
		
		v2[cont1] = fatorial;
	}
	printf("\n Vetor 1 = ");
	for(cont1 =0;cont1<5;cont1++){
		
		printf(" %d ",v1[cont1]);		
	}
	
	printf("\n Vetor 2 = ");
	for(cont1 =0;cont1<5;cont1++){
		
		printf(" %d ",v2[cont1]);		
	}
	
	
	
	
	
	
	
	return 0;
}
