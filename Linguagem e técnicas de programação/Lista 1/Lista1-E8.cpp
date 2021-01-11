#include<stdio.h>

int main(){
	
	float alt,peso,valor;
	
	printf("entre com a altura e peso: ");
	scanf("%f %f",&alt,&peso);
	
	valor= peso/(alt*alt);

if (valor <= 18.5){
	printf("Abaixo do peso normal");
}
else if (valor >18.5 && valor <=25) {
	printf("Peso normal");
}
else if (valor >25 && valor <=30) {
	printf("Peso acima do normal");
}
else {
	printf("peso acima do normal");
}	
	return 0;
}
