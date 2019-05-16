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
  //Longitud del poroso
  int L = atoi(argv[1]);
  
  //Porosidad del medio
  double r = atof(argv[2]);
  
  //Probabilidad de opacos en el poroso
  double p = 1 / (1 + r);
  
  //Índice de los bucles
  int n;
  
  //Números aleatorios generados
  double rnd;
  
  //Variable auxiliar que almacenará los valores del medio poroso
  char result;
  
  //Si la longitud del poroso provista es menor que 1, ajustar a 1
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

  
  //Fichero donde se guardará el poroso
  FILE * fout = fopen("poroso.dat", "w"); 
  
  //Generación y guardado del poroso
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
    fprintf(fout, "%d\t%d\n", n, result);
  }

  return 0;
}
