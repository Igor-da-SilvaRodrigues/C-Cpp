#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

int main(){
	char nome[100];
	cout<<"Digite um Nome: ";
	cin>>nome;
	cout<<endl;
	int tam = strlen(nome);
	char *p = &nome[tam];
	
	for (;p != &nome[0]; p--){
		cout<< *p;
	}
	cout<<*p;
	cout<<endl;
	system("pause");
	return 0;
}
