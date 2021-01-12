#include <stdio.h>
#include <stdlib.h>

struct celulaLista {
		int dado;
		struct celulaLista *proxCel;
		
	};

void inserirNoInicio(int valor, struct celulaLista **inicio);
void inserirNoFinal(int valor, struct celulaLista **inicio);
void deletarLista(struct celulaLista **inicio);
void deletarNo(struct celulaLista **prevCel, int valor);
void exibirListaApos(struct celulaLista *inicio);
void modificarCelulas(struct celulaLista *inicio, int old, int val);
void modificarPrimeiraOcorrencia(struct celulaLista *inicio, int old, int val);
struct celulaLista* buscarCelula(int alvo, struct celulaLista *inicio);
int contCel(struct celulaLista* Inicio);

struct celulaLista *Inicio;

int main(){
	Inicio = NULL;
	int v, old, opcao;
	
	while (1){
		system("cls");
		printf("\n1-Inserir uma nova celula no inicio\n2-Inserir uma nova celula no final\n3-Exibir a Lista\n4-Deletar a lista\n5-Deletar um valor\n6-Modificar valores\n7-Modificar primeira ocorrencia\n");
		scanf("%d", &opcao);
		switch(opcao){
			case 1://Inserir uma nova celula no inicio
				system("cls");
				printf("Insira um valor\n");
				scanf("%d", &v);
				inserirNoInicio(v, &Inicio);
				break;
			case 2://Inserir uma nova celula no final
				system("cls");
				printf("Insira um valor\n");
				scanf("%d", &v);
				inserirNoFinal(v, &Inicio);
				break;
			case 3://Exibir a Lista
				system("cls");
				exibirListaApos(Inicio);
				
				system("pause");
				break;
			case 4://Deletar a lista
				deletarLista(&Inicio);
				
				break;
			case 5://Deletar um valor
				system("cls");
				scanf("%d", &v);
				deletarNo(&Inicio, v);
				break;
			case 6://modificar valores
				system("cls");
				printf("Insira o valor a ser substituido\n");
				scanf("%d", &old);
				printf("Insira o novo valor\n");
				scanf("%d", &v);
				modificarCelulas(Inicio, old, v);
				break;
			case 7://modificar primeira ocorrencia
				system("cls");
				printf("Insira o valor a ser substituido\n");
				scanf("%d", &old);
				printf("Insira o novo valor\n");
				scanf("%d", &v);
				modificarPrimeiraOcorrencia(Inicio, old, v);
				break;
			case 8: 
				v = contCel(Inicio);
				printf("%d\n", v);
				system("pause");
				break;
			default:
				
				return(0);
			break;
		}
	}	
return 0;
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

int contCel(struct celulaLista* Inicio){
	int cont = 0;
	struct celulaLista* aux;
	if (Inicio != NULL){
		aux = Inicio;
		while (aux != NULL){
			cont++;
			aux = aux->proxCel;
		}
	}
	return cont;
}

