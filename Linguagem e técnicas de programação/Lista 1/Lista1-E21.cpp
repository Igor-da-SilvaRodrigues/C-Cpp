#include<stdio.h>

int main(){
	
	float num,soma=0,divs,mult=1,sub;
do {
		printf("DIFITE UM NUMERO :");
	scanf("%f",&num);
	if (num!=0){
	
	soma=soma+num;
	mult=mult*num;}
	} while (num!= 0);
	
divs=mult/soma;
sub=soma-divs;

printf("A soma eh = %f",soma);
printf("A divisao eh= %f",divs);
printf("A subtracao eh= %f",sub);
printf("a multiplicacao eh= %f",mult);
	
	
	
	
	
	return 0;
}
