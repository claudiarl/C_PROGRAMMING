#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char**argv){

int array[10]={0,1,2,3,4,5,6,7,8,9};
    for (int k = 1; k <= 10; k++) {   
      
      //Definición de la semilla para la generación de números aleatorios	
      int semilla = (int) time(NULL);
      srand(semilla);
      //Calentamiento
      for (int n = 0; n < 2 * 10; n++) {
        rand();
      }
      //Aleatorización del índice del array donde hay un cero
      int randomIndice = rand() % 10;
      printf("randomIndice es %d\n", randomIndice);
for(int i=0; i<randomIndice;i++){
	array[i]=array[i];
}
for(int i=randomIndice; i<10; i++){
	array[i]=array[i+1];
} 

for(int i=0; i<10-k; i++){
	printf("%d, ", array[i]);
}
printf("\n");
sleep(1); 
}
}
