//PILHA-LIFO	
//Igor da Silva Rodrigues
//22/11/20
#include <stdio.h>
#include <stdlib.h>

struct celulaLista {
		int dado;
		struct celulaLista *proxCel;
		
	};
		
typedef struct p{
	struct celulaLista* topo;							 
} Pilha;

void empilhar(Pilha** p, int val);
int desempilhar(Pilha* p);

void inserirNoInicio(int valor, struct celulaLista **inicio);
void inserirNoFinal(int valor, struct celulaLista **inicio);
void deletarLista(struct celulaLista **inicio);
void deletarNo(struct celulaLista **prevCel, int valor);
void exibirListaApos(struct celulaLista *inicio);
void modificarCelulas(struct celulaLista *inicio, int old, int val);
void modificarPrimeiraOcorrencia(struct celulaLista *inicio, int old, int val);
struct celulaLista* buscarCelula(int alvo, struct celulaLista *inicio);
struct celulaLista* buscarIndice(int indice, struct celulaLista* inicio);
void pause();


Pilha* pilha = NULL;

int main(){
	int v, op;
	int* V;
	
	
	//pilha = malloc(sizeof(Pilha));
	
	while(1){
		printf("1- Empilhar\n2- Desempilhar\n0- Sair\n");
			scanf("%d", &op);
			switch(op){
				case 1:
					printf("    Insira o numero a ser empilhado:\n    ");
					scanf("%d", &v);
					empilhar(&pilha, v);
					break;
				case 2:
					//v = desempilhar(pilha);
					printf("    |%d\n", desempilhar(pilha));					
					break;
				case 0:
					return 0;
					break;
				default:
					printf("Opcao invalida!\n");
			}
	}	
return 0;
}

void empilhar(Pilha** p, int val){
	if ((*p) != NULL){
		inserirNoInicio(val, &((*p)->topo) );
	}else{
		//printf("Pilha nao incializada!\n");
		(*p) = malloc(sizeof(Pilha));
		(*p)->topo = NULL;
		empilhar(p, val);
	}
}

int desempilhar(Pilha* p){
	int val;
	struct celulaLista* aux = NULL;
	if (p!= NULL && p->topo != NULL){
		//aux = buscarIndice(0, (p)->topo);
		//printf("aux buscado\n");
		val = (p->topo->dado);
		deletarNo(&(p->topo), val);
		return val;
	}else{
		printf("PILHA VAZIA OU NULA!!\n");
	}
}





void inserirNoInicio(int valor, struct celulaLista **inicio){
	struct celulaLista *novaCelula;
	//novaCelula = new celulaLista();
	novaCelula = malloc(sizeof(struct celulaLista));
		novaCelula->dado = valor;
		novaCelula->proxCel = (*inicio);
		(*inicio) = novaCelula;
}

void inserirNoFinal(int valor, struct celulaLista **inicio){
	struct celulaLista *novaCelula;
	if ((*inicio) != NULL){
		struct celulaLista *aux = (*inicio);
		while ( aux->proxCel != NULL){
			aux = aux->proxCel;
		}
		novaCelula = malloc(sizeof(struct celulaLista));
		novaCelula->dado = valor;
		novaCelula->proxCel = aux->proxCel;
		aux->proxCel = novaCelula;
		
	}else{
		novaCelula = malloc(sizeof(struct celulaLista));
		novaCelula->dado = valor;
		novaCelula->proxCel = (*inicio);
		(*inicio) = novaCelula;
	}
}

void deletarLista(struct celulaLista **inicio){
	if ((*inicio) != NULL){//...................................Se a lista e não-nula;
		struct celulaLista *nextCel = (*inicio)->proxCel;//.....NextCel recebe a segunda celula da lista, seja ela nula ou não;
		if (nextCel == NULL){//.................................Se a lista só pussui uma casa não há como avançar com o nextCel
			free((*inicio));//..................................portanto, apenas deleta-se a unica casa da lista, e seta o ponteiro como nulo;
			(*inicio) = NULL;
		}else{//................................................Se a lista possui duas ou mais casas
			do{//...............................................libera-se o ponteiro, e ambos andam uma casa até que o nextCel seja nulo (não pode mais avançar);
				free((*inicio));
				(*inicio) = nextCel;
				nextCel = nextCel->proxCel;
			}while (nextCel != NULL);
			free((*inicio));//..................................libera-se a ultima casa sobrando e seta o ponteiro como nulo;
			(*inicio) = NULL;
		}
		
	}
}

void deletarNo(struct celulaLista **inicio, int valor){ //comentar a linha A e "descomentar" a linha B para deletar apenas a primeira ocorrência
	struct celulaLista *prevCel;                        //comentar a linha B e "descomentar" a linha A para deletar todas as ocorrências
	struct celulaLista *currentCel;
	int cont = 0;
	if ((*inicio) == NULL){
		printf("Lista nao inicializada\n");
		system("pause");
	}else{
		prevCel = (*inicio);
		currentCel = (*inicio)->proxCel;
		if(currentCel == NULL ){			
			if (valor == prevCel->dado){
				(*inicio) = currentCel;
				free(prevCel);
			}
		}else{
			if (valor == prevCel->dado){
				(*inicio) = currentCel;
				free(prevCel);
				prevCel = currentCel;
				currentCel = currentCel->proxCel;
				//deletarNo(&(*inicio), valor);   //linha A
			} else{
				while (currentCel != NULL){
					if (valor == currentCel->dado){
						prevCel->proxCel = currentCel->proxCel;
						free(currentCel);
						currentCel = prevCel->proxCel;
						break;                            //linha B
					}else{
						prevCel = currentCel;
						currentCel = currentCel->proxCel;
					}	
				}		
			}
		}
	}
}

void exibirListaApos(struct celulaLista *inicio){
	struct celulaLista *currentCel = inicio;
	printf("-----\n");
	while (currentCel != NULL){
		printf("%d\n", currentCel->dado);
		currentCel = currentCel->proxCel;
	}
	printf("-----\n");
}

void modificarCelulas(struct celulaLista *inicio, int old, int val){
	if (inicio != NULL){
		//celulaLista *nextCel = inicio->proxCel;
		while (inicio != NULL){
			if (inicio->dado == old){
				inicio->dado = val;
			}
			inicio = inicio->proxCel;
		}
	}
}

void modificarPrimeiraOcorrencia(struct celulaLista *inicio, int old, int val){
		//celulaLista *nextCel = inicio->proxCel;
		//while (inicio != NULL && inicio->dado != old){
		//	inicio = inicio->proxCel;
		//}
		inicio = buscarCelula(old, inicio);
		if (inicio != NULL){
			inicio->dado = val;	
		}
		else{
			printf("Valor nao encontrado\n");
		}
}

struct celulaLista* buscarCelula(int alvo, struct celulaLista *inicio){
	if (inicio != NULL){
		while (inicio != NULL){
			if (inicio->dado == alvo){
				return inicio;
			}
			inicio = inicio->proxCel;
		}
		
	}
	return NULL;
}

struct celulaLista* buscarIndice(int indice, struct celulaLista* inicio){
	int i = 0;
	if (inicio != NULL){
		for(; i<indice && inicio != NULL; i++){
			inicio = inicio->proxCel;
			printf("passando\n");
		}
		return inicio;		
	}
	return NULL;
	
}

void pause(){
	fflush(stdin);
	printf("Preciona qualquer tecla para continuar. . .\n");
	getchar();
}
