#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

class PessoaFisica{
	public:
		char nome[100];
		char cpf[100];
		int idade;
	
	cadastrarPessoa(char* nome, char* cpf, int idade){
		strcpy(this->nome, nome);
		strcpy(this->cpf, cpf);
		this->idade = idade;
	}
		
};




int buscarporNome(PessoaFisica pessoas[], char* nome);


int main(){
	char nome[100], cpf[20];
	int idade;
	int opcao=1;
	PessoaFisica listadepessoas[10];
	
		
	while (opcao != 0){
		std::cout<<"1-Inserir Nova pessoa\n2-Buscar Pessoa\n0-sair"<<std::endl;
		std::cin>>opcao;
		switch (opcao){
			case 1:
				
				
				std::cout<<"Insira o NOME do sujeito"<<std::endl;
				std::cin>>nome;
				std::cout<<"Insira o CPF do sujeito"<<std::endl;
				std::cin>>cpf;
				std::cout<<"Insira a IDADE do sujeito"<<std::endl;
				std::cin>>idade;
				
				listadepessoas[1].cadastrarPessoa(nome,cpf,idade);				
				
				
				
				
				break;
			case 2:
				
				
				std::cout<<"Insira o nome: ";
				std::cin>>nome;
				std::cout<<std::endl;
				
				idade = buscarporNome(listadepessoas, nome);
				if (idade == -1){
					std::cout<<"sujeito nao encontrado\n";
					
				}else{
					std::cout<<idade<<std::endl;
				}
				
				
				break;
		}
	}
	
	
}

int buscarporNome(PessoaFisica fulano[], char* nomeaserprocurado){
	int tam = 10;
	int validador;
	for (int i = 0; i < tam ; i++){
		validador = strcmp(nomeaserprocurado, fulano[i].nome);
		if (validador == 0){
			std::cout<<fulano[i].nome<<std::endl<<fulano[i].cpf<<std::endl;
			return(fulano[i].idade);
		}
	}
	return(-1);
	
	
	
	
	
}
