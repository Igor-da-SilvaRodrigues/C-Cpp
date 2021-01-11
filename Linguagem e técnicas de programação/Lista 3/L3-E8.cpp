#include <stdio.h>
#include <stdlib.h>
int eposi(float i);
int main(){
	int v;
	printf("Insira um valor: ");
	scanf("%d",&v);
	if (eposi(v)){
		printf("Positivo\n");
	}else if (eposi(v)==0){
		printf("Negativo\n");
	}
	system("pause");
}
int eposi(float i){
	if (i>0){
		return(1);
	}else{
		return(0);          //A função retorna 1 se o numero for positivo, 0 se for negativo (ou igual a 0);
	}
}
