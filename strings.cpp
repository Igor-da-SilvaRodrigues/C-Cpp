#include <iostream>

int main(){
	
	char vetor[6] = "Viado";
	const char* vetor2 = vetor;
	
	// A linha 5 e 6 caracterizam uma redundância, 
	//No entanto "<texto>" Implica const char*, e só pode ser alocado a um vetor de char como inicializador (l. 5)...
	//portanto <<vetor[6] = "Viado";>> seria ilegal.
	
	int numeros[10] = {1,2,3,4,5,6,7,8,9,0};
	int *pnum = numeros;
	
	
	std::cout<<vetor2;
	
	
}
