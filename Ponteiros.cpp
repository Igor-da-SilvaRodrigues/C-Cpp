#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
	int* vetor = new int[10];
	
	int var=2;
	
	
	int *abc[10];
	abc[2]=new int;
	*abc[2]=var;
	cout<<&abc[2]<<endl;
	cout<<abc[2]<<endl;
	cout<<*abc[2]<<endl;
	
	
	}
