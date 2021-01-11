#include <stdlib.h>
#include <stdio.h>

int main(){
	float a,b,c;
	int t=0;
	printf("Insira os valores dos lados A, B, C de um triangulo:\n");
	scanf("%f",&a);
	scanf("%f",&b);
	scanf("%f",&c);
	
	if ((a*a)==(b*b)+(c*c)){
	t=1;
	}
	if((b*b)==(a*a)+(c*c)){
	t=1;
	}
	if((c*c)==(b*b)+(a*a)){
	t=1;
	}
	
	switch(t){
		case 1:
			printf("Os valores formam um triangulo retangulo.");
			break;
		case 0:
		    printf("Os valores NAO formam um triangulo retangulo.")	;
			break;		
	}
	getchar();
  return 0;
}
