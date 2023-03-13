#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");	
		
	float volume,comprimento,largura,altura;
	
	printf("Informe o comprimentio, largura e altura: ...\n");
	scanf("%f%f%f",&comprimento,&largura,&altura);
	
	volume = comprimento*largura*altura;
	
	printf("O volume da caixa é: %.2f unidades de volume.",volume);
	
	return 0;
}
