#include <stdlib.h>
#include <stdio.h>
int main(){
	char nome[5][50];
	float consumo [5], consumoemmil[5];
	int contador,economico=0;
	
	for (contador=0;contador<5;contador++){
		printf("Insira o nome do carro\n");
		scanf("%s",&nome[contador]);
		printf("Insira quantos quilometros o carro faz por litro de combustivel\n");
		scanf("%f",&consumo[contador]);
		if (contador==0){
			economico=contador;
		}
		else if (consumo[contador]>consumo[economico]){
			economico=contador;
		}
		
		consumoemmil[contador]=1000/consumo[contador];
	}
	
	printf("\nO carro mais economico foi %s\n",nome[economico]);
	
	for (contador=0;contador<5;contador++){
		printf("%s           %f\n",nome[contador],consumoemmil[contador]);
	}
	
	
}
