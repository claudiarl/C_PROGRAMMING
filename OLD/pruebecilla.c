#include <stdio.h>
#define LARGO 1000


int main(){

	int grupoCeros [] = {4,2,1}; 
    int derechas [LARGO];
    
    printf("Ceros derecha");
	for(int n = 0; n<3;n++){
		int numeroActual = grupoCeros[n];
		int derechita[numeroActual-1];
		
		for(int i=0;i<(grupoCeros[n]-1);i++){
			derechita[i] = --numeroActual;
		}
		for (int k = 0; k < (grupoCeros[n]-1); k++) {
			printf("%d, ", derechita[k]);
		}
		printf("\n");
	}
    
     //Creo un array con todos los valores anteriores de huecos de las N cadenas
    int i, j;
    int k = 0;
    for (j = ultimaPosicionRellenaTodosHuecos; j < ultimaPosicionRellenaTodosHuecos + largoArrayLimpio; j++) {
      TodosCeros[j] = derechita[k++];
    }

    //printf("ultima posicion era %d\n",ultimaPosicionRellenaTodosHuecos);
    ultimaPosicionRellenaTodosHuecos += largoArrayLimpio;
    
   /* printf("Ceros izquierda"); 
    	for(int n = 0; n < 3; n--){
		int numeroActual = grupoCeros[n];
		int izq[numeroActual-1];
		
		for(int i=0;i<(grupoCeros[n]-1);i++){

			izq[i] = --numeroActual;

		}
		for (int k = 0; k < (grupoCeros[n]-1); k++) {
			printf("%d, ", izq[k]);
		}
		printf("\n");
	}*/
    
	return 0;
}
