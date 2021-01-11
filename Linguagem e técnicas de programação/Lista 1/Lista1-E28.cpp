#include<stdio.h>

int main(){
	
	int v1,v2,div;
	
	printf("digite um valor :\n");
	scanf("%d %d",&v1,&v2);
	
	if (v2== 0){
		printf("VALOR DIGITADO INVALIDO, digite novamente :");
		scanf("%d",&v2);
	}
	
	div = v1/v2;
	
	printf("%d",div);
	
	
	
	return 0;
}
