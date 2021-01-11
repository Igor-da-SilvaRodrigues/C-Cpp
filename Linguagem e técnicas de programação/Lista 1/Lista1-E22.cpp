#include<stdio.h>

int main() {
	
	float hora,min,hdia;
	
	printf("DIGITE A HORA :");
	scanf("%f",&hora);
	printf("DIGITE o minuto :");
	scanf("%f",&min);
	
	hdia=hora+(min/60);
	
	printf("JA SE PASSARAM :%f horas",hdia);	
	return 0;
}
