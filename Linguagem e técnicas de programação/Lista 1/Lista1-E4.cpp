#include <stdio.h>

int main(){
	int operacao;
	float raio,resultado;
	printf("Insira o raio da Circunferencia:\n");
	scanf("%f%*C",&raio);
	printf("Insira a operacao desejada:\n");
	printf("1- AREA\n2- CIRCUNFERENCIA\n");
	scanf("%d%*C",&operacao);
	
	switch(operacao){
		case 1:
			resultado=(3.14*raio*raio);
			printf("A area da circunferencia e: %.2f",resultado);
			break;
		
		case 2:
			resultado=(2*3.14*raio);
			printf("O perimetro da circunferencia e: %.2f",resultado);
			break;
		
		default:
			printf("O indicador de operacao inserido e invalido!!!");
			break;
	}
	
}
