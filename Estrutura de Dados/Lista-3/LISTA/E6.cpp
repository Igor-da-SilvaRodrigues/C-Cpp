#include <stdio.h>
#include <stdlib.h>

typedef struct ListaS{ 
	int info; 
	struct ListaS *prox; 
}Lista;

Lista* quebrarLista(Lista* inicio, int n);


int main(){
	
}

Lista* quebrarLista(Lista* inicio, int n){
	Lista* aux;
	Lista* Lista2;
	if (inicio != NULL){
		aux = inicio;
		while (aux != NULL && aux->info != n){
			aux = aux->prox;
		}
		if (aux != NULL){
			Lista2 = aux->prox;
			aux->prox = NULL;
			return Lista2;
		}
	}
	return NULL;
}
