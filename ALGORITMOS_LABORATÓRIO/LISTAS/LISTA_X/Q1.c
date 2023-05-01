#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	int matriz[3][4];
	int l,c;
	
	printf("Informe doze números inteiros");
	
	for(l=0;l<3;l++){
		
		printf("\nElementos da %dª linha\n",l+1);
		
		for(c=0;c<4;c++){
			
			printf("%dº número",c+1);
			scanf("%d",&matriz[l][c]);
			
		}
	}
	
	printf("\nMatriz na ordem inversa:\n");
	printf("[");
	
	for(l=3;l>0;l--){
		
		for(c=4;c>0;c--){
					
			printf(" %d ",matriz[l-1][c-1]);
					
		}
		printf("\n");
	}
	
	printf("]");
	return 0;
}
