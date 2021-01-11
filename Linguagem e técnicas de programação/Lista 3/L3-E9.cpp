#include <stdio.h>
#include <stdlib.h>
int enulo(float i);
int main(){
	int v;
	printf("Insira um valor: ");
	scanf("%d",&v);
	if (enulo(v)){
		printf("E NULO\n");
	}else{
		printf("NAO E NULO\n");
	}
	system("pause");
}
int enulo(float i){
	if (i==0){
		return (1);
	}else{
		return (0);
	}
}
