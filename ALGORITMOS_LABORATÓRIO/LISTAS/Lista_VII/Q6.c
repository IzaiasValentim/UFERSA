#include <stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	int i, fatorial,n;
	
	printf("Informe qual fatorial desejas calcular\n");
	scanf("%d",&n);
	
	if(n>=0){
	
		fatorial =1 ;
		for(i=1;i<=n;i++){
	
			fatorial = fatorial*i;
		
		}
		
		printf("%d! = %d",n,fatorial);
		return 0;
			
	}else{
	
		printf("N�o existe fatorial de n�mero negativo");
		return 1;
	
	}
	
}
