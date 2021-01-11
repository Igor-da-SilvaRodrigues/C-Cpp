#include <stdio.h>
#include <stdlib.h>

struct Lista{
	int val;
	Lista* prox;
};


bool compareLista(Lista* a, Lista* b){
	Lista* auxa;
	Lista* auxb;
	
	for (auxa = a, auxb = b; auxa != NULL || auxb != NULL; auxa = auxa->prox, auxb = auxb->prox){
		
		if (auxa->val != auxb->val){
			return(false);
		}
		
	}
	
	return(true);
	
}


int main(){
	Lista* aux = NULL;
	
	Lista* novo = NULL;
	Lista* inicioa = NULL;
	Lista* iniciob = NULL;
	

	for (int i = 0; i<10; i++){
	
		novo = new Lista();
		novo->val = i;
		novo->prox = inicioa;
		inicioa = novo;
	}
	
		
	
	for (int i = 10; i>0; i--){
	
		novo = new Lista();
		novo->val = i;
		novo->prox = iniciob;
		iniciob = novo;
	}
		
	
	
	if (compareLista(inicioa, iniciob)){
		printf("\n E IGUAL \n");
	} else{
		printf("\n N E IGUAL \n");
	}
	
	
	system("pause");
	return(0);
	
	
	
}
