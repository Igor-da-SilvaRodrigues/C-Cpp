#include <stdlib.h>
#include <stdio.h>
int main(){
	char produto[50];
	float valortot, desconto, valordesc;
	
	printf ("Insira o nome do produto\n");
	gets(produto);
    printf("Insira o valor do produto\n");
    scanf("%f",&valortot);
    
    desconto=0.1*valortot;
    valordesc=valortot-desconto;
    
    printf("\n\n\nProduto  (-%s-)\nvalor total: %.2f R$\nvalor do desconto: %.2f R$\nvalor a ser pago: %.2f R$\n",produto, valortot,desconto,valordesc);
}
