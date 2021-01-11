#include <stdio.h>
#include <stdlib.h>
float delta(float a, float b, float c);
int main(){
	float x,y,z;
	float resultado;
	printf("Insira os valores de a b e c(separados por barra de espaço)\n:: ");
	scanf("%f %f %f", &x, &y, &z);
	resultado=delta(x,y,z);
	printf("%.2f",resultado);
}
float delta(float a, float b, float c){
	//delta==b²-4ac
	float d=b*b;
	b=4*a*c;
	d=d-b;
	return(d);
}
