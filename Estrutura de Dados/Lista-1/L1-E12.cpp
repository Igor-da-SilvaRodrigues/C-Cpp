#include <stdio.h>
#include <stdlib.h>

struct Lista{
	int val;
	Lista* prox = NULL;
};


Lista* getPar(Lista* lista){
	
	Lista* aux = NULL;
	Lista* inicio = NULL;
	Lista* novo = NULL;
	
	for (aux = lista; aux != NULL; aux = aux->prox){
		
		if ( ( aux->val ) % 2 == 0 ){
			novo = new Lista();
			novo->val = aux->val;
			novo->prox = inicio;
			inicio = novo;	
			
		}
		
	}
	
	return (inicio);
}

int main(){
		Lista* aux = NULL;
		Lista* novo = NULL;
		Lista* inicio = NULL;
		Lista* result = NULL;
		
		for (int i = 0; i<10; i++){
			
			novo = new Lista();
			novo->val = i;
			novo->prox = inicio;
			inicio = novo;
			
		}
		
		result = getPar(inicio);
		
		for (aux = result; aux != NULL; aux = aux->prox){
			printf("%d", aux->val);
		} 
		printf("\n");
		
		system("pause");
		return(0);	
}
