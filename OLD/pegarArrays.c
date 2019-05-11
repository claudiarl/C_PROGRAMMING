#include <stdio.h>
#define GRANDE 1000

int main() {

	int uno [] = {1,2,3};
	int dos [] = {4,5,6};
	int tres [] = {7,8,9};
	
	int pegados [GRANDE];
	
	for(int i = 0; i<GRANDE;i++){
		pegados[i] = uno[i];
	}
}

