#include <stdlib.h>
#include <stdio.h>

int main(){
	int n_itens_estoque, n_itens_pedidos;
	printf("Insira o numero de itens em estoque\n");
	scanf("%d",&n_itens_estoque);
	printf("Insira o numero de itens a serem fornecidos\n");
	scanf("%d",&n_itens_pedidos);
	
	if (n_itens_estoque>=n_itens_pedidos){
		printf("Fornecimento possivel\nEstoque atualizado:%d",(n_itens_estoque-n_itens_pedidos));
	}
	else{
		printf("!!!ESTOQUE INSUFICIENTE!!!");
	}
	return 0;
}
