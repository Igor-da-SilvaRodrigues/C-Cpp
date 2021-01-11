
#include <stdio.h>
#include <stdlib.h>

typedef struct ListaS{ 
	int info; 
	struct ListaS *prox; 
}Lista; 

void inserirNoFinal(int valor, Lista **inicio);
Lista* concatena(Lista* L1, Lista* L2); 

int main(){
	
}


Lista* concatena(Lista* L1, Lista* L2){ // concatena L1 no final de L2!!!
	Lista* aux;
		aux = L1;
		while (aux != NULL){
			inserirNoFinal(aux->info, &L2);
			aux = aux->prox;
		}	
	return L2;
}

void inserirNoFinal(int valor, Lista **inicio){
	Lista *novaCelula;
	if ((*inicio) != NULL){
		Lista *aux = (*inicio);
		while ( aux->prox != NULL){
			aux = aux->prox;
		}
		novaCelula = new Lista();
		novaCelula->info = valor;
		novaCelula->prox = aux->prox;
		aux->prox = novaCelula;
		
	}else{
		novaCelula = new Lista();
		novaCelula->info = valor;
		novaCelula->prox = (*inicio);
		(*inicio) = novaCelula;
	}
}
