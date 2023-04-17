#include<stdio.h>
#include<locale.h>

float volume(float c,float l,float a);

int main(){
	setlocale(LC_ALL,"Portuguese");
	float c,l,a,_area;
	printf("--Cálculo do volume--\n");
	
	printf("--Informe o comprimento-- ");
	scanf("%f",&c);//Comprimento
	
	printf("--Informe o largura-- ");
	scanf("%f",&l);//Largura 
	
	printf("--Informe o altura-- ");
	scanf("%f",&a);//Altura 
	
	_area = volume(c,l,a);
	
	printf("O volume da caixa retangular é: %.2f",_area);
	
	return 0;
}

float volume(float c,float l,float a){
	
	float volume = c*l*a;
	 return(volume);

}
