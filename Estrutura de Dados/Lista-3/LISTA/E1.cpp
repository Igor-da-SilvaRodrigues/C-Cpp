#include <stdio.h>
#include <stdlib.h>

typedef struct ListaS{ 
	int info; 
	struct ListaS *prox; 
} Celula; 

int contCel(Celula* Inicio);

int main(){
	return 0;
};

int contCel(Celula* Inicio){
	int cont;
	Celula* aux;
	if (Inicio != NULL){
		aux = Inicio;
		while (aux != NULL){
			cont++;
			aux = aux->prox;
		}
	}
	return cont;
}
