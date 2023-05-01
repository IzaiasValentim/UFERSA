#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	int valores[10],_maiorValor =0;
	int i;
	
	printf("Informe dez valores \n");
	
	for(i =0;i<10;i++){
		
		printf("Informe o %d valor: ",(i+1));
		scanf("%d",&valores[i]);
		
		
		if( valores[i] >= _maiorValor){
			
			_maiorValor = valores[i];
			
		}

	}
	
	printf("O maior valor do vetor é : %d", _maiorValor);
	
	return 0;
	
}
