#include <stdio.h>
#include <string.h>
int main(){
	int sexo,idade,v1,v2;
	char nome[50];
	
	printf("Insira um nome\n");
	gets(nome);
	printf("Insira seu sexo\n1-feminino\n2-masculino\n");
	scanf("%d",&sexo);
	switch (sexo){
		case 1:
			v1=1;
			break;
		case 2:
		    v1=0;
			break;
		default :
		printf("codigo invalido\n");
		break;
	}
	printf("Insira sua idade\n");
	scanf("%d",&idade);
	if (idade<25){
		v2=1;
	}
	else{
		v2=0;
	}
	if (v1==1 && v2==1){
		printf("ACEITA");
		
	}
	else{
		printf("NAO ACEITA");
	}
}
