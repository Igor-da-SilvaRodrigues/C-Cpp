#include <stdio.h>
#include <stdlib.h>

#include <iostream>



void mostrarnome(char *nome){
	
	std::cout<<nome;
	
}

int main(){
	char nome[100];
	std::cout<<"Insira um nome: "<<std::endl;
	std::cin>>nome;
	mostrarnome(nome);
	
	
}
