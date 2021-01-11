#include <stdio.h>
#include <stdlib.h>


typedef struct lista{
	int val;
	lista* prox;
}Lista;

Lista* novaCelula(int valor){
	Lista *novo;
	novo = new Lista();
	novo->val = valor;
	novo->prox = NULL;
	return (novo);
}

Lista* novaCelula(int valor, Lista* celulaAnterior){
	Lista *novo;
	novo = new Lista;
	novo->val = valor;
	novo->prox = NULL;
	celulaAnterior->prox = novo;
	return (celulaAnterior);
}

Lista* concatenar(Lista* a, Lista* b);

int main(){
	Lista* inicio = NULL;
	Lista* inicio2 = NULL;
	Lista* aux;
	inicio = novaCelula(1);
	//inicio->prox = novaCelula(2);
	novaCelula(2, inicio);
	novaCelula(3,inicio->prox);
	
	inicio2 = novaCelula(6);
	novaCelula(7, inicio2);
	novaCelula(8, inicio2->prox);
	
	
	Lista* resultado = NULL;
	resultado = concatenar(inicio, inicio2);
	
	for (aux = resultado; aux != NULL; aux = aux->prox){
		printf("%d", aux->val);
	}
	printf("\n");
	system("pause");	
	
		
}

Lista* concatenar(Lista* a, Lista* b){
	Lista* aux = NULL;
	
	for (aux = a; aux->prox != NULL; aux = aux->prox){
	}
	aux->prox = b;
	
	return(a);
}
