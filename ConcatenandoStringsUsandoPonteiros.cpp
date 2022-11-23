#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<string.h>

using namespace std;

char* concatenar(char *a, char*b){
	int tam_a = strlen(a), tam_b = strlen(b);
	char *resultado = new char[tam_a+tam_b];
	int j=0;
	int i=0;
	for (;  *(a+i) != '\0';  i++ ){
		*(resultado+i) = *(a+i);
	}
	for (;  *(b+j) != '\0';  i++, j++  ){
		*(resultado+i) = *(b+j);
	}
	*(resultado+i) = '\0';
	
	return(resultado);
}


int main(){
	
	char *str1 = new char[100];
	char *str2 = new char[100];
	cout<<"Insira as strings a serem concatenadas:\n";
	cin>>str1;
	cout<<endl;
	cin>>str2;
	cout<<endl;
	cout<<endl;
	
	cout<<concatenar(str1,str2)<<endl;
	system("pause");
	return 0;
}

