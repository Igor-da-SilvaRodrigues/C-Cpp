#include<stdio.h>

int main(){
	
	int num, cont=0, soma=0;
	
	printf("digite um numero :");
	scanf("%d",&num);

    while(num>=0) {
    	cont=cont+1;
    	soma=soma+num;
    	printf("digite um numero :");
    	scanf("%d",&num);
	}
	
	printf("A soma dos numeros e de : %d\n",soma);
	printf("A quantidade dos numeros e de :%d\n",cont);
	
	getchar();
	return 0;
}
