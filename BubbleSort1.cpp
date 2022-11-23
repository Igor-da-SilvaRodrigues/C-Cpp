#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#define MAX 10


class Carro{
	private:
		char nome[100];
		char cor[20];
		char placa[20];
		double preco;
	public:
		 //   
		
		void inserirCarroNome(char *nome){
			strcpy(this->nome,nome);
		}
		void inserirCarroCor(char *cor){
			strcpy(this->cor,cor);
		}
		void inserirCarroPlaca(char *placa){
			strcpy(this->placa,placa);
		}
		void inserirCarroPreco(double preco){
			this->preco = preco;
		}
		
		
		
		char* getCarroNome(){
			return(nome);
		}
		char* getCarroCor(){
			return(cor);
		}
		char* getCarroPlaca(){
			return(placa);
		}
		double getCarroPreco(){
			return(preco);
		}
		
};


void bubbleSortCarros(Carro *carros, int tam){
	Carro aux;
	
	for(int i = tam; i >= 0; i--){
		for(int j = 0; j<=i ; j++){
			if (strcmp( carros[j-1].getCarroNome(), carros[j].getCarroNome()  ) == 1 ){
				aux  = carros[j-1];
				carros[j-1] = carros[j];
				carros[j] = aux;
			}
		}
	}
	
	
	
	
}


int main(){
	
	
	Carro carros[MAX];
	int i = 0;
	char opcao;
	char nome[100];
	char cor[20];
	char placa[20];
	double preco;
	
	while(1){
		std::cout<<"\nDigite o nome do carro: ";
		std::cin>>nome;
		std::cout<<"\nDigite o preco: ";
		std::cin>>preco;
		
		carros[i].inserirCarroNome(nome);
		carros[i].inserirCarroPreco(preco);
		
		std::cout<<"\nDeseja inserir mais um carro?   | <S>Sim  |  <N>Nao  |   ";
		std::cin>>opcao;
		if (opcao != 'S'){
			break;
		}
		
		
		i++;
	}
		std::cout<<std::endl;
		
		bubbleSortCarros(carros, i);
	
	for (int j = 0; j<=i; j++){
		std::cout<<"\n----------------\n";
		std::cout<<"Nome: "<<carros[j].getCarroNome()<<std::endl;
		std::cout<<"Preco: "<<carros[j].getCarroPreco()<<std::endl;
		std::cout<<"----------------\n";
		
	}
	
	
}
