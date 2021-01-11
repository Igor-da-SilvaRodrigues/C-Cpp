#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int eposi(float i);
int enulo(float i);
float delta(float a, float b, float c);
int main(){
	//ax2+bx+c=0
	float x,y,z,resultado,r1,r2;
	do{
	printf("Insira os valores a b e c(separados por barra de espaco, a diferente de 0)\n");
	scanf("%f %f %f",&x ,&y ,&z);
	}while (x==0);
	resultado=delta(x,y,z);
	if (eposi(resultado)){
		printf("Raizes sao reais\n");
		r1=((-y)-sqrt(resultado))/2*x;
		r2=((-y)+sqrt(resultado))/2*x;
		printf("r1:%f\nr2:%f",r1,r2);
	}
	else{
		printf("Raizes sao complexas\n");
		resultado=resultado*(-1);
		printf("\nr1= -%f + %fi / %f", y, sqrt(resultado), 2*x);
		printf("\nr2= -%f - %fi / %f", y, sqrt(resultado), 2*x);
		//r1=((-y)-sqrt(resultado))/2*x;
		//r2=((-y)+sqrt(resultado))/2*x;
	}
	
	
	
}




int eposi(float i){
	if (i>=0){
		return(1);
	}else{
		return(0);          //A função retorna 1 se o numero for positivo, 0 se for negativo (ou igual a 0);
	}
}

int enulo(float i){
	if (i==0){
		return (1);
	}else{
		return (0);
	}
}

float delta(float a, float b, float c){
	//delta==b²-4ac
	float d=b*b;
	b=4*a*c;
	d=d-b;
	return(d);
}
