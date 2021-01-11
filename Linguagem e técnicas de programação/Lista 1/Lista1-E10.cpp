#include<stdio.h>

int main(){
	float alt;
	int cont=0,somaM,somaF,masc,fem, mediaF , mediaM, maior=0,menor=999,i;
	char sexo;
	
	for (i=0;i<=3;i++){
	printf("digite a altura :");
	scanf("%f%*C",&alt);
	
	printf("digite o sexo 'M' ou 'F':");
	scanf("%s%*C",&sexo);
	
	while ( sexo != 'M' && sexo != 'F'){
		printf("Entre somente com 'M' ou 'f' :");
		scanf("%s%*C",&sexo);
	}
	 if (alt > maior){
	 	maior = alt;
	 }
	 if (alt < menor) {
	    menor = alt;
	 }
	 
	 if (sexo == 'M'){
		 masc=masc+1;
		 somaM=somaM+alt;
	 }
	 
	 else {	
	 if(sexo == 'F');{
	 	fem=fem+1;
	 	somaF=somaF+alt;
	 }
}

}

mediaM = somaM/masc;
mediaF= somaF/fem;

printf("A maior altura foi: %d\n ", maior);
		printf("A menor altura foi: %d\n ", menor);
		printf("A media da altura das mulheres foi: %d\n ", mediaF);
		printf("A media da altura dos homens foi: %d\n ", mediaM);
	return 0;
}
