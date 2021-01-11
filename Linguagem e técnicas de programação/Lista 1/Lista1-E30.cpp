#include<stdio.h>
#include<math.h>>

int main (){
	
	int base,exp,valor;
	
	printf("DIGITE A BASE :");
	scanf("%d",&base);
	
	while (base<2){
		printf("Digite uma base maior ou igual que dois ");
		scanf("%d",&base);
	}

printf("DIGITE O EXPOENTE :");
scanf("%d",&exp);

while (exp<1){
	printf("DIGITE UM EXPOENTE MAIOR OU IGUAL A 1");
	scanf("%d",&exp);
}	

valor =pow(base,exp);
printf(" O valor eh = %d",valor);
	return 0;
}
