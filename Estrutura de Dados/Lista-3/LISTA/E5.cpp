#include <stdio.h>
#include <stdlib.h>

typedef struct ListaS{ 
	int info; 
	struct ListaS *prox; 
}Lista; 


void deletarPrimeiroNo(Lista** inicio);
Lista* deletar(Lista** inicio, unsigned int n);


int main(){
	
	
	return 0;
}

Lista* deletar(Lista** inicio, unsigned int n){
	for (int i = 0; i<n; i++ ){
		deletarPrimeiroNo(inicio);
	}
	return (*inicio);
}

void deletarPrimeiroNo(Lista** inicio){
	Lista* aux;
	if ((*inicio) != NULL){
		aux = (*inicio)->prox;
		delete((*inicio));
		(*inicio) = aux;
	}
}
