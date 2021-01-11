#include <stdio.h>
#include <stdlib.h>

struct Lista{
	int val;
	Lista* prox = NULL;
};


void trocarLugar(Lista* ca, Lista* cb){
	
	int aux;
	aux = cb->val;
	cb->val = ca->val;
	ca->val = aux;
		
}

Lista* sortLista(Lista* a, Lista* b){
	int i;
	Lista* inicio = a;
	Lista* aux = NULL;
	Lista* proxaux = NULL;
	
	for (aux = a; aux->prox != NULL; aux = aux->prox){	
	}                                                          //CONCATENACAO DAS LISTAS;
	aux->prox = b;
	 printf("\n\n");
	for (aux = a; aux != NULL; aux = aux->prox){
		printf("-%d", aux->val);
	}
	printf("\n\n");
	
	
	do{
		
		i = 0;
	
		aux = a;
		proxaux = aux->prox; 
		//    ATRIBUIÇÕES, COMPARA CASA 1 COM 2...;  PARA QUANDO A CASA A SER COMPARADA FICA NULA; PASSA AS CASAS PARA SUAS PROXIMAS;
		
		for (; proxaux != NULL; aux = aux->prox, proxaux = proxaux->prox){
			
			if (proxaux->val < aux->val ){
				i++;
				trocarLugar(aux, proxaux);
			}
			
		}	
	}while (i>0);
	
	
	return(inicio);
}

int main(){
	Lista* aux = NULL;
	Lista* novo = NULL;
	Lista* inicioa = NULL;
	Lista* iniciob = NULL;
	Lista* result = NULL;
	
	
	
	for (int i = 1; i<5; i++){
		novo = new Lista();
		novo->val = i*2;
		novo->prox = inicioa;
		inicioa = novo;
	}
	
	
	printf("INICIOA----------\n");
	for (aux = inicioa; aux != NULL; aux = aux->prox){
		printf("-%d", aux->val);
	}
	printf("\n\n\n");
	for (int i = 1; i<5; i++){
		novo = new Lista();
		novo->val = i*3;
		novo->prox = iniciob;
		iniciob = novo;
	}
	printf("INICIOB----------\n");
	for (aux = iniciob; aux != NULL; aux = aux->prox){
		printf("-%d", aux->val);
	}
	printf("\n\n\n");
	
	result = sortLista(inicioa, iniciob);
	
	
	printf("\n\n\n");
	for (aux = result; aux != NULL; aux = aux->prox){
		printf("-%d", aux->val);
	}
	
}
