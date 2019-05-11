#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char ** argv) {
	
  //Salida del programa si los argumentos no son los esperados
  if (argc < 2) 
  {
    printf("Uso del programa:\n %s <no.puntos>\n", argv[0]);
    exit(0);
  }

  int L = atoi(argv[1]); //Longitud del poroso
  double r = atof(argv[2]); //Porosidad del medio
  double p = 1 / (1 + r); //Probabilidad de opacos en el poroso
  int n,xp; //Índice de los bucles
  double rnd; //Números aleatorios generados
  char result; //Variable auxiliar que almacenará los valores del medio poroso
  
  /* Si la longitud del poroso provista 
   * es menor que 1, la ajusto a 1*/
  if (L < 1) 
  {
    L = 1;
  }
  
  //Inicialización del random
  int semilla = (int)time(NULL);
  srand(semilla);
  
   //Calentamiento
  for (n = 0; n < 2 * L; n++) 
  {
    rnd = (double) rand() / (RAND_MAX + 1.0);
  }


  
  //Generación del poroso
  for (n = 0; n < L; n++) 
  {
    rnd = (double) rand() / (RAND_MAX + 1.0);
    if (rnd <= p) 
    {
      result = 1;
    } 
    else 
    {
      result = 0;
    }
    printf("%d\t%d\n", n, result);
  }
  for (n = 0; n < L; n++) 
  {
  
	if(result=0)
	 {
		xp++; 
		printf("%d\n",xp);
	}
	else{}

}
  return 0;
}
