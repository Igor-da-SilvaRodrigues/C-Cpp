//soma dos itens;
#include <stdio.h>
#include <stdlib.h>
#include <string>

using std::string;

typedef struct celulaLista {
		int dado;
		struct celulaLista *proxCel;
		
	}CelulaLista;

int somaRecursiva(CelulaLista* inicio);
int somaDados(CelulaLista* inicio);
void inserirNoInicio(int valor, CelulaLista **inicio);
void inserirNoFinal(int valor, CelulaLista **inicio);
void deletarLista(CelulaLista **inicio);
void deletarNo(CelulaLista **prevCel, int valor);
void exibirListaApos(CelulaLista *inicio);
void modificarCelulas(CelulaLista *inicio, int old, int val);
void modificarPrimeiraOcorrencia(CelulaLista *inicio, int old, int val);
CelulaLista* buscarCelula(int alvo, CelulaLista *inicio);


CelulaLista *Inicio;

int main(){
	Inicio = NULL;
	int v, old, opcao;
	string aviso;
	while (1){
		system("cls");
		printf("\n1-Inserir uma nova celula\n2-Exibir a Lista\n3-Somar os itens (Iterativa)\n4-Somar os itens (Recursiva)                  %s\n", aviso.c_str());
		scanf("%d", &opcao);
		switch(opcao){
			case 1://Inserir uma nova celula no inicio
				system("cls");
				printf("Insira um valor\n");
				scanf("%d", &v);
				aviso = "Valor inserido!";
				inserirNoInicio(v, &Inicio);
				break;
			case 2://Exibir a Lista
				system("cls");
				exibirListaApos(Inicio);
				aviso = "";
				system("pause");
				break;
			case 3:
				v = somaDados(Inicio);
				printf("A soma dos dados = %d\n", v);
				system("pause");
				aviso = "";
				break;
			case 4:
				v = somaRecursiva(Inicio);
				printf("A soma dos dados = %d\n", v);
				system("pause");
				aviso = "";
				
				break;
			default:
				
				return(0);
			break;
		}
	}	
return 0;
}

int somaRecursiva(CelulaLista* inicio){
	int val = 0;
	if (inicio != NULL){
		val = inicio->dado;
		val += somaRecursiva(inicio->proxCel);
	}
	return val;
}

int somaDados(CelulaLista* inicio){
	int val = 0;
	for (; inicio != NULL; inicio = inicio->proxCel){
		val = val + inicio->dado;
	}
	return val;
}
void inserirNoInicio(int valor, CelulaLista **inicio){
	CelulaLista *novaCelula;
	//novaCelula = new celulaLista();
	novaCelula = new CelulaLista();
		novaCelula->dado = valor;
		novaCelula->proxCel = (*inicio);
		(*inicio) = novaCelula;
}

void inserirNoFinal(int valor, CelulaLista **inicio){
	CelulaLista *novaCelula;
	if ((*inicio) != NULL){
		CelulaLista *aux = (*inicio);
		while ( aux->proxCel != NULL){
			aux = aux->proxCel;
		}
		novaCelula = new CelulaLista();
		novaCelula->dado = valor;
		novaCelula->proxCel = aux->proxCel;
		aux->proxCel = novaCelula;
		
	}else{
		novaCelula = new CelulaLista();
		novaCelula->dado = valor;
		novaCelula->proxCel = (*inicio);
		(*inicio) = novaCelula;
	}
}

void deletarLista(CelulaLista **inicio){
	if ((*inicio) != NULL){//...................................Se a lista e não-nula;
		CelulaLista *nextCel = (*inicio)->proxCel;//.....NextCel recebe a segunda celula da lista, seja ela nula ou não;
		if (nextCel == NULL){//.................................Se a lista só pussui uma casa não há como avançar com o nextCel
			delete((*inicio));//..................................portanto, apenas deleta-se a unica casa da lista, e seta o ponteiro como nulo;
			(*inicio) = NULL;
		}else{//................................................Se a lista possui duas ou mais casas
			do{//...............................................libera-se o ponteiro, e ambos andam uma casa até que o nextCel seja nulo (não pode mais avançar);
				delete((*inicio));
				(*inicio) = nextCel;
				nextCel = nextCel->proxCel;
			}while (nextCel != NULL);
			delete((*inicio));//..................................libera-se a ultima casa sobrando e seta o ponteiro como nulo;
			(*inicio) = NULL;
		}
		
	}
}

void deletarNo(CelulaLista **inicio, int valor){ //comentar a linha A e "descomentar" a linha B para deletar apenas a primeira ocorrência
	CelulaLista *prevCel;                        //comentar a linha B e "descomentar" a linha A para deletar todas as ocorrências
	CelulaLista *currentCel;
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
				delete(prevCel);
			}
		}else{
			if (valor == prevCel->dado){
				(*inicio) = currentCel;
				delete(prevCel);
				prevCel = currentCel;
				currentCel = currentCel->proxCel;
				//deletarNo(&(*inicio), valor);   //linha A
			} else{
				while (currentCel != NULL){
					if (valor == currentCel->dado){
						prevCel->proxCel = currentCel->proxCel;
						delete(currentCel);
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

void exibirListaApos(CelulaLista *inicio){
	CelulaLista *currentCel = inicio;
	
	while (currentCel != NULL){
		printf("%d\n", currentCel->dado);
		currentCel = currentCel->proxCel;
	}
	
}

void modificarCelulas(CelulaLista *inicio, int old, int val){
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

void modificarPrimeiraOcorrencia(CelulaLista *inicio, int old, int val){
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

CelulaLista* buscarCelula(int alvo, CelulaLista *inicio){
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

