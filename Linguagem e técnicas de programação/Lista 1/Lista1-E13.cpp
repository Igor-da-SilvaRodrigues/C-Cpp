#include<stdio.h>

int main() {
	
	float km, consumo;
	char type;
	
	printf("Digite a Quilometragem a ser percorrida e o tipo de carro (A,B,C) :");
	scanf("%f %c",&km,&type);
	
	switch (type){
		case ('A'):
		consumo = km/12;
		printf("O consumo em litros eh de :%.2f",consumo);break;
		case ('B'):
		consumo = km/9;
		printf("O consumo em litros eh de :%.2f",consumo);break;
		case ('C'):
			consumo = km/8;
		printf("O consumo em litros eh de :%.2f",consumo);break;
	}
	return 0;
}
