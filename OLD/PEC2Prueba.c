#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0 
//0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0



int main(int argc, char ** argv) {
  //Índices de los bucles
  int n, m;
  int poroso [] = {0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0};
  
  int grupoCeros [20];
  for(int j=0;j<=20;j++){
	grupoCeros[j]=-1;
	printf("%d, ",grupoCeros[j]);
  }
  printf("\n");
  
  for(int j=0;j<20;j++){
	printf("%d, ",poroso[j]);
  }
  printf("\n");
 
 
 
  for(n = 0; n < 20; n++)
  {

	//printf("Bucle grande en n=%d\n",n);
	if(poroso[n]==0){
		//printf("Poroso es cero en n=%d\n",n);
		int numeroCeros = 0;
		for(m = n; m <=20; m++)
		{
			//printf("Bucle pequeño en m=%d\n",m);
			if(m==20 || poroso[m]==1) {
				//printf("He entrado!!\n");
				n = m;
				grupoCeros[m] = numeroCeros;
				break;
			} else if (poroso[m]==0)//TODO pensar si aqui me como estar fuera del array con el cero
			{
				numeroCeros++;
			}
		}
		//printf("Número de ceros = %d\n",numeroCeros+1);
    }

  }
  for(int j=0;j<=20;j++){
	if(grupoCeros[j]!=-1){
		printf("%d, ",grupoCeros[j]);
	}
  }
    printf("\n");
  
  return 0;
}
