#include <stdio.h>
#include <stdlib.h>

struct Lista{
	int val;
	Lista* prox;
};

Lista* inverterLista(Lista* lista){
	Lista* aux = NULL;
	Lista* inicio = NULL;
	Lista* novo = NULL;
	
	for (aux = lista; aux != NULL; aux = aux->prox ){
		novo = new Lista();
		novo->val = aux->val;
		novo->prox = inicio;
		inicio = novo;
	}
	
	return(inicio);
	
	
	
}



int main(){
	
	Lista* aux = NULL;
	
	Lista* novo = NULL;
	Lista* inicio = NULL;
	

	for (int i = 0; i<10; i++){
	
		novo = new Lista();
		novo->val = i;
		novo->prox = inicio;
		inicio = novo;
		}
		
	printf("\n ----LISTA CONVENCIONAL----\n");
	for (aux = inicio; aux != NULL; aux = aux->prox){
		printf("%d", aux->val);
				
	}
		
	
	inicio = inverterLista(inicio);
		
	
	printf("\n ----LISTA INVERTIDA----\n");
	for (aux = inicio; aux != NULL; aux = aux->prox){
		printf("%d", aux->val);
				
	}	
		
		
		
	printf("\n\n");
	system("pause");
	return(0);
	
}
